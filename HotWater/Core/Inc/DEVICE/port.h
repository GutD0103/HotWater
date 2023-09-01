/*
 * port.h
 *
 *  Created on: Aug 5, 2023
 *      Author: ntdat
 */

#ifndef INC_DEVICE_PORT_H_
#define INC_DEVICE_PORT_H_

#define RELAY0_ON   			HAL_GPIO_WritePin(RELAY0_GPIO_Port, RELAY0_Pin, DEVICE_OPEN)
#define RELAY0_OFF  			HAL_GPIO_WritePin(RELAY0_GPIO_Port, RELAY0_Pin, GPIO_PIN_SET)
#define RELAY0_STATE 			HAL_GPIO_ReadPin(RELAY0_GPIO_Port, RELAY0_Pin)

#define RELAY1_ON   			HAL_GPIO_WritePin(RELAY1_GPIO_Port, RELAY1_Pin, GPIO_PIN_RESET)
#define RELAY1_OFF  			HAL_GPIO_WritePin(RELAY1_GPIO_Port, RELAY1_Pin, GPIO_PIN_SET)
#define RELAY1_STATE 			HAL_GPIO_ReadPin(RELAY1_GPIO_Port, RELAY1_Pin)

#define SOLENOID_OUT0_OPEN   	HAL_GPIO_WritePin(SOLENOID_OUT0_GPIO_Port, SOLENOID_OUT0_Pin, GPIO_PIN_SET)
#define SOLENOID_OUT0_CLOSE    	HAL_GPIO_WritePin(SOLENOID_OUT0_GPIO_Port, SOLENOID_OUT0_Pin, GPIO_PIN_RESET)
#define SOLENOID_OUT0_STATE 	HAL_GPIO_ReadPin(SOLENOID_OUT0_GPIO_Port, SOLENOID_OUT0_Pin)

#define SOLENOID_OUT1_OPEN   	HAL_GPIO_WritePin(SOLENOID_OUT1_GPIO_Port, SOLENOID_OUT1_Pin, GPIO_PIN_SET)
#define SOLENOID_OUT1_CLOSE    	HAL_GPIO_WritePin(SOLENOID_OUT1_GPIO_Port, SOLENOID_OUT1_Pin, GPIO_PIN_RESET)
#define SOLENOID_OUT1_STATE 	HAL_GPIO_ReadPin(SOLENOID_OUT1_GPIO_Port, SOLENOID_OUT1_Pin)

#define SOLENOID_IN0_OPEN   	HAL_GPIO_WritePin(SOLENOID_IN0_GPIO_Port, SOLENOID_IN0_Pin, GPIO_PIN_SET)
#define SOLENOID_IN0_CLOSE    	HAL_GPIO_WritePin(SOLENOID_IN0_GPIO_Port, SOLENOID_IN0_Pin, GPIO_PIN_RESET)
#define SOLENOID_IN0_STATE 		HAL_GPIO_ReadPin(SOLENOID_IN0_GPIO_Port, SOLENOID_IN0_Pin)

#define SOLENOID_IN1_OPEN   	HAL_GPIO_WritePin(SOLENOID_IN1_GPIO_Port, SOLENOID_IN1_Pin, GPIO_PIN_SET)
#define SOLENOID_IN1_CLOSE    	HAL_GPIO_WritePin(SOLENOID_IN1_GPIO_Port, SOLENOID_IN1_Pin, GPIO_PIN_RESET)
#define SOLENOID_IN1_STATE 		HAL_GPIO_ReadPin(SOLENOID_IN1_GPIO_Port, SOLENOID_IN1_Pin)

#define WATER0_LEVEL0_STATE		HAL_GPIO_ReadPin(WATER0_LEVEL0_GPIO_Port, WATER0_LEVEL0_Pin)
#define WATER0_LEVEL1_STATE		HAL_GPIO_ReadPin(WATER0_LEVEL1_GPIO_Port, WATER0_LEVEL1_Pin)

#define WATER1_LEVEL0_STATE		HAL_GPIO_ReadPin(WATER1_LEVEL0_GPIO_Port, WATER1_LEVEL0_Pin)
#define WATER1_LEVEL1_STATE		HAL_GPIO_ReadPin(WATER1_LEVEL1_GPIO_Port, WATER1_LEVEL1_Pin)

#define FLOW0_STATE				HAL_GPIO_ReadPin(FLOW0_GPIO_Port, FLOW0_Pin)

#define FLOW1_STATE				HAL_GPIO_ReadPin(FLOW1_GPIO_Port, FLOW1_Pin)

#define WT_EMPTY_ON(id)				do { 																	\
  									if ((id) == 0) { 														\
  										HAL_GPIO_WritePin(WT0_EMPTY_GPIO_Port, WT0_EMPTY_Pin, DEVICE_OPEN); \
  									} else if ((id) == 1) { 												\
  										HAL_GPIO_WritePin(WT1_EMPTY_GPIO_Port, WT1_EMPTY_Pin, DEVICE_OPEN); \
  									} 																		\
  								} while (0)

#define WT_EMPTY_OFF(id)			do { 																	\
  									if ((id) == 0) { 														\
  										HAL_GPIO_WritePin(WT0_EMPTY_GPIO_Port, WT0_EMPTY_Pin, DEVICE_CLOSE);\
  									} else if ((id) == 1) { 												\
  										HAL_GPIO_WritePin(WT1_EMPTY_GPIO_Port, WT1_EMPTY_Pin, DEVICE_CLOSE);\
  									} 																		\
  								} while (0)


#define BOILING_ON(id)			do { \
									if ((id) == 0) { \
										HAL_GPIO_WritePin(BOILING0_GPIO_Port, BOILING0_Pin, DEVICE_OPEN); \
									} else if ((id) == 1) { \
										HAL_GPIO_WritePin(BOILING1_GPIO_Port, BOILING1_Pin, DEVICE_OPEN); \
									} \
								} while (0)



#define BOILING_OFF(id)			do { \
									if ((id) == 0) { \
										HAL_GPIO_WritePin(BOILING0_GPIO_Port, BOILING0_Pin, DEVICE_CLOSE); \
									} else if ((id) == 1) { \
										HAL_GPIO_WritePin(BOILING1_GPIO_Port, BOILING1_Pin, DEVICE_CLOSE); \
									} \
								} while (0)


#endif /* INC_DEVICE_PORT_H_ */
