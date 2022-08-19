/**************************************************************************/
/**************************************************************************/
/****************       Author : Abdelrahman Reda      ********************/
/****************       Layer  : MCAL                  ********************/
/****************       SWC    : DIO                   ********************/
/****************       Version: 1.00                  ********************/
/**************************************************************************/
/**************************************************************************/

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_register.h"
#include "DIO_interface.h"

/*******************************************************************************************************/
/**********************************      SetPinDirection       *****************************************/
/*******************************************************************************************************/

/***************************************************************************
 **                                                                       **
 ** this function take name of port from user and number                  **
 ** of pin and direction you want to set on this pin output/input .       **
 ** return 0 then there is false data / return 1 then there is no wrong . **
 **                                                                       **
 ***************************************************************************/
u8 DIO_u8SetPinDirection ( u8 Copy_u8PortName , u8 Copy_u8PinNumber , u8 Copy_u8Direction )
{
	/* variable to check inserted data is good */
	u8 Local_u8ErrorState = 0 ;

	if( Copy_u8Direction == OUTPUT && Copy_u8PinNumber >= 0 && Copy_u8PinNumber <= 7 )
	{
		switch( Copy_u8PortName )
		{
		case PORT_A : SetBit( DDRA, Copy_u8PinNumber) ; break ;
		case PORT_B : SetBit( DDRB, Copy_u8PinNumber) ; break ;
		case PORT_C : SetBit( DDRC, Copy_u8PinNumber) ; break ;
		case PORT_D : SetBit( DDRD, Copy_u8PinNumber) ; break ;
		default     : Local_u8ErrorState = 1 ;
		}//end switch
	}//end if
	else if( Copy_u8Direction == INPUT && Copy_u8PinNumber >= 0 && Copy_u8PinNumber <= 7 )
	{
		switch( Copy_u8PortName )
		{
		case PORT_A : ClearBit( DDRA, Copy_u8PinNumber) ; break ;
		case PORT_B : ClearBit( DDRB, Copy_u8PinNumber) ; break ;
		case PORT_C : ClearBit( DDRC, Copy_u8PinNumber) ; break ;
		case PORT_D : ClearBit( DDRD, Copy_u8PinNumber) ; break ;
		default     : Local_u8ErrorState = 1 ;
		}//end switch
	}//end else if
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}//end function

/*******************************************************************************************************/
/**********************************      SetPortDirection       ****************************************/
/*******************************************************************************************************/

/***************************************************
 **                                               **
 ** this function set the selected port to output **
 ** or input                                      **
 **                                               **
 ***************************************************/

u8 DIO_u8SetPortDirection( u8 Copy_u8PortName , u8 Copy_u8Direction )
{
	/* variable to check inserted data is right or not */
	u8 Local_u8ErrorState = 0 ;

	if( Copy_u8Direction == OUTPUT )
	{
		switch( Copy_u8PortName )
		{
		case PORT_A : DDRA = DIO_PORT_OUTPUT ; break ;
		case PORT_B : DDRB = DIO_PORT_OUTPUT ; break ;
		case PORT_C : DDRC = DIO_PORT_OUTPUT ; break ;
		case PORT_D : DDRD = DIO_PORT_OUTPUT ; break ;
		default     : Local_u8ErrorState = 1 ;
		}//end switch case
	}//end if
	else if( Copy_u8Direction == INPUT )
	{
		switch( Copy_u8PortName )
		{
		case PORT_A : DDRA = DIO_PORT_INPUT ; break ;
		case PORT_B : DDRB = DIO_PORT_INPUT ; break ;
		case PORT_C : DDRC = DIO_PORT_INPUT ; break ;
		case PORT_D : DDRD = DIO_PORT_INPUT ; break ;
		default     : Local_u8ErrorState = 1 ;
		}//end switch case
	}//end else if
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}//end function

/*******************************************************************************************************/
/**********************************      SetPinValue        ********************************************/
/*******************************************************************************************************/

/*************************************************************************************************
 **                                                                                             **
 ** this function is used when pin is output                                                    **
 ** this function take name of port && number of pin wanted to be set && state of pin high/low  **
 **                                                                                             **
 *************************************************************************************************/

