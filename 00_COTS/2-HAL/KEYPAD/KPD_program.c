/**************************************************************************/
/**************************************************************************/
/****************       Author : Abdelrahman Reda      ********************/
/****************       Layer  : HAL                   ********************/
/****************       SWC    : KPD                   ********************/
/****************       Version: 1.00                  ********************/
/**************************************************************************/
/**************************************************************************/

#include "../../4-LIB/STD_TYPES.h"
#include <util/delay.h>

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

#include "../../1-MCAL/1-DIO/DIO_interface.h"

void KPD_voidInit( void )
{
	u8 Local_u8Iterator = 0;
    u8 KPD_ROW_ARR[]    ={ KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN };
    u8 KPD_COLUMN_ARR[] ={ KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN };

	/* set row as input     */
    for( Local_u8Iterator = 0 ; Local_u8Iterator < 4; Local_u8Iterator++ )
    {
    	/* active pull up */
    	DIO_u8SetPinDirection(KPD_DATA_PORT, KPD_ROW_ARR[Local_u8Iterator], INPUT);
    	DIO_u8SetPinValue(KPD_DATA_PORT, KPD_ROW_ARR[Local_u8Iterator], HIGH);
    }

	/* set column as output */
    for( Local_u8Iterator = 0 ; Local_u8Iterator < 4; Local_u8Iterator++ )
    {
    	/* active pull up */
    	DIO_u8SetPinDirection(KPD_DATA_PORT, KPD_COLUMN_ARR[Local_u8Iterator], OUTPUT);
    	DIO_u8SetPinValue(KPD_DATA_PORT, KPD_COLUMN_ARR[Local_u8Iterator], HIGH);
    }

}

void KPD_voidGetPressedKey( u8* Copy_pu8PressedKey )
{
    u8 KPD_ROW_ARR[]    ={ KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN };
    u8 KPD_COLUMN_ARR[] ={ KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN };

	u8 Local_u8ColumnIndex = 0;
	u8 Local_u8RowIndex    = 0;

	u8 Local_u8RowChek    = 1;
	*Copy_pu8PressedKey   = NOT_PRESSED;

	/* Loop for columns */
	for( Local_u8ColumnIndex = 0; Local_u8ColumnIndex < 4; Local_u8ColumnIndex++ )
	{
		/* set one column to low */
		DIO_u8SetPinValue(KPD_DATA_PORT, KPD_COLUMN_ARR[Local_u8ColumnIndex], LOW);

		/* Loop for checking rows */
		for( Local_u8RowIndex = 0; Local_u8RowIndex < 4; Local_u8RowIndex++ )
		{
			/* check four row one by one */
			DIO_u8ReadPin(KPD_DATA_PORT, KPD_ROW_ARR[Local_u8RowIndex], &Local_u8RowChek);

			/* Local_u8RowChek = LOW when press button */
			if( Local_u8RowChek == LOW )
			{
				/* take pressed key from map */
				*Copy_pu8PressedKey = KPD_u8PrivateMap[Local_u8RowIndex][Local_u8ColumnIndex];

				/* set back column to high */
				DIO_u8SetPinValue(KPD_DATA_PORT, KPD_COLUMN_ARR[Local_u8ColumnIndex], HIGH);

				/* delay */
				_delay_ms(250);

			 }/* if( Local_u8RowChek == LOW ) */

		 }/* end row for() */

		/* set back column to high */
		DIO_u8SetPinValue(KPD_DATA_PORT, KPD_COLUMN_ARR[Local_u8ColumnIndex], HIGH);
	}/* end column for() loop */
}/* end function */






