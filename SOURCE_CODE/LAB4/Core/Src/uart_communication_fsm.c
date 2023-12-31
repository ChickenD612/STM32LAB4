/*
 * uart_communication_fsm.c
 *
 *  Created on: Nov 19, 2023
 *      Author: ASUS
 */

#include "uart_communication_fsm.h"
#include"main.h"
uint32_t ADC_value = 0;
char str[50];

void uart_communication_fsm(){
	switch (status_communicate){
		case WAIT_CMD_RST:
			if (command_flag){
				command_flag = 0;
				if (is_RST()){
					status_communicate = SEND_ADC;
					setTimer1(10);
					ADC_value = HAL_ADC_GetValue(&hadc1);
				}
			}
			break;

		case SEND_ADC:
			if (timer1_flag == 1){
				setTimer1(300);
				HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "!ADC=%.4d#", ADC_value), 1000);
                HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin);
			}
			if (command_flag){
				command_flag = 0;
				if (is_OK()){
					status_communicate = WAIT_CMD_RST;
				}
			}
			break;

		default:
			break;
	}
}

int is_RST(){
	if (length_of_command == 3 && command_data[0] == 0x52 && command_data[1] == 0x53 && command_data[2] == 0x54){
		return 1;
	}

	return 0;
}

int is_OK(){
	if (length_of_command == 2 && command_data[0] == 0x4f && command_data[1] == 0x4b){
			return 1;
		}

		return 0;
}
