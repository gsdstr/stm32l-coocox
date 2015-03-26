#include "stm32l1xx_hal.h"

/* StartDefaultTask function */
void BlueTask(void const * argument)
{
  for(;;)
  {
	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_6);
	  osDelay(300);
  }
}
