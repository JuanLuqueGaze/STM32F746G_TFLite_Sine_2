/**
  ******************************************************************************
  * @file         stm32f7xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "stm32746g_discovery.h"
/* USER CODE BEGIN Includes */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* External functions --------------------------------------------------------*/
/* USER CODE END 0 */

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  DISCOVERY_COM1_TX_GPIO_CLK_ENABLE();
  DISCOVERY_COM1_RX_GPIO_CLK_ENABLE();
  DISCOVERY_COM1_CLK_ENABLE();
  /*##-2- Configure peripheral GPIO ##########################################*/
  /* UART TX GPIO pin configuration  */
  GPIO_InitStruct.Pin       = DISCOVERY_COM1_TX_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
  GPIO_InitStruct.Alternate = DISCOVERY_COM1_TX_AF;
  HAL_GPIO_Init(DISCOVERY_COM1_TX_GPIO_PORT, &GPIO_InitStruct);
  /* UART RX GPIO pin configuration  */
  GPIO_InitStruct.Pin = DISCOVERY_COM1_RX_PIN;
  GPIO_InitStruct.Alternate = DISCOVERY_COM1_RX_AF;
  
  HAL_GPIO_Init(DISCOVERY_COM1_RX_GPIO_PORT, &GPIO_InitStruct);
}



/**
  * @brief UART MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO configuration to their default state
  * @param huart: UART handle pointer
  * @retval None
  */
 void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{
  /*##-1- Reset peripherals ##################################################*/
  DISCOVERY_COM1_FORCE_RESET();
  DISCOVERY_COM1_RELEASE_RESET();

     /*##-2- Disable peripherals and GPIO Clocks #################################*/
  /* Configure USART6 Tx as alternate function  */
  HAL_GPIO_DeInit(DISCOVERY_COM1_TX_GPIO_PORT, DISCOVERY_COM1_TX_PIN);
  /* Configure USART6 Rx as alternate function  */
  HAL_GPIO_DeInit(DISCOVERY_COM1_RX_GPIO_PORT, DISCOVERY_COM1_RX_PIN);
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
