/*
 * time.h
 *
 *  Created on: Dec 21, 2021
 *      Author: stasiukm
 */

#ifndef TIME_TIME_H_
#define TIME_TIME_H_

#include "type_defs.h"

void delay_ms(uint32_t time_ms);

//use in system systick
void decrement_time_delay();

uint32_t Delay_Time_ms;

#endif /* TIME_TIME_H_ */
