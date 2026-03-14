#include <stdint.h>

// STM32F405 Register Base Addresses
#define RCC_BASE	0x40023800
#define GPIOA_BASE	0x40020000
#define GPIOB_BASE	0x40020400
#define GPIOC_BASE	0x40020800
#define USART3_BASE	0x40004800
#define	ADC1_BASE	0x40012000
#define TIM2_BASE	0x40000000
#define DMA2_BASE	0x40026400


//RCC Registers
#define RCC_CR			(*((volatile uint32_t *)(RCC_BASE + 0x00)))
#define RCC_PLLCFGR		(*((volatile uint32_t *)(RCC_BASE + 0x04)))
#define RCC_CFGR		(*((volatile uint32_t *)(RCC_BASE + 0x08)))
#define RCC_AHB1ENR		(*((volatile uint32_t *)(RCC_BASE + 0x30)))
#define RCC_APB1ENR		(*((volatile uint32_t *)(RCC_BASE + 0x40)))
#define RCC_APB2ENR		(*((volatile uint32_t *)(RCC_BASE + 0x44)))

//TIM2 Registers
#define TIM2_CR1		(*((volatile uint32_t *)(TIM2_BASE + 0x00)))
#define TIM2_CR2		(*((volatile uint32_t *)(TIM2_BASE + 0x04)))
#define TIM2_PSC		(*((volatile uint32_t *)(TIM2_BASE + 0x28)))
#define TIM2_ARR		(*((volatile uint32_t *)(TIM2_BASE + 0x2C)))
#define TIM2_EGR		(*((volatile uint32_t *)(TIM2_BASE + 0x14)))


//DMA2 Registers
#define DMA_S0CR		(*((volatile uint32_t *)(DMA2_BASE + 0x10)))
#define DMA_S0NDTR		(*((volatile uint32_t *)(DMA2_BASE + 0x14)))
#define DMA_S0PAR		(*((volatile uint32_t *)(DMA2_BASE + 0x18)))
#define DMA_S0M0AR		(*((volatile uint32_t *)(DMA2_BASE + 0x1C)))
#define DMA_S0M1AR		(*((volatile uint32_t *)(DMA2_BASE + 0x20)))
#define DMA2_LISR  		(*((volatile uint32_t *)(DMA2_BASE + 0x00)))
#define DMA2_LIFCR  	(*((volatile uint32_t *)(DMA2_BASE + 0x08)))


//GPIOA Registers
#define GPIOA_MODER 	(*((volatile uint32_t *)(GPIOA_BASE + 0x00)))

//GPIOB Registers
#define GPIOB_MODER 	(*((volatile uint32_t *)(GPIOB_BASE + 0x00)))
#define	GPIOB_AFRH		(*((volatile uint32_t *)(GPIOB_BASE + 0x24)))

//GPIOC Registers
#define GPIOC_MODER 	(*((volatile uint32_t *)(GPIOC_BASE + 0x00)))
#define GPIOC_ODR		(*((volatile uint32_t *)(GPIOC_BASE + 0x14)))


//USART3 Registers (keeping for later)
#define USART3_SR		(*((volatile uint32_t *)(USART3_BASE + 0x00)))
#define USART3_DR		(*((volatile uint32_t *)(USART3_BASE + 0x04)))
#define USART3_BRR		(*((volatile uint32_t *)(USART3_BASE + 0x08)))
#define USART3_CR1		(*((volatile uint32_t *)(USART3_BASE + 0x0C)))


//ADC1 Registers
#define ADC1_SR			(*((volatile uint32_t *)(ADC1_BASE + 0x00)))
#define ADC1_CR1		(*((volatile uint32_t *)(ADC1_BASE + 0x04)))
#define ADC1_CR2		(*((volatile uint32_t *)(ADC1_BASE + 0x08)))
#define ADC1_SMPR2		(*((volatile uint32_t *)(ADC1_BASE + 0x14)))
#define ADC1_SQR3		(*((volatile uint32_t *)(ADC1_BASE + 0x34)))
#define ADC1_DR			(*((volatile uint32_t *)(ADC1_BASE + 0x4C)))

//ADC Common Register
#define	ADC_CCR			(*((volatile uint32_t *)(0x40012300 + 0x04)))

//FPU Enable
#define FPU_CPACR		(*((volatile uint32_t *)0xE000ED88))	//ARM architecture-defined (Every Cortex-M4 chip in the world has this FPU control register address)

//Double buffers - DMA writes here, CPU reads here
#define BUFFER_SIZE 240

volatile uint16_t	buffer_A[BUFFER_SIZE];
volatile uint16_t	buffer_B[BUFFER_SIZE];
volatile uint8_t	buffer_ready = 255;		//255 = no buffer ready yet


