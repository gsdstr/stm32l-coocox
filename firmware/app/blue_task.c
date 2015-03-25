#include "stm32l1xx_hal.h"

/* StartDefaultTask function */
void BlueTask(void const * argument)
{
  for(;;)
  {
		GPIOB->ODR |= (GPIO_PIN_6);
		osDelay(300);
		GPIOB->ODR &= ~(GPIO_PIN_6);
		osDelay(300);
  }
}
