/*
 * communication.h
 *
 *  Created on: Dec 21, 2021
 *      Author: stasiukm
 */

#ifndef COMMUNICATION_COMMUNICATION_H_
#define COMMUNICATION_COMMUNICATION_H_

#include "type_defs.h"

#include "usart.h"
#include "dma.h"

#define UART_MAX_RX_LEGHT 255

void transmit_data(uint8_t* data, uint8_t size);

bool is_new_frame_availible(void);

uint8_t get_new_frame(uint8_t* frame);

void uart_irq_handler(uint8_t byte);

#endif /* COMMUNICATION_COMMUNICATION_H_ */
