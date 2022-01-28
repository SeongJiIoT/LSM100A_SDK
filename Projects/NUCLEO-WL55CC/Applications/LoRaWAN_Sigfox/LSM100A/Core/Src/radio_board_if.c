/**
  ******************************************************************************
  * @file    radio_board_if.c
  * @author  MCD Application Team
  * @brief   This file provides an interface layer between MW and Radio Board
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
/* Includes ------------------------------------------------------------------*/
#include "radio_board_if.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* External variables ---------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */
/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Exported functions --------------------------------------------------------*/
int32_t RBI_Init(void)
{

  /* USER CODE END RBI_Init_1 */
#if defined(USE_BSP_DRIVER)
  /* code generated by MX does not support BSP */
  /* In order to use BSP driver, add the correspondent files in the IDE workspace */
  /* and define USE_BSP_DRIVER in the preprocessor definitions  or in platform.h */
  return BSP_RADIO_Init();
#else
  /* should be calling BSP_RADIO_Init() but not supported by MX*/

  GPIO_InitTypeDef  gpio_init_structure = {0};

#if LSM_RF_CHANNEL_SWITCH
    /* Enable the Radio Switch Clock */
    RF_SW_CTRL1_GPIO_CLK_ENABLE();
    RF_SW_CTRL2_GPIO_CLK_ENABLE();
    /* Configure the Radio Switch pin */
    gpio_init_structure.Pin   = RF_SW_CTRL1_PIN;
    gpio_init_structure.Mode  = GPIO_MODE_OUTPUT_PP;
    gpio_init_structure.Pull  = GPIO_NOPULL;
    gpio_init_structure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(RF_SW_CTRL1_GPIO_PORT, &gpio_init_structure);
    gpio_init_structure.Pin = RF_SW_CTRL2_PIN;
    HAL_GPIO_Init(RF_SW_CTRL2_GPIO_PORT, &gpio_init_structure);

    HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);
#else   /* LSM_RF_CHANNEL_SWITCH */
  /* Enable the Radio Switch Clock */
  RF_SW_CTRL3_GPIO_CLK_ENABLE();

  /* Configure the Radio Switch pin */
  gpio_init_structure.Pin   = RF_SW_CTRL1_PIN;
  gpio_init_structure.Mode  = GPIO_MODE_OUTPUT_PP;
  gpio_init_structure.Pull  = GPIO_NOPULL;
  gpio_init_structure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  HAL_GPIO_Init(RF_SW_CTRL1_GPIO_PORT, &gpio_init_structure);

  gpio_init_structure.Pin = RF_SW_CTRL2_PIN;
  HAL_GPIO_Init(RF_SW_CTRL2_GPIO_PORT, &gpio_init_structure);

  gpio_init_structure.Pin = RF_SW_CTRL3_PIN;
  HAL_GPIO_Init(RF_SW_CTRL3_GPIO_PORT, &gpio_init_structure);

  HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_RESET);
#endif   /* LSM_RF_CHANNEL_SWITCH */

  return 0;
#endif  /* USE_BSP_DRIVER */
  /* USER CODE BEGIN RBI_Init_3 */

  /* USER CODE END RBI_Init_3 */
}

int32_t RBI_DeInit(void)
{
  /* USER CODE BEGIN RBI_DeInit_1 */

  /* USER CODE END RBI_DeInit_1 */
#if defined(USE_BSP_DRIVER)
  /* code generated by MX does not support BSP */
  /* In order to use BSP driver, add the correspondent files in the IDE workspace */
  /* and define USE_BSP_DRIVER in the preprocessor definitions  or in platform.h */
  return BSP_RADIO_DeInit();
#else

#if LSM_RF_CHANNEL_SWITCH
    RF_SW_CTRL1_GPIO_CLK_ENABLE();
    RF_SW_CTRL2_GPIO_CLK_ENABLE();

    /* Turn off switch */
    HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);

    /* DeInit the Radio Switch pin */
    HAL_GPIO_DeInit(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN);
    HAL_GPIO_DeInit(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN);
#else   /* LSM_RF_CHANNEL_SWITCH */
  RF_SW_CTRL3_GPIO_CLK_ENABLE();

  /* Turn off switch */
  HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_RESET);

  /* DeInit the Radio Switch pin */
  HAL_GPIO_DeInit(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN);
  HAL_GPIO_DeInit(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN);
  HAL_GPIO_DeInit(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN);
#endif   /* LSM_RF_CHANNEL_SWITCH */

  return 0;
#endif  /* USE_BSP_DRIVER */
  /* USER CODE BEGIN RBI_DeInit_3 */

  /* USER CODE END RBI_DeInit_3 */
}

