/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RESET_USB_Pin GPIO_PIN_9
#define RESET_USB_GPIO_Port GPIOB
#define EQ_P_Pin GPIO_PIN_0
#define EQ_P_GPIO_Port GPIOB
#define EQ_P_EXTI_IRQn EXTI0_1_IRQn
#define SET_LCD_Pin GPIO_PIN_1
#define SET_LCD_GPIO_Port GPIOB
#define SET_LCD_EXTI_IRQn EXTI0_1_IRQn
#define EQ_M_Pin GPIO_PIN_2
#define EQ_M_GPIO_Port GPIOB
#define EQ_M_EXTI_IRQn EXTI2_3_IRQn
#define DP_SEL_Pin GPIO_PIN_15
#define DP_SEL_GPIO_Port GPIOA
#define WAKEUP_USB_Pin GPIO_PIN_8
#define WAKEUP_USB_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
