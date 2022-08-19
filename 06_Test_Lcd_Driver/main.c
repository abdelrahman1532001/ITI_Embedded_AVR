/*
 * main.c
 *
 *  Created on: Aug 15, 2022
 *      Author: User
 */

#include "4-LIB/STD_TYPES.h"
#include "util/delay.h"

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

	LCD_voidAddSpecialChar( LCD_pu8SpecialChars[0], 0);
	LCD_voidAddSpecialChar( LCD_pu8SpecialChars[1], 1);
	LCD_voidAddSpecialChar( LCD_pu8SpecialChars[2], 2);
	LCD_voidAddSpecialChar( LCD_pu8SpecialChars[3], 3);
	LCD_voidAddSpecialChar( LCD_pu8SpecialChars[4], 4);

	LCD_voidPrintSpecialChar(0, 0, 0);

	LCD_voidPrintSpecialChar(4, 0, 1);


	for( u8 Local_u8Counter = 0 ; Local_u8Counter < 5 ; Local_u8Counter++ )
	{
		for( u8 Local_u8Motion = 1 ; Local_u8Motion < 4 ; Local_u8Motion++ )
		{
			_delay_ms(250);

			LCD_voidClear();

			LCD_voidPrintSpecialChar(Local_u8Motion, 0, (Local_u8Motion + 3 * Local_u8Counter));

			LCD_voidPrintSpecialChar(4, 0, (Local_u8Motion + 3 * Local_u8Counter) + 1);

		}
	}
	LCD_voidClear();

	LCD_voidSetCursorPos(0, 6);
	LCD_voidPrintString("THE");
	LCD_voidSetCursorPos(1, 6);
	LCD_voidPrintString("END");

	while(1)
	{

	}//end while
}//end main
