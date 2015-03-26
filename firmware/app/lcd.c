#include "stm32l152l_discovery_glass_lcd.h"

void LCD_GLASS_Init(void){
	BSP_LCD_GLASS_Init();
	uint8_t LCD_String[]= "00 99";
	//BSP_LCD_GLASS_DisplayString(LCD_String, SCROLL_NUM, SCROLL_SPEED_L);
	BSP_LCD_GLASS_DisplayString(LCD_String);
}
