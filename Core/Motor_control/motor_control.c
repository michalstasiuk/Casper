/*
 * motor_control.c
 *
 *  Created on: Dec 21, 2021
 *      Author: stasiukm
 */
#include "motor_control.h"
#include "tim.h"
#include "time.h"

#define MAX_RPM 1000
#define MAX_SPEED 3000
#define PWM_FREQUENCY 1000
#define PWM_INTERVAL 0.001

#define KP 2
#define KI 1
#define KD 5

typedef struct{
	float duty_cycle;
	uint32_t target_rotation_ps;
	uint32_t current_rotation_ps;
	float target_rpm;
	float current_rpm;
	int32_t target_speed;
	bool enabled;
	int32_t integration_sum;
}motor_status;

watchdog_timer motors_watchdog_timer;

motor_status motor_left;
motor_status motor_right;

void motor_left_forward(){
	HAL_GPIO_WritePin(GPIOB, DIR1A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DIR1B_Pin, GPIO_PIN_RESET);

	motor_left.target_speed = 2000;
	motor_right.target_speed = 2000;
}

void motor_right_forward(){
	HAL_GPIO_WritePin(GPIOB, DIR2A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DIR2B_Pin, GPIO_PIN_RESET);

	motor_left.target_speed = 2000;
	motor_right.target_speed = 2000;
}

void motor_left_backward(){
	HAL_GPIO_WritePin(GPIOB, DIR1A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DIR1B_Pin, GPIO_PIN_SET);

	motor_left.target_speed = -2000;
	motor_right.target_speed = -2000;
}

void motor_right_backward(){
	HAL_GPIO_WritePin(GPIOB, DIR2A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DIR2B_Pin, GPIO_PIN_SET);

	motor_left.target_speed = -2000;
	motor_right.target_speed = -2000;
}

void left_motor_stop(){
	motor_left.target_speed = 0;
}

void right_motor_stop(){
	motor_right.target_speed = 0;
}

void go_forward(){
	motor_left_forward();
	motor_right_forward();
}

void go_backward(){
	motor_left_backward();
	motor_right_backward();
}

void turn_left(){
	motor_right_forward();
	motor_left_backward();
}

void turn_right(){
	motor_left_forward();
	motor_right_backward();
}

void STOP(){
	left_motor_stop();
	right_motor_stop();
}

void set_watchdog_active(){
	motors_watchdog_timer.counter = 0;
	motors_watchdog_timer.is_counter_active = TRUE;
}

void wsad_motor_control(uint8_t byte) {
	switch ((char)byte) {
	case 'w':
		set_watchdog_active();
		go_forward();
		break;
	case 's':
		set_watchdog_active();
		go_backward();
		break;
	case 'a':
		set_watchdog_active();
		turn_left();
		break;
	case 'd':
		set_watchdog_active();
		turn_right();
		break;
	default:
		STOP();
		break;
	}
}

void deserialize_motor_control_frame(uint8_t* frame, uint8_t size){
	switch (frame[1]) {
		case '!':{
			motor_left.enabled = frame[2];
			motor_right.enabled = frame[2];
			break;
		}
		case '?':{
			set_watchdog_active();
			motor_left.target_speed = (uint8_t)(MAX_SPEED*((frame[2]-100)/100));
			motor_right.target_speed = (uint8_t)(MAX_SPEED*((frame[3]-100)/100));

			if(motor_left.target_speed >=0){
				HAL_GPIO_WritePin(GPIOB, DIR1A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB, DIR1B_Pin, GPIO_PIN_RESET);
			} else {
				HAL_GPIO_WritePin(GPIOB, DIR1A_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB, DIR1B_Pin, GPIO_PIN_SET);
			}
			if (motor_right.target_speed >= 0) {
				HAL_GPIO_WritePin(GPIOB, DIR2A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB, DIR2B_Pin, GPIO_PIN_RESET);
			} else {
				HAL_GPIO_WritePin(GPIOB, DIR2A_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB, DIR2B_Pin, GPIO_PIN_SET);
			}
			break;
		}
		case '@':{
			wsad_motor_control(frame[2]);
			break;
		}
		default:
			break;
	}
}


uint32_t counter_left = 0;
uint32_t counter_right = 0;

int32_t count_left = 0;
int32_t count_right = 0;

extern int32_t speed_left;
extern int32_t speed_right;

int32_t old_error_left = 0;
int32_t old_error_right = 0;

void motor_control_handler(void){
	int32_t error_left = motor_left.target_speed - speed_left;
	int32_t error_right = motor_right.target_speed - speed_right;

	motor_left.integration_sum += error_left*PWM_INTERVAL;
	motor_right.integration_sum += error_right*PWM_INTERVAL;

	motor_left.duty_cycle = KP*error_left + KI*motor_left.integration_sum + KD*(error_left-old_error_left);
	motor_right.duty_cycle = KP*error_right + KI*motor_right.integration_sum + KD*(error_right-old_error_right);

	old_error_left = error_left;
	old_error_right = error_right;

	TIM2->CCR1 = motor_left.duty_cycle;
	TIM2->CCR2 = motor_right.duty_cycle;
}



/**
  * @brief  Input Capture callback in non-blocking mode
  * @param  htim TIM IC handle
  * @retval None
  */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2){
		counter_left = __HAL_TIM_GET_COUNTER(htim);
		count_left = (int32_t)counter_left;
	} else if (htim->Instance == TIM4){
		counter_right = __HAL_TIM_GET_COUNTER(htim);
		count_right = (int32_t)counter_right;
	}
}

