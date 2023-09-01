/*
 * fsm.c
 *
 *  Created on: Jul 23, 2023
 *      Author: ntdat
 */
#include "fsm.h"
#include "APP/water_out.h"

static int state1 = INIT;
int state2 = 0;
int count;
int flag = 0;
int id;
uint8_t buffer[12] = {0};


uint8_t VALUE1 = 0;
uint8_t STRING1[50];
uint8_t STRING2[50];
uint8_t STRING3[50];
uint8_t STRING4[50];
uint8_t STRING5[50];
uint8_t STRING6[50];

void get_command()
{
	if(flag_uart[UART_3] >= 1)
	{
		flag_uart[UART_3] --;
		switch (state1)
		{
			case INIT:
				if(UART_receive_data(UART_3) == '!')
				{
					buffer[0] = '!';
					count = 1;
					state1 = GET;
					setTimer(2, 500);
				}

				break;
			case GET:
				if(count >= 12){
					count = 0;
					state1 = INIT;
				}
				buffer[count] = UART_receive_data(UART_3);

				if(buffer[count] == '#')
				{
					UART_send(UART_3, buffer, count);
					UART_send(UART_3, "#\n", sizeof("#\n"));
					if(buffer[1] == 'E')
					{
						state2 = 0;
					}
					else if(buffer[1] == 'S')
					{
						if(buffer[2] == '0'){
							waterout[0].set_solenoid_out(SET);
							sprintf(STRING1,"%s %d %s","SOLENOID OUT 0",waterout[0].get_solenoid_out()," \n");
						}
						else if(buffer[2] == '1'){
							waterout[1].set_solenoid_out(SET);
							sprintf(STRING1,"%s %d %s","SOLENOID OUT 1",waterout[1].get_solenoid_out()," \n");
						}
						else if(buffer[2] == '2'){
							waterout[0].set_solenoid_out(RESET);
							sprintf(STRING1,"%s","SOLENOID OUT 0  OFF\n");
						}
						else if(buffer[2] == '3'){
							waterout[1].set_solenoid_out(RESET);
							sprintf(STRING1,"%s","SOLENOID OUT 1 OFF\n");
						}




						if(buffer[2] == '4'){
							waterout[0].set_solenoid_in(SET);
							sprintf(STRING1,"%s","SOLENOID IN 0 ON\n");
						}
						else if(buffer[2] == '5'){
							waterout[1].set_solenoid_in(SET);
							sprintf(STRING1,"%s","SOLENOID IN 1 ON\n");
						}
						else if(buffer[2] == '6'){
							waterout[0].set_solenoid_in(RESET);
							sprintf(STRING1,"%s","SOLENOID IN 0 OFF\n");
						}
						else if(buffer[2] == '7'){
							waterout[1].set_solenoid_in(RESET);
							sprintf(STRING1,"%s","SOLENOID IN 1 OFF\n");
						}





						if(buffer[2] == '8'){
							BOILING_ON(0);
							sprintf(STRING1,"%s","BOLING ON 0\n");
						}
						else if(buffer[2] == '9'){
							BOILING_ON(1);
							sprintf(STRING1,"%s","BOLING ON 1\n");
						}
						else if(buffer[2] == 'A'){
							BOILING_OFF(0);
							sprintf(STRING1,"%s","BOLING OFF 0\n");
						}
						else if(buffer[2] == 'B'){
							BOILING_OFF(1);
							sprintf(STRING1,"%s","BOLING OFF 1\n");
						}


						if(buffer[2] == 'C'){
							WT_EMPTY_ON(0);
							sprintf(STRING1,"%s","WT EMPTY 0\n");
						}
						else if(buffer[2] == 'D'){
							WT_EMPTY_ON(1);
							sprintf(STRING1,"%s","WT EMPTY 1\n");
						}
						else if(buffer[2] == 'E'){
							WT_EMPTY_OFF(0);
							sprintf(STRING1,"%s","WT FULL 0\n");
						}
						else if(buffer[2] == 'F'){
							WT_EMPTY_OFF(1);
							sprintf(STRING1,"%s","WT FULL 1\n");
						}
						state2 = 1;
						setTimer(0, 100);
					}
					else if(buffer[1] == 'R')
					{
						if(buffer[2] == '0'){
							waterout[0].set_relay(RESET);
							sprintf(STRING2,"%s","RELAY 0 ON\n");
						}
						else if(buffer[2] == '1'){
							waterout[1].set_relay(RESET);
							sprintf(STRING2,"%s","RELAY 1 ON\n");
						}
						else if(buffer[2] == '2'){
							waterout[0].set_relay(SET);
							sprintf(STRING2,"%s","RELAY 0 OFF\n");
						}
						else if(buffer[2] == '3'){
							waterout[1].set_relay(SET);
							sprintf(STRING2,"%s","RELAY 1 OFF\n");
						}
						state2 = 2;
						setTimer(0, 100);
					}
					else if(buffer[1] == 'T') // NHIET DO
					{
						if(buffer[2] == '0'){
							sprintf(STRING3,"%s %d %s","TEMP 0: ", (int)waterout[0].temp()," \n");
						}
						else if(buffer[2] == '1'){
							sprintf(STRING3,"%s %d %s","TEMP 1: ", (int)waterout[1].temp()," \n");
						}
						else if(buffer[2] == 'S'){
							char *substring = buffer + 3;

							uint8_t number = 0;
							uint64_t multiplier = 1;

							for (int i = count - 1; i >= 0; i--) {
								if (substring[i] >= '0' && substring[i] <= '9') {
									number += (substring[i] - '0') * multiplier;
									multiplier *= 10;
								}
							}
							set_temp(number);
							sprintf(STRING3,"%s %d %s","SET TEMP: ", number ," \n");
						}
						state2 = 3;
						setTimer(0, 100);
					}
					else if(buffer[1] == 'F') // DONG CHAY
					{
							if(buffer[2] == '0'){
								sprintf(STRING4,"%s %d %s","PULSE FLOW 0: ", (int)fn_pulse(0)," \n");
							}
							else if(buffer[2] == '1'){
								sprintf(STRING4,"%s %d %s","PULSE FLOW 1: ", (int)fn_pulse(1)," \n");
							}
//						if(isTimer_timeout(2)){
//							setTimer(2, 500);
//						}
						state2 = 4;
						setTimer(0, 100);
					}
					else if(buffer[1] == 'W') // MUC NUOC
					{
						if(buffer[2] == '0'){
							sprintf(STRING5,"%s %d - %d %s","WATER LEVEL 0: ", waterout[0].water_level_0()
									,waterout[0].water_level_1()," \n");

						}
						else if(buffer[2] == '1'){
							sprintf(STRING5,"%s %d - %d %s","WATER LEVEL 1: ", waterout[1].water_level_0()
									,waterout[1].water_level_1()," \n");
						}
						state2 = 5;
						setTimer(0, 100);
					}
					else if (buffer[1] == 'L') {
						char *substring = buffer + 3;

						uint8_t number = 0;
						uint64_t multiplier = 1;

						for (int i = count - 1; i >= 0; i--) {
						    if (substring[i] >= '0' && substring[i] <= '9') {
						            number += (substring[i] - '0') * multiplier;
						            multiplier *= 10;
						    }
						}
						if(buffer[2] == '0'){
							SYSTEM_output_water(number, 0);
							sprintf(STRING6,"%s %d %s","SET LITER 0: ", number ," \n");
						}else if(buffer[2] == '1'){
							SYSTEM_output_water(number, 1);
							sprintf(STRING6,"%s %d %s","SET LITER 1: ", number ," \n");
						}
						state2 = 6;
						setTimer(0, 100);
					}
					count = 0;
					state1 = INIT;
				}

				if(buffer[count] == '!')
				{
					buffer[0] = '!';
					count = 1;
					setTimer(2, 500);
				}
				count++;
				break;
			default:
				UART_send(UART_3, "DEFAULT\n", sizeof("DEFAULT\n"));
				break;
		}
	}
}

void fsm_uart()
{
	switch (state2) {
		case 0:
			break;
		case 1:
			if(isTimer_timeout(0)){
				UART_send(UART_3, STRING1, sizeof(STRING2));
				setTimer(0, 500);
			}
			break;
		case 2:
			if(isTimer_timeout(0)){
				UART_send(UART_3, STRING2, sizeof(STRING2));
				setTimer(0, 500);
			}
			break;
		case 3:
			if(isTimer_timeout(0)){
				UART_send(UART_3, STRING3, sizeof(STRING3));
				setTimer(0, 500);
			}
			break;
		case 4:
			if(isTimer_timeout(0)){
				UART_send(UART_3, STRING4, sizeof(STRING4));
				setTimer(0, 500);
			}
			break;
		case 5:
			if(isTimer_timeout(0)){
				UART_send(UART_3, STRING5, sizeof(STRING5));
				setTimer(0, 500);
			}
			break;
		case 6:
			if(isTimer_timeout(0)){
				UART_send(UART_3, STRING6, sizeof(STRING6));
				setTimer(0, 500);
			}
			break;
		default:
			break;
	}
}

void fsm_run(){
	SCH_Dispatch_Tasks();
	get_command();
	fsm_uart();
}
