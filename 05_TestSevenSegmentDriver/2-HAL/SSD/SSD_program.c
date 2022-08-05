/**************************************************************************/
/**************************************************************************/
/****************       Author : Abdelrahman Reda      ********************/
/****************       Layer  : HAL                   ********************/
/****************       SWC    : SSD                   ********************/
/****************       Version: 1.00                  ********************/
/**************************************************************************/
/**************************************************************************/

#include "../../4-LIB/STD_TYPES.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"
#include "SSD_private.h"
#include "SSD_interface.h"


u8 SSD_u8Show    ( u8 Copy_u8NumberToShow , strt_SSDConfig* Copy_strt_SSDData )
{
	u8 Local_u8ErrorState = 0 ;
	if( Copy_u8NumberToShow >= 0 && Copy_strt_SSDData != NULL )
	{
		// hold the digit will be shown on segment
		u8 Local_u8DigitToShow ;
		if( Copy_strt_SSDData->HAL_u8Digit == 1 )
		{
			// calculate the desired digit
			Local_u8DigitToShow = Copy_u8NumberToShow % 10 ;
		}
		else if( Copy_strt_SSDData->HAL_u8Digit == 2 )
		{
			// calculate the desired digit
			Local_u8DigitToShow = ( Copy_u8NumberToShow / 10 ) % 10 ;
		}
		else
		{
			Local_u8DigitToShow = 0 ;
			Local_u8ErrorState = 1  ;
		}

		if( Copy_strt_SSDData->HAL_u8Type == COM_CATHODE )
		{
			// send data to seven segment
			DIO_u8SetPortValue(Copy_strt_SSDData->HAL_u8SSDDataPort, HAL_COM_CATHODE_SSDNumber[Local_u8DigitToShow]);
		}
		else if( Copy_strt_SSDData->HAL_u8Type == COM_ANODE )
		{
			// send data to seven segment
			DIO_u8SetPortValue(Copy_strt_SSDData->HAL_u8SSDDataPort, HAL_COM_ANODE_SSDNumber[Local_u8DigitToShow]);
		}
		else
		{
			Local_u8ErrorState = 1 ;
		}

	}
	else
	{
		Local_u8ErrorState = 1 ;
	}

	return Local_u8ErrorState ;
}

u8 SSD_u8Initiate  ( strt_SSDConfig* Copy_strt_SSDData )
{
	u8 Local_u8ErrorState = 0 ;

	if( Copy_strt_SSDData != NULL )
	{
		//set port of 7 segment as output
		DIO_u8SetPortDirection( Copy_strt_SSDData->HAL_u8SSDDataPort, OUTPUT );
		//set enable pin as output
		DIO_u8SetPinDirection( Copy_strt_SSDData->HAL_u8SSDEnablePort, Copy_strt_SSDData->HAL_u8SSDEnablePin, OUTPUT);
		//set default states
		if( Copy_strt_SSDData->HAL_u8Type == COM_CATHODE )
		{
			//seven segment off by default
			DIO_u8SetPortValue(Copy_strt_SSDData->HAL_u8SSDDataPort, 0);
			DIO_u8SetPinValue(Copy_strt_SSDData->HAL_u8SSDEnablePort, Copy_strt_SSDData->HAL_u8SSDEnablePin, HIGH);
		}
		else if( Copy_strt_SSDData->HAL_u8Type == COM_ANODE )
		{
			//seven segment off by default
			DIO_u8SetPortValue(Copy_strt_SSDData->HAL_u8SSDDataPort, 255);
			DIO_u8SetPinValue(Copy_strt_SSDData->HAL_u8SSDEnablePort, Copy_strt_SSDData->HAL_u8SSDEnablePin, LOW);
		}
		else
		{
			Local_u8ErrorState = 1 ;
		}
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;

}


u8 SSD_u8Enable  ( strt_SSDConfig* Copy_strt_SSDData )
{
	u8 Local_u8ErrorState = 0 ;

	if( Copy_strt_SSDData->HAL_u8Type == COM_CATHODE )
	{
		//set enable pin Low
		DIO_u8SetPinValue( Copy_strt_SSDData->HAL_u8SSDEnablePort, Copy_strt_SSDData->HAL_u8SSDEnablePin, LOW);
	}
	else if( Copy_strt_SSDData->HAL_u8Type == COM_ANODE )
	{
		//set enable pin high
		DIO_u8SetPinValue( Copy_strt_SSDData->HAL_u8SSDEnablePort, Copy_strt_SSDData->HAL_u8SSDEnablePin, HIGH);
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}


	return Local_u8ErrorState ;
}


u8 SSD_u8Disable ( strt_SSDConfig* Copy_strt_SSDData )
{
	u8 Local_u8ErrorState = 0 ;

	if( Copy_strt_SSDData->HAL_u8Type == COM_CATHODE )
	{
		 //set enable pin high
		DIO_u8SetPinValue( Copy_strt_SSDData->HAL_u8SSDEnablePort, Copy_strt_SSDData->HAL_u8SSDEnablePin, HIGH);
	}
	else if( Copy_strt_SSDData->HAL_u8Type == COM_ANODE )
	{
		//set enable pin high
		DIO_u8SetPinValue( Copy_strt_SSDData->HAL_u8SSDEnablePort, Copy_strt_SSDData->HAL_u8SSDEnablePin, LOW);
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}

	return Local_u8ErrorState ;
}


u8 SSD_u8Count   ( u8 Copy_u8Start , u8 Copy_u8End , strt_SSDConfig* Copy_strt_SSDData)
{
	u8 Local_u8ErrorState = 0 ;

	return Local_u8ErrorState ;
}
