#include "STD_TYPES.h"
#include "bit.h"
#define F_CPU 8000000UL
#include"avr/io.h"
#include"avr/delay.h"
#include "DIO_Interface.h"
#include"LCD_Config.h"
#include"LCD_Interface.h"
#include"ADC_Config.h"
#include"ADC_Interface.h"

void main (void)
{LCD_VidInit();
ADC_VidInit();
	u16 ADC_Reading;
	u16 temp;
	while(1)
		{
		ADC_Reading=ADC_U16ReadChannel(ADC7);
		ADC_Reading=(ADC_Reading*5000UL)/1024;
		temp=ADC_Reading/10;
		LCD_VidSendCommand(LCD_Clear);
		LCD_VidSetPosition(0 , 0 );
		LCD_VidWriteNumber(temp);
		_delay_ms(500);
		}
}
