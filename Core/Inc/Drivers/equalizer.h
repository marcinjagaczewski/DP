#pragma once

#define EQ_ADDRESS 0x0F
#define EQ_GENERAL_REG		0X0A
#define EQ_FOR1_2_LINES_REG	0x10
#define EQ_FOR3_4_LINES_REG	0x11
#define EQ_STATUS_REG		0x12
#define EQ_CONTROL_REG		0x13

#define MAX_EQ_GAIN 0x0F
#define MIN_EQ_GAIN 0x00

typedef enum eqI2CStatus_e
{
	EQ_OK = 0,
	EQ_ERROR,
	EQ_ERROR_GAIN_CANNOT_SET,
	EQ_StatusMax,
}eqI2CStatus_t;

typedef enum eqGainSet_e
{
	EQ_UP = 0,
	EQ_DOWN,
	EQ_SET_MAX,
}eqGainSet_t;


eqI2CStatus_t eqInit();
eqI2CStatus_t eqGainSet(eqGainSet_t set);
