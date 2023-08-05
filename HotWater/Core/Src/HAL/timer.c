/*
 * timer.c
 *
 *  Created on: Jul 24, 2023
 *      Author: ntdat
 */

#include "main.h"
#include "HAL/timer.h"
#define TIMER_FN_MAX_SIZE	10
#define MAX_TIMER	10
#define TICK 10


int timer_counter[MAX_TIMER] = {0};
int timer_flag[MAX_TIMER] = {0};

static TIMER_fn fn_table[TIMER_FN_MAX_SIZE];
static size_t fn_table_len = 0;
TIM_HandleTypeDef htim3 = {
		  .Instance = TIM3,
		  .Init ={
				  .Prescaler = 15999,
				  .CounterMode = TIM_COUNTERMODE_UP,
				  .Period = 9,
				  .ClockDivision = TIM_CLOCKDIVISION_DIV1,
				  .AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE,
		  }
};

bool TIM_init(){
	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
		TIM_MasterConfigTypeDef sMasterConfig = {0};

		if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
		{
			Error_Handler();
		}
		sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
		if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
		{
			Error_Handler();
		}
		sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
		sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
		if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
		{
			Error_Handler();
		}
		if (HAL_TIM_Base_Start_IT(&htim3) != HAL_OK)
		{
			Error_Handler();
		}
		return true;
}


void setTimer(int index, int duration){
	timer_counter[index] = duration;
	timer_flag[index] = 0;
};

int isTimer_timeout(int index){
	if(timer_flag[index]){
		timer_flag[index] = 0;
		return 1;
	}
	return 0;
}

void timerRun(){
	for(int i = 0; i < MAX_TIMER ; i++)
	{
		if(timer_counter[i] > 0){
			timer_counter[i] -- ;
			if(timer_counter [i] == 0){
				timer_flag[i] = 1;
			}
		}
	}
};

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim){
	if(htim->Instance == htim3.Instance){
//		for (int fn_idx = 0; fn_idx < fn_table_len; ++fn_idx) {
//			fn_table[fn_idx]();
//		}
		timerRun();
		SCH_Update();
	}
}
