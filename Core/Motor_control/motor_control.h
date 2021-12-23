/*
 * motor_control.h
 *
 *  Created on: Dec 21, 2021
 *      Author: stasiukm
 */

#ifndef MOTOR_CONTROL_MOTOR_CONTROL_H_
#define MOTOR_CONTROL_MOTOR_CONTROL_H_

#include "type_defs.h"

void deserialize_motor_control_frame(uint8_t* frame, uint8_t size);

void motor_control_handler(void);

#endif /* MOTOR_CONTROL_MOTOR_CONTROL_H_ */
