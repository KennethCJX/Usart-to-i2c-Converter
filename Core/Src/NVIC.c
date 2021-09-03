/*
 * NVIC.c
 *
 *  Created on: Sep 3, 2021
 *      Author: ken chow
 */


#include "NVIC.h"

void nvicEnableIrq(int IrqNum){
	int n, bitPos;

	n= IrqNum/32;
	bitPos = IrqNum%32;

	nvic->ISER[n] = 1 << bitPos;
}

void nvicDisableIrq(int IrqNum){
	int n, bitPos;

	n= IrqNum/32;
	bitPos = IrqNum%32;

	nvic->ICER[n] = 1 << bitPos;
}

void nvicEnablePendingIrq(int IrqNum){
	int n, bitPos;

	n= IrqNum/32;
	bitPos = IrqNum%32;

	nvic->ISPR[n] = 1 << bitPos;
}

void nvicDisablePendingIrq(int IrqNum){
	int n, bitPos;

	n= IrqNum/32;
	bitPos = IrqNum%32;

	nvic->ICPR[n] = 1 << bitPos;
}
