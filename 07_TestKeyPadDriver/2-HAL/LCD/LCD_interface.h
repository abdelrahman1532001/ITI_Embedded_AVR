/**************************************************************************/
/**************************************************************************/
/****************       Author : Abdelrahman Reda      ********************/
/****************       Layer  : HAL                   ********************/
/****************       SWC    : LCD                   ********************/
/****************       Version: 1.00                  ********************/
/**************************************************************************/
/**************************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* functions prototypes */

void LCD_voidInit( void ) ;

void LCD_voidSendCommand( u8 Copy_u8Command) ;
void LCD_voidSendData( u8 Copy_u8Data ) ;

void LCD_voidPrintString( const char* Copy_pcString ) ;
void LCD_voidPrintChar( const u8 Copy_u8Char ) ;

void LCD_voidClear( void );

void LCD_voidSetCursorPos( u8 Copy_u8NumOfRow, u8 Copy_u8NumOfColumn );
void LCD_voidCursorHome( void );

void LCD_voidAddSpecialChar( const u8* Copy_pu8CharDesign, u8 Copy_u8PatternNum );
void LCD_voidPrintSpecialChar( u8 Copy_u8PatternNum, u8 Copy_u8RowNum, u8 Copy_u8ColumnNum );

void LCD_voidPrintNumber(u32 Copy_u32Number);

/***********************************************************************************
 ** Description => convert integer into string to print it on LCD                 **
 ** Input       => array to hold string, array size, integer to convert it        **
 ** Output      => none                                                           **
 ***********************************************************************************/
void IntegerToString(char* Copy_pcString, u8 Copy_u8StringSize, u32 Copy_u32Integer);

/***********************************************************************************
 ** Description => calculate number of digit of integer positive number           **
 ** Input       => unsigned integer number                                        **
 ** Output      => number of digit                                                **
 ***********************************************************************************/
u8 CalcNumOfDigit( u32 Copy_u8Integer );

#endif
