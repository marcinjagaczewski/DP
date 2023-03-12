/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins
*/

volatile buttons_t buttons;

void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
//  HAL_GPIO_WritePin(GPIOB, RESET_USB_Pin|WAKEUP_USB_Pin, GPIO_PIN_SET);

  HAL_GPIO_WritePin(GPIOB, WAKEUP_USB_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, RESET_USB_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, WAKEUP_USB_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOB, RESET_USB_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DP_SEL_GPIO_Port, DP_SEL_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PBPin PBPin */
  GPIO_InitStruct.Pin = RESET_USB_Pin|WAKEUP_USB_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = EQ_P_Pin|SET_LCD_Pin|EQ_M_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = DP_SEL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(DP_SEL_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_1_IRQn);

  HAL_NVIC_SetPriority(EXTI2_3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_3_IRQn);

}
//
void gpioToSwitchDP(bool dp)
{
  if(dp){
    HAL_GPIO_WritePin(DP_SEL_GPIO_Port, DP_SEL_Pin, GPIO_PIN_SET);
  }
  else{
    HAL_GPIO_WritePin(DP_SEL_GPIO_Port, DP_SEL_Pin, GPIO_PIN_SET);
  }

}

void buttonsInit()
{
  buttons.eqGainUp = false;
  buttons.dpSwitch = false;
  buttons.eqGainDown = false;
}

bool buttonsGetState(buttonsState_t state)
{
  switch(state)
  {
    case EQ_GAIN_UP:
      return buttons.eqGainUp;
      break;
    case EQ_GAIN_DOWN:
      return buttons.eqGainDown;
      break;
    case DP_SWITCH:
      return buttons.dpSwitch;
      break;
    default:
      return false;
  }
}

void buttonsResetState()
{
  buttons.eqGainUp = false;
  buttons.eqGainDown = false;
  buttons.dpSwitch = false;
}

/* USER CODE BEGIN 2 */
void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
		case EQ_P_Pin:
      buttons.eqGainUp = true;
			break;
		case SET_LCD_Pin:
      buttons.dpSwitch = true;
			break;
		case EQ_M_Pin:
      buttons.eqGainDown = true;
			break;
		default:
			break;
	}
}

/* USER CODE END 2 */
