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
#define FLOW0_Pin GPIO_PIN_2
#define FLOW0_GPIO_Port GPIOA
#define FLOW1_Pin GPIO_PIN_4
#define FLOW1_GPIO_Port GPIOC
#define SOLENOID_IN1_Pin GPIO_PIN_11
#define SOLENOID_IN1_GPIO_Port GPIOB
#define BOILING0_Pin GPIO_PIN_13
#define BOILING0_GPIO_Port GPIOB
#define BOILING1_Pin GPIO_PIN_15
#define BOILING1_GPIO_Port GPIOB
#define RELAY1_Pin GPIO_PIN_8
#define RELAY1_GPIO_Port GPIOA
#define WT0_EMPTY_Pin GPIO_PIN_9
#define WT0_EMPTY_GPIO_Port GPIOA
#define RELAY0_Pin GPIO_PIN_6
#define RELAY0_GPIO_Port GPIOC
#define WT1_EMPTY_Pin GPIO_PIN_7
#define WT1_EMPTY_GPIO_Port GPIOC
#define SOLENOID_OUT1_Pin GPIO_PIN_11
#define SOLENOID_OUT1_GPIO_Port GPIOA
#define SOLENOID_IN0_Pin GPIO_PIN_15
#define SOLENOID_IN0_GPIO_Port GPIOA
#define SOLENOID_OUT0_Pin GPIO_PIN_9
#define SOLENOID_OUT0_GPIO_Port GPIOC
#define WATER0_LEVEL0_Pin GPIO_PIN_3
#define WATER0_LEVEL0_GPIO_Port GPIOB
#define WATER0_LEVEL1_Pin GPIO_PIN_4
#define WATER0_LEVEL1_GPIO_Port GPIOB
#define WATER1_LEVEL0_Pin GPIO_PIN_5
#define WATER1_LEVEL0_GPIO_Port GPIOB
#define WATER1_LEVEL1_Pin GPIO_PIN_6
#define WATER1_LEVEL1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
