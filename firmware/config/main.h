#include "stm32l1xx.h"
#include "stm32l1xx_hal_conf.h"

/*

  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = (GPIO_PIN_6 | GPIO_PIN_7);
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_MEDIUM;
  HAL_GPIO_Init( GPIOB , &GPIO_InitStruct);

  while (1)
  {
	  GPIOB->ODR &= ~(GPIO_PIN_6 | GPIO_PIN_7);
	  HAL_Delay(100);
	  GPIOB->ODR |= (GPIO_PIN_6 | GPIO_PIN_7);
	  HAL_Delay(100);
  }

 */
