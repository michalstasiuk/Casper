/*
 * time.c
 *
 *  Created on: Dec 21, 2021
 *      Author: stasiukm
 */
#include "time.h"

void delay_ms(uint32_t time_ms) {
	Delay_Time_ms = time_ms;
	while (Delay_Time_ms != 0) {
	}
}
void decrement_time_delay() {
	if (Delay_Time_ms != 0)
		Delay_Time_ms--;
}
