/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
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
#define PWM_EXT3_Pin GPIO_PIN_8
#define PWM_EXT3_GPIO_Port GPIOC
#define PWM_EXT4_Pin GPIO_PIN_9
#define PWM_EXT4_GPIO_Port GPIOC
#define PWM1_Pin GPIO_PIN_8
#define PWM1_GPIO_Port GPIOA
#define PWM2_Pin GPIO_PIN_9
#define PWM2_GPIO_Port GPIOA
#define ENCODER1_B_Pin GPIO_PIN_6
#define ENCODER1_B_GPIO_Port GPIOB
#define ENCODER1_A_Pin GPIO_PIN_7
#define ENCODER1_A_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
