/*
 * RCC.c
 *
 *  Created on: Jul 23, 2021
 *      Author: ken chow
 */

#include "RCC.h"

void rccResetUnresetDevice(_IO_ uint32_t *io, int bitnum){
	*io &= ~(1 << bitnum);
	*io |= 1 << bitnum;				//Reset
	*io &= ~(1 << bitnum);			//Unreset
}

void rccEnableClock(_IO_ uint32_t *io, int bitnum){
	*io &= ~(1 << bitnum);			//Clear
	*io |= 1 << bitnum;				//Enable

}

void rccResetAndUnresetGpio(RccGpio rccGpio){
	rccResetUnresetDevice(ahb1ResetReg, rccGpio);	//Reset and Unreset
	rccEnableClock(ahb1_EnClkReg, rccGpio);			//Enable Clock
}

void rccResetAndUnresetUsart(RccUsart rccUsart){
	if(rccUsart == Rcc_USART2){
		rccResetUnresetDevice(apb1ResetReg, rccUsart);	//Reset and Unreset
		rccEnableClock(apb1_EnClkReg, rccUsart);		//Enable Clock
	}
	else
	{
		rccResetUnresetDevice(apb2ResetReg, rccUsart);	//Reset and Unreset
		rccEnableClock(apb2_EnClkReg, rccUsart);		//Enable Clock
	}
}

void rccResetAndUnresetI2C(RccI2C rccI2C){
	rccResetUnresetDevice(apb1ResetReg, rccI2C);
	rccEnableClock(apb1_EnClkReg, rccI2C);
}
