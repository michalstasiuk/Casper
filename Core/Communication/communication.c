/*
 * communication.c
 *
 *  Created on: Dec 21, 2021
 *      Author: stasiukm
 */

#include "communication.h"
#include <memory.h>

#define FRAME_INIT_CHAR 's'
#define FRAME_END_CHAR 'e'

typedef struct {
	uint8_t rx_data[UART_MAX_RX_LEGHT];
	bool is_new_frame_availible;
	uint8_t current_frame_size;
}interface;

interface uart_interface = {
		.is_new_frame_availible = FALSE,
		.current_frame_size = 0
};

char uart_rx_frame[UART_MAX_RX_LEGHT];
bool is_new_data_availible = FALSE;

void transmit_data(uint8_t* data, uint8_t size){
	HAL_UART_Transmit_DMA(&huart3, data, size);
}

bool is_new_frame_availible(void){
	return is_new_data_availible;
}

uint8_t get_new_frame(uint8_t* frame){
	if (is_new_frame_availible()){
		memcpy(frame, uart_interface.rx_data, uart_interface.current_frame_size);
		return uart_interface.current_frame_size;
	} else{
		return 0;
	}
}

void uart_irq_handler(uint8_t byte){
	switch (byte) {
	case FRAME_INIT_CHAR:
		uart_interface.current_frame_size = 0;
		break;
	case FRAME_END_CHAR:
		uart_interface.is_new_frame_availible = TRUE;
		;
		break;
	default:
		uart_interface.rx_data[uart_interface.current_frame_size] = byte;
		uart_interface.current_frame_size++;
		break;
	}
}
