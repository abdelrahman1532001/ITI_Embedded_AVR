/**************************************************************************/
/**************************************************************************/
/****************       Author : Abdelrahman Reda      ********************/
/****************       Layer  : HAL                   ********************/
/****************       SWC    : LED                   ********************/
/****************       Version: 1.00                  ********************/
/**************************************************************************/
/**************************************************************************/

#include "../../4-LIB/STD_TYPES.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"
#include "LED_interface.h"


u8 LED_u8LightOn  ( strt_LedData* Copy_strLedData )
{
	u8 Local_u8ErrorState = 0 ;
	if ( Copy_strLedData != NULL )
	{
		switch( Copy_strLedData->HAL_u8ConnectType )
		{
		case SINK   : DIO_u8SetPinDirection(Copy_strLedData->HAL_u8LedPort, Copy_strLedData->HAL_u8LedPin, OUTPUT) ;
					  DIO_u8SetPinValue(Copy_strLedData->HAL_u8LedPort, Copy_strLedData->HAL_u8LedPin, LOW);
						break ;
		case SOURCE : DIO_u8SetPinDirection(Copy_strLedData->HAL_u8LedPort, Copy_strLedData->HAL_u8LedPin, OUTPUT) ;
		              DIO_u8SetPinValue(Copy_strLedData->HAL_u8LedPort, Copy_strLedData->HAL_u8LedPin, HIGH);
			            break ;
		default     : Local_u8ErrorState = 1 ; /* there is an error */
		}
	}
	else
	{
		Local_u8ErrorState = 1 ; /* there is an error */
	}
	return Local_u8ErrorState ;
}
u8 LED_u8LightOff ( strt_LedData* Copy_strLedData )
{
	u8 Local_u8ErrorState = 0 ;
	if ( Copy_strLedData != NULL )
	{
		switch( Copy_strLedData->HAL_u8ConnectType )
		{
		case SINK   : DIO_u8SetPinDirection(Copy_strLedData->HAL_u8LedPort, Copy_strLedData->HAL_u8LedPin, OUTPUT) ;
					  DIO_u8SetPinValue(Copy_strLedData->HAL_u8LedPort, Copy_strLedData->HAL_u8LedPin, HIGH);
						break ;
		case SOURCE : DIO_u8SetPinDirection(Copy_strLedData->HAL_u8LedPort, Copy_strLedData->HAL_u8LedPin, OUTPUT) ;
					  DIO_u8SetPinValue(Copy_strLedData->HAL_u8LedPort, Copy_strLedData->HAL_u8LedPin, LOW);
						break ;
		default     : Local_u8ErrorState = 1 ; /* there is an error */
		}
	}
	else
	{
		Local_u8ErrorState = 1 ; /* there is an error */
	}
	return Local_u8ErrorState ;
}
