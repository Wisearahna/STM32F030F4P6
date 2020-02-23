/*
 * CB.c
 *
 *  Created on: Feb 22, 2020
 *      Author: Wise
 */
#include "main.h"

  //
uint16_t	arr_val=hnote;

  void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
  {

	  if(htim->Instance == TIM14) //interrupt comes from TIM14
  	  {
  		  HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);

  		  //
  		  arr_val=arr_val+dnote;
  		  if(arr_val > lnote)	arr_val=hnote;

  	  }
  	  if(htim->Instance == TIM16) //interrupt comes from TIM16
  	  {
  		  HAL_GPIO_TogglePin(BUZZ_GPIO_Port, BUZZ_Pin);
  		  //
  		  htim->Instance->ARR = arr_val;
  		  htim->Init.Period = arr_val;
  	  }

  }
