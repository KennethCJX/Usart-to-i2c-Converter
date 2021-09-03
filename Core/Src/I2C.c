/*
 * I2C.c
 *
 *  Created on: Jul 30, 2021
 *      Author: ken chow
 */

#include "I2C.h"

uint32_t getI2CFreq(I2CReg *i2c){
	HAL_RCC_GetPCLK1Freq();
}

void I2C_configure(I2CReg *i2c, I2C_Control_config configuration){
	i2c->CR1 &= ~(configuration & I2C_CR1_MASK);
	i2c->CR1 |= (configuration & I2C_CR1_MASK);
	i2c->CR2 &= ~(configuration >> 16);
	i2c->CR2 |= (configuration >> 16);
}

void I2C_SoftwareReset(I2CReg *i2c){
	i2c->CR1 &= ~I2C_UNDER_RESET;
	i2c->CR1 |= I2C_UNDER_RESET	;
	i2c->CR1 &= ~I2C_UNDER_RESET;
}

void I2C_set_CCR_and_TRISE(I2CReg *i2c, uint32_t frequency){
	long double Thigh;
    uint32_t apb1_freq = getI2CFreq(i2c);
    long double apb1_period = 1 / (long double)apb1_freq;
    long double i2c_period = 1 / (long double)frequency;
	i2c->TRISE = 0x0;
	i2c->CCR &= ~0xFFF;
	if(i2c->CCR & (1 << 15)){		//Fast Mode
		i2c->TRISE |= (uint32_t)((3E-7 / apb1_period) + 1);
		if(i2c->CCR & (1 << 14)){
			Thigh = i2c_period * (9 / 25);
			i2c->CCR |= (uint32_t)((Thigh / 9)/ apb1_period);
		}else {
			Thigh = i2c_period / 3;
			i2c->CCR |= (uint32_t)(Thigh / apb1_period);
		}
	}else {							//Standard Mode
		i2c->TRISE |= (uint32_t)((1E-6 / apb1_period) + 1);
		Thigh = i2c_period / 2;
		i2c->CCR |= (uint32_t)(Thigh / apb1_period);
	}
}

void I2C_Start(I2CReg *i2c){
	i2c->CR1 &= ~(POS_NEXT_BYTE_RECEIVED_IN_SHIFT_REG);
	i2c->CR1 |= ACKNOWLEDGE_RETURNED;
	i2c->CR1 |= I2C_GENERATED_START;
	while(!(i2c->SR1 & I2C_START_GENERATED));
}


I2C_Status _I2C_Write(I2CReg *i2c, int SlaveAddr, char *data, int length, int stopBit){
	uint32_t temp;

	//Initiate start sequence
	I2C_Start(i2c);

	//send the slave address
	i2c->DR = (uint32_t)SlaveAddr << 1;
	while(!(i2c->SR1 & I2C_ADDRESS_MATCHED));
	temp = 0x0;
	temp = i2c->SR1;
	temp = i2c->SR2;
	while(!(i2c->SR1 & I2C_TXE));

	for(int i = 0; i < length; i++){
		i2c->DR = (uint32_t)data[i];
		while(!(i2c->SR1 & I2C_TXE));
		while(!(i2c->SR1 & I2C_DATA_TRANSFERRED));
		if(i2c->SR1 & I2C_ACK_FAIL)
			return I2C_ERROR;
		//temp = 0x0;
		//temp = i2c->SR1;
		temp = i2c->SR2;
	}
	if(stopBit){
		i2c->CR1 |= I2C_GENERATED_STOP;
		temp = i2c->SR1;
		temp = i2c->SR2;
	}
	return I2C_SUCCESS;
}

I2C_Status I2C_Write(I2CReg *i2c, int SlaveAddr, char *data, int length){
	return _I2C_Write(i2c, SlaveAddr, data, length, 1);
}

I2C_Status I2C_Read(I2CReg *i2c, int SlaveAddr, char *dataToWrite, int Wrlength, char *rdData, int Rdlength){
	uint32_t temp;

	I2C_Status result = _I2C_Write(i2c, SlaveAddr, dataToWrite, Wrlength, 0);
	if(result != I2C_SUCCESS)
		return result;

	//repeated start
	I2C_Start(i2c);

	i2c->DR = (uint32_t)(SlaveAddr << 1) + 1;
	while(!(i2c->SR1 & I2C_ADDRESS_MATCHED));
	//temp = 0x0;
	//temp = i2c->SR1;
	//temp = i2c->SR2;
	i2c->SR2 = i2c->SR2;
	for(int i=0; i< (Rdlength - 1); i++){
		while(!(i2c->SR1 & I2C_RXNE));
		rdData[i] = i2c->DR;
		i2c->CR1 |= ACKNOWLEDGE_RETURNED;
	}
	i2c->CR1 |= I2C_GENERATED_STOP;					//testing
	while(!(i2c->SR1 & I2C_RXNE));
	rdData[Rdlength - 1] = i2c->DR;
	i2c->CR1 &= ~(ACKNOWLEDGE_RETURNED);
	//i2c->CR1 |= I2C_GENERATED_STOP;
	return I2C_SUCCESS;
}