//Utility
void delay(volatile uint32_t count){
	while(count--);
}

//ADC INIT
void adc_init(void) {

	//Enable GPIOA and ADC1 clocks
	RCC_AHB1ENR |= (1 << 0);	//GPIOA
	RCC_APB2ENR |= (1 << 8);

	//Set PA4 to analog mode (11 in MODER bits 8-9)
	GPIOA_MODER |= (3 << 8);

	//Set ADC pres-calar to /4
	ADC_CCR |= (1 << 16);

	//Set sample time for channel 4 to 480 cycles (slowest, most accurate)
	ADC1_SMPR2 |= (7 << 12);

	//Set channel 4 as first conversion in sequence
	ADC1_SQR3 = 4;

	//Enable ADC
	ADC1_CR2 |= (1 << 0);	//enable ADC1
	delay(10000);			//stabilize
	ADC1_CR2 |= (6 << 24);	//EXTSEL = 0110, TIM2 TRGO
	ADC1_CR2 |= (1 << 28); 	//EXTEN = 01, rising edge
	ADC1_CR2 |= (1 << 8);  // DMA enable

	//Wait for ADC to stabilize
	delay(10000);

}

//Timer Initialize
void timer_init(void) {

	//Enable Timer2 clock first
	RCC_APB1ENR |= (1 << 0);

	//Configure before starting
	TIM2_CR2 |= (1 << 5);	//MMS = 010, TRGO on update
	TIM2_PSC = 0;			//No prescalar, full 16 MHz
	TIM2_ARR = 332;			// 16 MHz / 333 = ~48.048 kHz
	TIM2_EGR |= (1 << 0);	//Load PSC and ARR immediately

	//Start the timer last
	TIM2_CR1 |= (1 << 0);	//CEN - counter enable
}


//Initialize DMA
void dma_init(void) {

	RCC_AHB1ENR |= (1 << 22);	//DMA2 clock enable
	DMA_S0CR &= ~ (1 << 0);
	while(DMA_S0CR & (1 << 0));	//wait until hardware confirms disabled

	// Clear CHSEL bits (channel 0)
	DMA_S0CR &= ~(0x7 << 25);

	// Set all configuration bits in S0CR
	DMA_S0CR |= (1 << 18);  // DBM - double buffer mode
	DMA_S0CR |= (1 << 13);  // MSIZE = 01, 16-bit memory size
	DMA_S0CR |= (1 << 11);  // PSIZE = 01, 16-bit peripheral size
	DMA_S0CR |= (1 << 10);  // MINC - memory increment enable
	DMA_S0CR |= (1 << 4);   // TCIE - transfer complete interrupt
	// DIR = 00 (peripheral to memory) - already 0 at reset
	// PINC = 0 (peripheral address fixed) - already 0 at reset

	DMA_S0PAR  = (uint32_t)(ADC1_BASE + 0x4C);  // ADC1_DR address
	DMA_S0M0AR = (uint32_t)buffer_A;             // buffer A
	DMA_S0M1AR = (uint32_t)buffer_B;             // buffer B
	DMA_S0NDTR = BUFFER_SIZE;                    // 240 transfers

	// Enable DMA2 Stream0 interrupt in NVIC
	// DMA2_Stream0 is IRQ 56
	*((volatile uint32_t *)0xE000E100 + (56/32)) |= (1 << (56 % 32));

	DMA_S0CR |= (1 << 0);  // EN - enable stream
}

void DMA2_Stream0_IRQHandler(void) {
	if (DMA2_LISR & (1 << 5)) {
		DMA2_LIFCR |= (1 << 5);
		if (DMA_S0CR & (1 << 19)) {
		    buffer_ready = 0;  // CT=1 means DMA switched to buffer B, so A is ready
		} else {
		    buffer_ready = 1;  // CT=0 means DMA switched to buffer A, so B is ready
		}
	}
}

int main(void) {

	//Enable FPU (floating point) - full access to CP10 and CP11
	FPU_CPACR |= (0xF << 20);

	adc_init();
	timer_init();
	dma_init();

	//Enable GPIOC, set PC1 as output (red LED)
	RCC_AHB1ENR |= (1 << 2);
	GPIOC_MODER &= ~(3 << 2);
	GPIOC_MODER |= (1 << 2);

	volatile uint16_t *active_buffer;

	for(;;) {

        // Wait for DMA to finish filling a buffer
        while(buffer_ready == 255);  // 255 = no buffer ready yet

        // Point to whichever buffer is ready
        if (buffer_ready == 0) {
            active_buffer = buffer_A;
        } else {
            active_buffer = buffer_B;
        }

        // Mark as processed
        buffer_ready = 255;

        // Toggle LED to show processing is happening
        GPIOC_ODR ^= (1 << 1);

	}
}
