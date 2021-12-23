/*
 * manipulator.c
 *
 *  Created on: Dec 23, 2021
 *      Author: stasiukm
 */

#include "manipulator.h"
#include "tim.h"

void deserialize_manipulator_control_frame(uint8_t* frame, uint8_t size){
	uint16_t axis1 = (uint16_t)((frame[1]<<8)+frame[2]);
	uint16_t axis2 = (uint16_t)((frame[3]<<8)+frame[4]);
	uint16_t axis3 = (uint16_t)((frame[5]<<8)+frame[6]);

	TIM3->CCR1 = (uint16_t)(axis1/360)*TIM3->ARR;
	TIM3->CCR2 = (uint16_t)(axis2/360)*TIM3->ARR;
	TIM3->CCR3 = (uint16_t)(axis3/360)*TIM3->ARR;
}

