#include "main.h"
#include "cmsis_os.h"
#include "stm32l152l_discovery_glass_lcd.h"

osPoolId mPoolId;

void LCD_Init(void){
	BSP_LCD_GLASS_Init();
}

void LCD_DisplayString(uint8_t *pcMessage){
	xLCDMessage *message;
	message = osPoolAlloc(mPoolId);
	message->pcMessage = pcMessage;
	message->xMessageType = 10;
	osMessagePut(xLCDQueueHandle, message, 100);
}

//sprintf(strDisp, "%d °C", temperature_C );
void StartLCDTask(void const * argument)
{
	osPoolDef(mPool, 8, xLCDMessage); // Define memory pool
	mPoolId = osPoolCreate(osPool(mPool));


	//const uint8_t * const pcString = "www.FreeRTOS.org";
	//LCD_GLASS_Init();
	BSP_LCD_GLASS_BarLevelConfig(BATTERYLEVEL_OFF);
	uint8_t LCD_String[]= "START";
	BSP_LCD_GLASS_DisplayString(LCD_String);

	//BSP_LCD_GLASS_DisplayString(LCD_String, SCROLL_NUM, SCROLL_SPEED_L);

	xLCDMessage *message;
	const uint8_t * const pcBlankLine = "     ";

	for(;;)
	{
		/* Wait for a message to arrive that requires displaying. */
		osEvent evt = osMessageGet( xLCDQueueHandle, osWaitForever );
		if (evt.status == osEventMessage) {
			//BSP_LCD_GLASS_DisplayString(pcBlankLine);
			message = evt.value.v;
			if (message->xMessageType == 10){
				BSP_LCD_GLASS_DisplayString(message->pcMessage);
				BSP_LCD_GLASS_DisplayString(pcBlankLine);
				osDelay(800);
			}
			osPoolFree(mPoolId, message);
		}
		BSP_LCD_GLASS_DisplayString(LCD_String);
	}
}
