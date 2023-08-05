/*
 * adc.c
 *
 *  Created on: Aug 1, 2023
 *      Author: ntdat
 */

#include "HAL/adc.h"

ADC_HandleTypeDef hadc1 = {
		  .Instance = ADC1,
		  .Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2,
		  .Init.Resolution = ADC_RESOLUTION_12B,
		  .Init.DataAlign = ADC_DATAALIGN_RIGHT,
		  .Init.ScanConvMode = ADC_SCAN_ENABLE,
		  .Init.EOCSelection = ADC_EOC_SINGLE_CONV,
		  .Init.LowPowerAutoWait = DISABLE,
		  .Init.LowPowerAutoPowerOff = DISABLE,
		  .Init.ContinuousConvMode = ENABLE,
		  .Init.NbrOfConversion = 3,
		  .Init.ExternalTrigConv = ADC_SOFTWARE_START,
		  .Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE,
		  .Init.DMAContinuousRequests = DISABLE,
		  .Init.Overrun = ADC_OVR_DATA_PRESERVED,
		  .Init.SamplingTimeCommon1 = ADC_SAMPLETIME_1CYCLE_5,
		  .Init.SamplingTimeCommon2 = ADC_SAMPLETIME_1CYCLE_5,
		  .Init.OversamplingMode = DISABLE,
		  .Init.TriggerFrequencyMode = ADC_TRIGGER_FREQ_HIGH
};
DMA_HandleTypeDef hdma_adc1;

bool ADC_init()
{
	bool success = true;
	ADC_ChannelConfTypeDef sConfig = {0};

	if (HAL_ADC_Init(&hadc1) != HAL_OK)
	{
	  Error_Handler();
	}
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLINGTIME_COMMON_1;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
	  Error_Handler();
	}

	/** Configure Regular Channel
	*/
	sConfig.Channel = ADC_CHANNEL_1;
	sConfig.Rank = ADC_REGULAR_RANK_2;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
	  Error_Handler();
	}

	  /** Configure Regular Channel
	  */
	sConfig.Channel = ADC_CHANNEL_2;
	sConfig.Rank = ADC_REGULAR_RANK_3;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
	  Error_Handler();
	}

	  /** Configure Regular Channel
	  */
	sConfig.Channel = ADC_CHANNEL_3;
	sConfig.Rank = ADC_REGULAR_RANK_4;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
	  Error_Handler();
	}
	return success;
}

void ADC_Select_CH0 (void)
{
	ADC_ChannelConfTypeDef sConfig = {0};
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
	  Error_Handler();
	}
}
void ADC_Select_CH1 (void)
{
	ADC_ChannelConfTypeDef sConfig = {0};
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = ADC_REGULAR_RANK_2;
	sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
	  Error_Handler();
	}
}
void ADC_Select_CH2 (void)
{
	ADC_ChannelConfTypeDef sConfig = {0};
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = ADC_REGULAR_RANK_2;
	sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
	  Error_Handler();
	}
}

void ADC_Select_CH3 (void)
{
	ADC_ChannelConfTypeDef sConfig = {0};
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = ADC_REGULAR_RANK_2;
	sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
	  Error_Handler();
	}
}

uint32_t Read_ADC(int ch)
{
	uint32_t ADC_VAL;
	if(ch < 0 || ch > 2){
		return -1;
	}
	else if(ch == 0){
		ADC_Select_CH0();
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1, 1000);
		ADC_VAL = HAL_ADC_GetValue(&hadc1);
		HAL_ADC_Stop(&hadc1);
	}
	else if(ch == 1){
		ADC_Select_CH1();
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1, 1000);
		ADC_VAL = HAL_ADC_GetValue(&hadc1);
		HAL_ADC_Stop(&hadc1);
	}
	else if(ch == 2){
		ADC_Select_CH2();
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1, 1000);
		ADC_VAL = HAL_ADC_GetValue(&hadc1);
		HAL_ADC_Stop(&hadc1);
	}
	else if(ch == 3){
			ADC_Select_CH2();
			HAL_ADC_Start(&hadc1);
			HAL_ADC_PollForConversion(&hadc1, 1000);
			ADC_VAL = HAL_ADC_GetValue(&hadc1);
			HAL_ADC_Stop(&hadc1);
	}
	return ADC_VAL;
}
