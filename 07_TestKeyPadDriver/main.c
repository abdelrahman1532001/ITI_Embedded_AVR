/*
 * main.c
 *
 *  Created on: Aug 15, 2022
 *      Author: User
 */

#include "4-LIB/STD_TYPES.h"

#include "util/delay.h"

#include "2-HAL/KEYPAD/KPD_interface.h"
#include "2-HAL/KEYPAD/KPD_config.h"

#include "2-HAL/LCD/LCD_config.h"
#include "2-HAL/LCD/LCD_interface.h"
#include "2-HAL/LCD/LCD_SpecialChars.h"



#include "1-MCAL/1-DIO/DIO_interface.h"


void main( void )
{
	/* initiate direction of pins of LCD */
	DIO_u8SetPortDirection(LCD_DATA_PORT, OUTPUT);
	DIO_u8SetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT);
	DIO_u8SetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT);
	DIO_u8SetPinDirection(LCD_CTRL_PORT, LCD_ENABLE_PIN, OUTPUT);

	/* call initiate function */
	LCD_voidInit() ;
	KPD_voidInit() ;

	u8 Local_u8Key ;

	while(1)
	{
		KPD_voidGetPressedKey( &Local_u8Key );
		if( Local_u8Key != NOT_PRESSED )
		{
			LCD_voidPrintChar( Local_u8Key );
		}
	}//end while
}//end main
