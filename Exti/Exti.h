#ifndef EXTI_H
#define EXTI_H

#include "Std_Types.h"


typedef struct {
	uint32 IMR;
	uint32 EMR;
	uint32 RTSR;
	uint32 FTSR;
	uint32 SWIER;
	uint32 PR;
} ExtiType;

#define EXTI_BASE (0x40013C00)
#define EXTI ((ExtiType *)EXTI_BASE)

#define SYSCFG_EXTICR1 (*(uint32*) (EXTI_BASE + 0x08))
#define SYSCFG_EXTICR2 (*(uint32*) (EXTI_BASE + 0x0C))
#define SYSCFG_EXTICR3 (*(uint32*) (EXTI_BASE + 0x10))
#define SYSCFG_EXTICR4 (*(uint32*) (EXTI_BASE + 0x14))

#define FALL_TRIG 0
#define RISE_TRIG 1
uint32 * Reg[4]={&SYSCFG_EXTICR1, &SYSCFG_EXTICR2, &SYSCFG_EXTICR3, &SYSCFG_EXTICR4}; 
void Init_Exti(uint8 PortName, uint8 PinNum, uint8 EdgeType);

void Exti_EnableInterrupt(void);

void Exti_DisableInterrupt(void);

#endif /* EXTI_H */
