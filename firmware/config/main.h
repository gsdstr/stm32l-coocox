#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "cmsis_os.h"

extern osMessageQId xLCDQueueHandle;

/* Type of the message sent to the LCD task. */
typedef struct
{
	uint8_t *pcMessage;
	uint8_t xMessageType;
} xLCDMessage;

void LCD_Init(void);
void LCD_DisplayString(uint8_t *pcMessage);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
