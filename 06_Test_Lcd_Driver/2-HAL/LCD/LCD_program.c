/**************************************************************************/
/**************************************************************************/
/****************       Author : Abdelrahman Reda      ********************/
/****************       Layer  : HAL                   ********************/
/****************       SWC    : LCD                   ********************/
/****************       Version: 1.00                  ********************/
/**************************************************************************/
/**************************************************************************/

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/INTEGER_OPERATION.h"
#include <util/delay.h>

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

#include "../../1-MCAL/1-DIO/DIO_interface.h"




void LCD_voidInit( void )
{
	/* wait more than 30ms */
	_delay_ms(40);
	/* function set command : 2 lines(DB3), 5*8 font size(DB2) */
	LCD_voidSendCommand(0b00111000);
	/* Display ON/OFF control : Display enable , No cursor , No blink */
	LCD_voidSendCommand(0b00001100);
	/* Display clear */
	LCD_voidSendCommand(0b00000001);
	/* Entry mode set ( don't care ) */

}


void LCD_voidSendCommand( u8 Copy_u8Command)
{
	/*Set RS pin to low for commands*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, LOW);

	/*Set RW pin to low for writing commands*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);

	/*Send commands using data port*/
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Command);

	/*Set enable pin to high for 2ms then set it to low*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_ENABLE_PIN, HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_ENABLE_PIN, LOW);

}


void LCD_voidSendData( u8 Copy_u8Data )
{
	/*Set RS pin to high for data*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);

	/*Set RW pin to low for writing commands*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);

	/*Send commands using data port*/
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Data);

	/*Set enable pin to high for 2ms then set it to low*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_ENABLE_PIN, HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_ENABLE_PIN, LOW);
}


void LCD_voidPrintString( const char* Copy_pcString )
{
	u8 Local_u8EndString = 0 ;
	while( Copy_pcString[ Local_u8EndString ] != '\0' )
	{
		LCD_voidSendData( Copy_pcString[ Local_u8EndString ] ) ;
		Local_u8EndString ++ ;
	}
}

void LCD_voidPrintChar( const u8 Copy_u8Char )
{
	/* send data to LCD */
	LCD_voidSendData( Copy_u8Char );
}

void LCD_voidClear( void )
{
	/* clear screen of LCD */
	LCD_voidSendCommand( 1 ) ;
}

void LCD_voidCursorHome( void )
{
	/* send command to return cursor to home */
	LCD_voidSendCommand( 0b00000010 );
}



void LCD_voidSetCursorPos( u8 Copy_u8NumOfRow, u8 Copy_u8NumOfColumn )
{
	/* variable to store address you want to start from */
	u8 Local_u8Address ;

	if( Copy_u8NumOfRow == 0 )
	{
		/* address is the same number of column in first Row */
		Local_u8Address = Copy_u8NumOfColumn ;
	}
	else if ( Copy_u8NumOfRow == 1 )
	{
		/* address is the same number of column + 40 in second Row */
		Local_u8Address = Copy_u8NumOfColumn + 0x40 ;
	}

	/* Set bit 7 to set DDRAM address */
	Local_u8Address |= ( 1 << 7 ) ;
	/* send address you want to write data from it */
	LCD_voidSendCommand( Local_u8Address );
}


void LCD_voidAddSpecialChar( const u8* Copy_pu8CharDesign, u8 Copy_u8PatternNum )
{
	/* variable to hold start address */
	u8 Local_u8CGRAMaddress = 0;
	/* set bit 6 and clear bit 7 to set CGRAM address */
	Local_u8CGRAMaddress = Copy_u8PatternNum * 8;
	Local_u8CGRAMaddress |= ( 1 << 6 );
	/* detect address of CGRAM you will write on ( 0 ~ 7 ) */
	LCD_voidSendCommand( Local_u8CGRAMaddress ) ;
	/* Write character design inside CGRAM */
	for( u8 Local_u8Counter = 0 ; Local_u8Counter < 8 ; Local_u8Counter++ )
	{
		/* Send Pattern to CGRAM byte by byte */
		LCD_voidSendData( Copy_pu8CharDesign[ Local_u8Counter ] );
	}

}

void LCD_voidPrintSpecialChar( u8 Copy_u8PatternNum, u8 Copy_u8RowNum, u8 Copy_u8ColumnNum )
{
	/* go to address on DD RAM */
	LCD_voidSetCursorPos( Copy_u8RowNum, Copy_u8ColumnNum );
	/* print special character on LCD */
	LCD_voidSendData( Copy_u8PatternNum );
}


void LCD_voidPrintNumber(u32 Copy_u32Number)
{
	u8 Local_u8BufferSize;

	Local_u8BufferSize = CalcNumOfDigit( Copy_u32Number ) + 1;

	char Local_u8Buffer[Local_u8BufferSize] ;

	IntegerToString( Local_u8Buffer, Local_u8BufferSize, Copy_u32Number );

	LCD_voidPrintString( Local_u8Buffer );

}









