/*
 * gpio.c
 *
 *  Created on: Aug 3, 2023
 *      Author: ntdat
 */


#include "HAL/gpio.h"

bool GPIO_init(){
	bool succes = 1;
	  GPIO_InitTypeDef GPIO_InitStruct = {0};
	/* USER CODE BEGIN MX_GPIO_Init_1 */
	/* USER CODE END MX_GPIO_Init_1 */

	  /* GPIO Ports Clock Enable */
	  __HAL_RCC_GPIOA_CLK_ENABLE();
	  __HAL_RCC_GPIOB_CLK_ENABLE();
	  __HAL_RCC_GPIOC_CLK_ENABLE();
	  __HAL_RCC_GPIOD_CLK_ENABLE();

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(RELAY2_GPIO_Port, RELAY2_Pin, GPIO_PIN_RESET);

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(GPIOA, RELAY1_Pin|SOLENOID2_Pin, GPIO_PIN_RESET);

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(SOLENOID1_GPIO_Port, SOLENOID1_Pin, GPIO_PIN_RESET);

	  /*Configure GPIO pins : FLOW2_Pin FLOW1_Pin */
	  GPIO_InitStruct.Pin = FLOW2_Pin|FLOW1_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	  /*Configure GPIO pin : RELAY2_Pin */
	  GPIO_InitStruct.Pin = RELAY2_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(RELAY2_GPIO_Port, &GPIO_InitStruct);

	  /*Configure GPIO pins : RELAY1_Pin SOLENOID2_Pin */
	  GPIO_InitStruct.Pin = RELAY1_Pin|SOLENOID2_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	  /*Configure GPIO pin : SOLENOID1_Pin */
	  GPIO_InitStruct.Pin = SOLENOID1_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(SOLENOID1_GPIO_Port, &GPIO_InitStruct);

	  return succes;
}
