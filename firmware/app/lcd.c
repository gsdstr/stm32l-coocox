#include "main.h"
#include "cmsis_os.h"
#include "stm32l152l_discovery_glass_lcd.h"

void LCD_Init(void){
	BSP_LCD_GLASS_Init();
}

void LCD_DisplayString(uint8_t *pcMessage){
	xLCDMessage message;
	message.pcMessage = pcMessage;
	message.xMessageType = 10;
	osMessagePut(xLCDQueueHandle, &message, 100);
}

void StartLCDTask(void const * argument)
{
	//const uint8_t * const pcString = "www.FreeRTOS.org";
	uint8_t LCD_String[]= "START";
	BSP_LCD_GLASS_DisplayString(LCD_String);
	//BSP_LCD_GLASS_DisplayString(LCD_String, SCROLL_NUM, SCROLL_SPEED_L);

	xLCDMessage *message;
	const uint8_t * const pcBlankLine = "     ";

	//LCD_GLASS_Init();

	for(;;)
	{
		/* Wait for a message to arrive that requires displaying. */
		osEvent evt = osMessageGet( xLCDQueueHandle, osWaitForever );
		if (evt.status == osEventMessage) {
			//BSP_LCD_GLASS_DisplayString(pcBlankLine);
			message = evt.value.p;
			if (message.xMessageType == 10){
				BSP_LCD_GLASS_DisplayString(message->pcMessage);
				osDelay(1000);
			}
		}
		BSP_LCD_GLASS_DisplayString(LCD_String);
	}
}
