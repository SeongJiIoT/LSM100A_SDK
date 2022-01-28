/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    platform.h
  * @author  MCD Application Team
  * @brief   Header for General HW instances configuration
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Exported constants --------------------------------------------------------*/

//#define USE_BSP_DRIVER

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include "stm32wlxx.h"
#include "main.h"
#include "stm32wlxx_ll_gpio.h"
#if defined(USE_BSP_DRIVER)
/* code generated by STM32CubeMX does not support BSP.  */
/* In order to use BSP, users can add the BSP files in the IDE project space */
/* and define USE_BSP_DRIVER in the preprocessor definitions  */
#include "stm32wlxx_nucleo.h"
#include "stm32wlxx_nucleo_radio.h"
#endif /* defined(USE_BSP_DRIVER) */

/* USER CODE BEGIN include */

/* USER CODE END include */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /* __PLATFORM_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
