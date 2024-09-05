/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.h
  * @brief   This file contains the headers of the interrupt handlers.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @name Core IRQ Handlers
 */
/**@{*/   
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
/**@}*/ 

/**
 * @name GPIO EXTI IRQ Handlers
 */
/**@{*/   
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
void EXTI9_5_IRQHandler(void);
void EXTI15_10_IRQHandler(void);
/**@}*/ 

/**
 * @name Shared IRQ Handlers
 */
/**@{*/   
void HASH_RNG_IRQHandler(void);
/**@}*/ 

/**
 * @name USB IRQ Handlers
 */
/**@{*/   
void OTG_FS_IRQHandler(void);
/**@}*/ 


void ADC_IRQHandler(void);
void TIM3_IRQHandler(void);

/**
 * @name Other Handlers
 * 
 * This is not an IRQ, but needed by the HAL. Since there isn't a better 
 * place to put it, we put here for now. These are implemented with the shared
 * handlers.
 */
/**@{*/    
void Error_Handler(void);
/**@}*/ 

// These are inlineable handlers defined by application code. We 
// include them here for later inlining into the actual IRQ Handlers. 
#include <time/systick_handler.h>
#include <hal_platform/entropy_handlers.h>
#include <hal_platform/usb_handlers.h>
#include <hal_platform/shared_handlers.h>

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_IT_H */
