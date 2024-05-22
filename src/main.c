#include "Bit_Operations.h"
#include "Std_Types.h"
#include "Utils.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Nvic.h"
#include "Exti.h"

typedef struct {
	uint32 IMR;
	uint32 EMR;
	uint32 RTSR;
	uint32 FTSR;
	uint32 SWIER;
	uint32 PR;
} ExtiType;

// GLOBAL VARIABLES
uint8 counter = 0;

int main() {
	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_SYSCFG);

	// INPUT PINS - 2 Buttons
	Gpio_ConfigPin(GPIO_A, 9, GPIO_INPUT, GPIO_PULL_UP);
	Gpio_ConfigPin(GPIO_B, 4, GPIO_INPUT, GPIO_PULL_UP);

	// OUTPUT PINS - 7 seg pins
	Gpio_ConfigPin(GPIO_A, 0, GPIO_OUTPUT, GPIO_PUSH_PULL);
	//.............................................


	// enable line 1 on nvic
	Nvic_EnableInterrupt(7);

	Init_Exti(GPIO_A, 9, RISE_TRIG);
	Exti_EnableInterrupt();

	Init_Exti(GPIO_B, 4, RISE_TRIG);
	Exti_EnableInterrupt();

	while (1) {
		// Code For 7-Segment using "Counter Variable i declared globally"
	}

	return 0;
}

void EXTI4_IRQHandler(void) {
	counter++;
	//clear pending flag
	SET_BIT(EXTI->PR, 1);
}

void EXTI9_5_IRQHandler(void){
	counter--;
	//clear pending flag
	SET_BIT(EXTI->PR, 1);
}

