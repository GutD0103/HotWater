/*
 * fsm.c
 *
 *  Created on: Jul 23, 2023
 *      Author: ntdat
 */
#include "fsm.h"

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
uint8_t MSG[35] = {'\0'};

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
					if(buffer[1] == 'E')
					{
						state2 = 0;
					}
					else if(buffer[1] == 'S')
					{
						if(buffer[2] == '0'){
							SOLENOID1_OPEN;
							sprintf(STRING1,"%s","SOLENOID 1 IS OPEN");
						}
						else if(buffer[2] == '1'){
							SOLENOID2_OPEN;
							sprintf(STRING1,"%s","SOLENOID 2 IS OPEN");
						}
						else if(buffer[2] == '2'){
							SOLENOID1_CLOSE;
							sprintf(STRING1,"%s","SOLENOID 1 IS CLOSE");
						}
						else if(buffer[2] == '3'){
							SOLENOID2_CLOSE;
							sprintf(STRING1,"%s","SOLENOID 2 IS CLOSE");
						}
						state2 = 1;
						setTimer(0, 100);
					}
					else if(buffer[1] == 'R')
					{
						if(buffer[2] == '0'){
							RELAY1_ON;
							sprintf(STRING2,"%s","RELAY 1 IS ON");
						}
						else if(buffer[2] == '1'){
							RELAY2_ON;
							sprintf(STRING2,"%s","RELAY 2 IS ON");
						}
						else if(buffer[2] == '2'){
							RELAY1_OFF;
							sprintf(STRING2,"%s","RELAY 1 IS OFF");
						}
						else if(buffer[2] == '3'){
							RELAY2_OFF;
							sprintf(STRING2,"%s","RELAY 2 IS OFF");
						}
						state2 = 2;
						setTimer(0, 100);
					}
					else if(buffer[1] == 'F')
					{
						if(buffer[2] == '0'){

						}
						else if(buffer[2] == '1'){

						}
						else if(buffer[2] == '2'){

						}
						else if(buffer[2] == '3'){

						}
						state2 = 3;
						setTimer(0, 100);
					}
					else if(buffer[1] == 'W')
					{
						if(buffer[2] == '0'){

						}
						else if(buffer[2] == '1'){

						}
						else if(buffer[2] == '2'){

						}
						else if(buffer[2] == '3'){

						}
						state2 = 4;
						setTimer(0, 100);
					}
					else if(buffer[1] == 'T')
					{
						if(buffer[2] == '0'){

						}
						else if(buffer[2] == '1'){

						}
						else if(buffer[2] == '2'){

						}
						else if(buffer[2] == '3'){

						}
						state2 = 5;
						setTimer(0, 100);
					}
					count = 0;
					state1 = INIT;
				}

				if(buffer[count] == '!')
				{
					buffer[0] = '!';
					count = 1;
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
				UART_send(UART_3, STRING1, sizeof(STRING1));
				setTimer(0, 100);
			}
			break;
		case 2:
			if(isTimer_timeout(0)){
				UART_send(UART_3, STRING2, sizeof(STRING2));
				setTimer(0, 100);
			}
			break;
		case 3:
			if(isTimer_timeout(0)){
				UART_send(UART_3, STRING3, sizeof(STRING3));
				setTimer(0, 100);
			}
			break;
		case 4:
			if(isTimer_timeout(0)){
				UART_send(UART_3, STRING4, sizeof(STRING4));
				setTimer(0, 100);
			}
			break;
		case 5:
			if(isTimer_timeout(0)){
				UART_send(UART_3, STRING5, sizeof(STRING5));
				setTimer(0, 100);
			}
			break;
		default:
			break;
	}
}

void fsm_run(){
	get_command();
	fsm_uart();
}