u8 DIO_u8SetPinValue     ( u8 Copy_u8PortName , u8 Copy_u8PinNumber , u8 Copy_u8PinValue )
{
	/* variable to check inserted data is right or not */
	u8 Local_u8ErrorState = 0 ;
	if( Copy_u8PinNumber >= 0 && Copy_u8PinNumber <= 7 )
	{
		if( Copy_u8PinValue == HIGH )
		{
			switch( Copy_u8PortName )
			{
			case PORT_A : SetBit( PORTA , Copy_u8PinNumber ) ; break ;
			case PORT_B : SetBit( PORTB , Copy_u8PinNumber ) ; break ;
			case PORT_C : SetBit( PORTC , Copy_u8PinNumber ) ; break ;
			case PORT_D : SetBit( PORTD , Copy_u8PinNumber ) ; break ;
			default     : Local_u8ErrorState = 1 ;
			}//end first switch
		}//end first inner if
		else if( Copy_u8PinValue == LOW )
		{
			switch( Copy_u8PortName )
			{
			case PORT_A : ClearBit( PORTA , Copy_u8PinNumber ) ; break ;
			case PORT_B : ClearBit( PORTB , Copy_u8PinNumber ) ; break ;
			case PORT_C : ClearBit( PORTC , Copy_u8PinNumber ) ; break ;
			case PORT_D : ClearBit( PORTD , Copy_u8PinNumber ) ; break ;
			default     : Local_u8ErrorState = 1 ;
			}//end second switch
		}//end second else if of inner if
		else
		{
			Local_u8ErrorState = 1 ;
		}//end else of inner if
	}//end outer if
	else
	{
		Local_u8ErrorState = 1 ;
	}//end else of outer if
	return Local_u8ErrorState ;
}//end function

/*******************************************************************************************************/
/**********************************      SetPortValue        *******************************************/
/*******************************************************************************************************/

/**********************************************************
 **                                                      **
 ** this function take value from 0 to 255 and set it to **
 ** the selected port                                    **
 **                                                      **
 **********************************************************/

u8 DIO_u8SetPortValue    ( u8 Copy_u8PortName , u8 Copy_u8PortValue )
{
	u8 Local_u8ErrorState = 0 ;
	if( Copy_u8PortValue >= 0 && Copy_u8PortValue <= 255  )
	{
		switch( Copy_u8PortName )
		{
		case PORT_A : PORTA = Copy_u8PortValue ; break ;
		case PORT_B : PORTB = Copy_u8PortValue ; break ;
		case PORT_C : PORTC = Copy_u8PortValue ; break ;
		case PORT_D : PORTD = Copy_u8PortValue ; break ;
		default     : Local_u8ErrorState = 1 ;
		}//end switch
	}//end if
	else
	{
		Local_u8ErrorState = 1 ;
	}//end else
    return Local_u8ErrorState ;
}//end function

/*******************************************************************************************************/
/**********************************      ReadPin        ************************************************/
/*******************************************************************************************************/

/***************************************************************************************************
 **                                                                                               **
 ** this function read the value of pin                                                           **
 ** this function take port name && number of pin you want to read && pointer to hold read value. **
 **                                                                                               **
 ***************************************************************************************************/

u8 DIO_u8ReadPin         ( u8 Copy_u8PortName , u8 Copy_u8PinNumber , u8* Copy_pu8ReadedValue )
{
	u8 Local_u8ErrorState = 0 ;
	if( Copy_u8PinNumber >= 0 && Copy_u8PinNumber <= 7 )
	{
		switch( Copy_u8PortName )
		{
		case PORT_A : *Copy_pu8ReadedValue = GetBit( PINA , Copy_u8PinNumber ) ; break ;
		case PORT_B : *Copy_pu8ReadedValue = GetBit( PINB , Copy_u8PinNumber ) ; break ;
		case PORT_C : *Copy_pu8ReadedValue = GetBit( PINC , Copy_u8PinNumber ) ; break ;
		case PORT_D : *Copy_pu8ReadedValue = GetBit( PIND , Copy_u8PinNumber ) ; break ;
		default     :  Local_u8ErrorState = 1 ;
		}//end switch
	}//end if
	else
	{
		Local_u8ErrorState = 1 ;
	}//end else
	return Local_u8ErrorState ;
}//end function

/*******************************************************************************************************/
/**********************************      ReadPort        ***********************************************/
/*******************************************************************************************************/

/************************************************
 **                                            **
 ** this function read all pins of port        **
 ** take name of port && pointer to hold value **
 **                                            **
 ************************************************/

u8 DIO_u8ReadPort        ( u8 Copy_u8PortName , u8* Copy_pu8PortValue)
{
	u8 Local_u8NoError = 0 ;
	switch( Copy_u8PortName )
	{
	case PORT_A : *Copy_pu8PortValue = PINA ; break ;
	case PORT_B : *Copy_pu8PortValue = PINB ; break ;
	case PORT_C : *Copy_pu8PortValue = PINC ; break ;
	case PORT_D : *Copy_pu8PortValue = PIND ; break ;
	default     : Local_u8NoError = 1 ;
	}//end switch case
	return Local_u8NoError ;
}//end function

/*******************************************************************************************************/
/*******************************************************************************************************/
