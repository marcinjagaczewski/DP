#include <stdio.h>
#include <stdbool.h>
#include "Drivers/dp_switch.h"
#include<gpio.h>

void setDp(dpSwitch_t dp)
{
	switch (dp)
	{
	case DP1:
		gpioToSwitchDP(false);
		break;

	case DP2:
		gpioToSwitchDP(true);
		break;
	
	default:
		break;
	}
}
