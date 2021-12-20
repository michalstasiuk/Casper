/*
 * type_defs.h
 *
 *  Created on: Dec 20, 2021
 *      Author: stasiukm
 */

#include "stm32f1xx_hal.h"

#ifndef HW_LAYER_TYPE_DEFS_H_
#define HW_LAYER_TYPE_DEFS_H_

#define LED2_Pin GPIO_PIN_0
#define LED2_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_1
#define LED1_GPIO_Port GPIOC
#define LED1_CUT_Pin GPIO_PIN_2
#define LED1_CUT_GPIO_Port GPIOC
#define LED2_CUT_Pin GPIO_PIN_3
#define LED2_CUT_GPIO_Port GPIOC
#define ENCODER2_A_Pin GPIO_PIN_0
#define ENCODER2_A_GPIO_Port GPIOA
#define ENCODER2_B_Pin GPIO_PIN_1
#define ENCODER2_B_GPIO_Port GPIOA
#define LED1_DIM_Pin GPIO_PIN_2
#define LED1_DIM_GPIO_Port GPIOA
#define LED2_DIM_Pin GPIO_PIN_3
#define LED2_DIM_GPIO_Port GPIOA
#define VOLTAGE_ADC1_Pin GPIO_PIN_7
#define VOLTAGE_ADC1_GPIO_Port GPIOA
#define CURRENT_ADC1_Pin GPIO_PIN_4
#define CURRENT_ADC1_GPIO_Port GPIOC
#define FAULT_Pin GPIO_PIN_5
#define FAULT_GPIO_Port GPIOC
#define DIR1B_Pin GPIO_PIN_1
#define DIR1B_GPIO_Port GPIOB
#define DIR1A_Pin GPIO_PIN_2
#define DIR1A_GPIO_Port GPIOB
#define DIR2B_Pin GPIO_PIN_10
#define DIR2B_GPIO_Port GPIOB
#define DIR2A_Pin GPIO_PIN_11
#define DIR2A_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_15
#define LED3_GPIO_Port GPIOB
#define PWM_EXT1_Pin GPIO_PIN_6
#define PWM_EXT1_GPIO_Port GPIOC
#define PWM_EXT2_Pin GPIO_PIN_7
#define PWM_EXT2_GPIO_Port GPIOC
#define PWM1_Pin GPIO_PIN_8
#define PWM1_GPIO_Port GPIOA
#define PWM2_Pin GPIO_PIN_9
#define PWM2_GPIO_Port GPIOA
#define ENCODER1_B_Pin GPIO_PIN_6
#define ENCODER1_B_GPIO_Port GPIOB
#define ENCODER1_A_Pin GPIO_PIN_7
#define ENCODER1_A_GPIO_Port GPIOB

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
void Error_Handler(void);


#endif /* HW_LAYER_TYPE_DEFS_H_ */
