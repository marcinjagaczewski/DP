#include <stdio.h>
#include "Drivers/equalizer.h"
#include "i2c.h"

uint8_t eqGain = 0;

eqI2CStatus_t eqInit()
{
	uint8_t data = 0;
	data |= (1 << 4) | (1 << 1); //EQ set by regisetrs and DP enable
	if(eqI2CWrite(EQ_ADDRESS, EQ_GENERAL_REG, &data) != HAL_OK){
		return EQ_ERROR;
	}
	data = 0; //AUX, DP line 1,2,3 and 4 are enable
	if(eqI2CWrite(EQ_ADDRESS, EQ_CONTROL_REG, &data) != HAL_OK){
		return EQ_ERROR;
	}
	data = 0;
	eqI2CWrite(EQ_ADDRESS, EQ_FOR1_2_LINES_REG, &data);
	eqI2CWrite(EQ_ADDRESS, EQ_FOR3_4_LINES_REG, &data);

	return EQ_OK;
}

eqI2CStatus_t eqGainSet(eqGainSet_t set)
{
	uint8_t eqGain1And2Lines = 0;
	uint8_t eqGain3And4Lines = 0;

	if(eqI2CRead(EQ_ADDRESS, EQ_FOR1_2_LINES_REG, &eqGain1And2Lines) != HAL_OK) {
		return EQ_ERROR;
	}
	if(eqI2CRead(EQ_ADDRESS, EQ_FOR3_4_LINES_REG, &eqGain3And4Lines) != HAL_OK) {
		return EQ_ERROR;
	}
	if(eqGain1And2Lines != eqGain3And4Lines)
	{
		if(eqGain1And2Lines < eqGain3And4Lines) {
			eqGain = eqGain1And2Lines;
		}
		else {
			eqGain = eqGain3And4Lines;
		}
	}
	if((set == EQ_UP) && (eqGain < MAX_EQ_GAIN)) {
		eqGain++;
	}
	else if((set == EQ_DOWN) && (eqGain > MIN_EQ_GAIN)) {
		eqGain--;
	}
	else {
		return EQ_ERROR_GAIN_CANNOT_SET;
	}

	if(eqI2CWrite(EQ_ADDRESS, EQ_FOR1_2_LINES_REG, &eqGain) != HAL_OK) {
		return EQ_ERROR;
	}
	if(eqI2CWrite(EQ_ADDRESS, EQ_FOR3_4_LINES_REG, &eqGain) != HAL_OK) {
		return EQ_ERROR;
	}
	return EQ_OK;
}
