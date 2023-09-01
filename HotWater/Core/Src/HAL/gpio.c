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
	  __HAL_RCC_GPIOC_CLK_ENABLE();
	  __HAL_RCC_GPIOB_CLK_ENABLE();
	  __HAL_RCC_GPIOD_CLK_ENABLE();

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(GPIOB, SOLENOID_IN1_Pin|BOILING0_Pin|BOILING1_Pin, GPIO_PIN_RESET);

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(GPIOA, RELAY1_Pin|WT0_EMPTY_Pin|SOLENOID_OUT1_Pin|SOLENOID_IN0_Pin, GPIO_PIN_RESET);

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(GPIOC, RELAY0_Pin|WT1_EMPTY_Pin|SOLENOID_OUT0_Pin, GPIO_PIN_RESET);

	  /*Configure GPIO pin : FLOW0_Pin */
	  GPIO_InitStruct.Pin = FLOW0_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	  HAL_GPIO_Init(FLOW0_GPIO_Port, &GPIO_InitStruct);

	  /*Configure GPIO pin : FLOW1_Pin */
	  GPIO_InitStruct.Pin = FLOW1_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	  HAL_GPIO_Init(FLOW1_GPIO_Port, &GPIO_InitStruct);

	  /*Configure GPIO pins : SOLENOID_IN1_Pin BOILING0_Pin BOILING1_Pin */
	  GPIO_InitStruct.Pin = SOLENOID_IN1_Pin|BOILING0_Pin|BOILING1_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	  /*Configure GPIO pins : RELAY1_Pin WT0_EMPTY_Pin SOLENOID_OUT1_Pin SOLENOID_IN0_Pin */
	  GPIO_InitStruct.Pin = RELAY1_Pin|WT0_EMPTY_Pin|SOLENOID_OUT1_Pin|SOLENOID_IN0_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	  /*Configure GPIO pins : RELAY0_Pin WT1_EMPTY_Pin SOLENOID_OUT0_Pin */
	  GPIO_InitStruct.Pin = RELAY0_Pin|WT1_EMPTY_Pin|SOLENOID_OUT0_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	  /*Configure GPIO pins : WATER0_LEVEL0_Pin WATER0_LEVEL1_Pin WATER1_LEVEL0_Pin WATER1_LEVEL1_Pin */
	  GPIO_InitStruct.Pin = WATER0_LEVEL0_Pin|WATER0_LEVEL1_Pin|WATER1_LEVEL0_Pin|WATER1_LEVEL1_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	return succes;
}
