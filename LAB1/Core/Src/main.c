/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

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
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  int NUM[12][12];
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++)
		{
			if (i == j) 	NUM[i][j] = 1;
			else NUM[i][j] = 0;
		}
	}
	void display12SEG(int num)
	{
	  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, NUM[num][0]);
	  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, NUM[num][1]);
	  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, NUM[num][2]);
	  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, NUM[num][3]);
	  HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, NUM[num][4]);
	  HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, NUM[num][5]);
	  HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, NUM[num][6]);
	  HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, NUM[num][7]);
	  HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, NUM[num][8]);
	  HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, NUM[num][9]);
	  HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, NUM[num][10]);
	  HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, NUM[num][11]);
	}

	int LED_STATUS[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	void clearAllClock()
	{
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, LED_STATUS[0] = 0);
		HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, LED_STATUS[1] = 0);
		HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, LED_STATUS[2] = 0);
		HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, LED_STATUS[3] = 0);
		HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, LED_STATUS[4] = 0);
		HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, LED_STATUS[5] = 0);
		HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, LED_STATUS[6] = 0);
		HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, LED_STATUS[7] = 0);
		HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, LED_STATUS[8] = 0);
		HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, LED_STATUS[9] = 0);
		HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, LED_STATUS[10] = 0);
		HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, LED_STATUS[11] = 0);
	}



	void setNumberOnClock(int num)
	{
		LED_STATUS[num] = 1;
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, LED_STATUS[0]);
		HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, LED_STATUS[1]);
		HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, LED_STATUS[2]);
		HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, LED_STATUS[3]);
		HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, LED_STATUS[4]);
		HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, LED_STATUS[5]);
		HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, LED_STATUS[6]);
		HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, LED_STATUS[7]);
		HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, LED_STATUS[8]);
		HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, LED_STATUS[9]);
		HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, LED_STATUS[10]);
		HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, LED_STATUS[11]);
	}

	void clearNumberOnClock(int num)
	{
		LED_STATUS[num] = 0;
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, LED_STATUS[0]);
		HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, LED_STATUS[1]);
		HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, LED_STATUS[2]);
		HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, LED_STATUS[3]);
		HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, LED_STATUS[4]);
		HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, LED_STATUS[5]);
		HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, LED_STATUS[6]);
		HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, LED_STATUS[7]);
		HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, LED_STATUS[8]);
		HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, LED_STATUS[9]);
		HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, LED_STATUS[10]);
		HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, LED_STATUS[11]);
	}

	/* USER CODE END 2 */
	clearAllClock();
	int count = 11;
	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
	  /* USER CODE END WHILE */
	  //display12SEG(count);
	  setNumberOnClock(count);
	  count--;
	  if (count < 0){
		  count = 11;
		  clearAllClock();
	  }
	  HAL_Delay(1000);
	  /* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_1_Pin|LED_2_Pin|LED_3_Pin|LED_4_Pin
                          |LED_5_Pin|LED_6_Pin|LED_7_Pin|LED_8_Pin
                          |LED_9_Pin|LED_10_Pin|LED_11_Pin|LED_12_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_1_Pin LED_2_Pin LED_3_Pin LED_4_Pin
                           LED_5_Pin LED_6_Pin LED_7_Pin LED_8_Pin
                           LED_9_Pin LED_10_Pin LED_11_Pin LED_12_Pin */
  GPIO_InitStruct.Pin = LED_1_Pin|LED_2_Pin|LED_3_Pin|LED_4_Pin
                          |LED_5_Pin|LED_6_Pin|LED_7_Pin|LED_8_Pin
                          |LED_9_Pin|LED_10_Pin|LED_11_Pin|LED_12_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
