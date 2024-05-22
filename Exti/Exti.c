#include "Exti.h"
#include "Bit_Operations.h"

void Init_Exti(uint8 PortName, uint8 PinNum, uint8 EdgeType){
    
    uint8 selection = PortName - 'A'; // A ---> 0x0 , B ---> 0x1 , etc.
    uint8 SYSCFG_INDEX = PinNum/4;
    uint8 SYSCFG_BIN = (PinNum%4)*4;

    *Reg[SYSCFG_INDEX] &= ~(0xf << (SYSCFG_BIN));
    *Reg[SYSCFG_INDEX] |= (selection << (SYSCFG_BIN));

    // enable falling edge on line 1
    if (EdgeType == 0){
        EXTI->FTSR |= (1 << 1);
        CLEAR_BIT(EXTI->RTSR, 1);
    }
    else{
        EXTI->RTSR |= (1 << 1);
        CLEAR_BIT(EXTI->FTSR, 1);
    }
}

void Exti_EnableInterrupt(uint8 IRQn){
    // enalbe line 1
	EXTI->IMR |= (1 << 1);
}

void Exti_DisableInterrupt(void){
    // enalbe line 1
	EXTI->IMR &=~ (1 << 1);
}