int32_t RBI_ConfigRFSwitch(RBI_Switch_TypeDef Config)
{
  /* USER CODE BEGIN RBI_ConfigRFSwitch_1 */

  /* USER CODE END RBI_ConfigRFSwitch_1 */
#if defined(USE_BSP_DRIVER)
  /* code generated by MX does not support BSP */
  /* In order to use BSP driver, add the correspondent files in the IDE workspace */
  /* and define USE_BSP_DRIVER in the preprocessor definitions  or in platform.h */
  return BSP_RADIO_ConfigRFSwitch((BSP_RADIO_Switch_TypeDef) Config);
#else
  switch (Config)
  {
    case RBI_SWITCH_OFF:
    {
		#if LSM_RF_CHANNEL_SWITCH
		/* Turn off switch */
		HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);
		#else   /* LSM_RF_CHANNEL_SWITCH */
		/* Turn off switch */
		HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);
		#endif   /* LSM_RF_CHANNEL_SWITCH */
		break;
    }
    case RBI_SWITCH_RX:
    {
		#if LSM_RF_CHANNEL_SWITCH
		/*Turns On in Rx Mode the RF Switch */
		HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);
		#else   /* LSM_RF_CHANNEL_SWITCH */
		/*Turns On in Rx Mode the RF Switch */
		HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);
		#endif   /* LSM_RF_CHANNEL_SWITCH */
		break;
    }
    case RBI_SWITCH_RFO_LP:
    {
		#if LSM_RF_CHANNEL_SWITCH
		/*Turns On in Tx Low Power the RF Switch */
		HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_SET);
		#else   /* LSM_RF_CHANNEL_SWITCH */
		/*Turns On in Tx Low Power the RF Switch */
		HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_SET);
		#endif   /* LSM_RF_CHANNEL_SWITCH */
		break;
    }
    case RBI_SWITCH_RFO_HP:
    {
		#if LSM_RF_CHANNEL_SWITCH
		/*Turns On in Tx High Power the RF Switch */
		HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_SET);
		#else   /* LSM_RF_CHANNEL_SWITCH */
		/*Turns On in Tx High Power the RF Switch */
		HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_SET);
		#endif   /* LSM_RF_CHANNEL_SWITCH */
		break;
    }
    default:
      break;
  }

  return 0;
#endif  /* USE_BSP_DRIVER */
  /* USER CODE BEGIN RBI_ConfigRFSwitch_3 */

  /* USER CODE END RBI_ConfigRFSwitch_3 */
}

int32_t RBI_GetTxConfig(void)
{
  /* USER CODE BEGIN RBI_GetTxConfig_1 */

  /* USER CODE END RBI_GetTxConfig_1 */
#if defined(USE_BSP_DRIVER)
  /* code generated by MX does not support BSP */
  /* In order to use BSP driver, add the correspondent files in the IDE workspace */
  /* and define USE_BSP_DRIVER in the preprocessor definitions  or in platform.h */
  return BSP_RADIO_GetTxConfig();
#else
  return RBI_CONF_RFO;
#endif  /* USE_BSP_DRIVER  || MX_NUCLEO_WL55JC1 */
  /* USER CODE BEGIN RBI_GetTxConfig_3 */

  /* USER CODE END RBI_GetTxConfig_3 */
}

int32_t RBI_GetWakeUpTime(void)
{
  /* USER CODE BEGIN RBI_GetWakeUpTime_1 */

  /* USER CODE END RBI_GetWakeUpTime_1 */
#if defined(USE_BSP_DRIVER)
  /* code generated by MX does not support BSP */
  /* In order to use BSP driver, add the correspondent files in the IDE workspace */
  /* and define USE_BSP_DRIVER in the preprocessor definitions  or in platform.h */
  return  BSP_RADIO_GetWakeUpTime();

#else
  return RF_WAKEUP_TIME_A;
#endif  /* USE_BSP_DRIVER */
  /* USER CODE BEGIN RBI_GetWakeUpTime_3 */

  /* USER CODE END RBI_GetWakeUpTime_3 */
}

int32_t RBI_IsTCXO(void)
{
  /* USER CODE BEGIN RBI_IsTCXO_1 */

  /* USER CODE END RBI_IsTCXO_1 */
#if defined(USE_BSP_DRIVER)
  /* code generated by MX does not support BSP */
  /* In order to use BSP driver, add the correspondent files in the IDE workspace */
  /* and define USE_BSP_DRIVER in the preprocessor definitions  or in platform.h */
  return BSP_RADIO_IsTCXO();

#else
  return IS_TCXO_SUPPORTED;
#endif  /* USE_BSP_DRIVER  */
  /* USER CODE BEGIN RBI_IsTCXO_3 */

  /* USER CODE END RBI_IsTCXO_3 */
}

int32_t RBI_IsDCDC(void)
{
  /* USER CODE BEGIN RBI_IsDCDC_1 */

  /* USER CODE END RBI_IsDCDC_1 */
#if defined(USE_BSP_DRIVER)
  /* code generated by MX does not support BSP */
  /* In order to use BSP driver, add the correspondent files in the IDE workspace */
  /* and define USE_BSP_DRIVER in the preprocessor definitions  or in platform.h */
  return BSP_RADIO_IsDCDC();

#else
  return IS_DCDC_SUPPORTED;
#endif  /* USE_BSP_DRIVER */
  /* USER CODE BEGIN RBI_IsDCDC_3 */

  /* USER CODE END RBI_IsDCDC_3 */
}

/* USER CODE BEGIN EF */

/* USER CODE END EF */

/* Private Functions Definition -----------------------------------------------*/
/* USER CODE BEGIN PrFD */

/* USER CODE END PrFD */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
