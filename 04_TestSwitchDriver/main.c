/*
 * main.c
 *
 *  Created on: Jul 31, 2022
 *      Author: User
 */

#include "4-LIB/STD_TYPES.h"
#include <util/delay.h>
#include "1-MCAL/1-DIO/DIO_interface.h"
#include "2-HAL/LED/LED_interface.h"
#include "2-HAL/SWITCH/SWITCH_interface.h"


void main ( void )
{
	strt_LedData LED1 = {
			PORT_D,
			PIN_5,
			SOURCE
	};
	strt_LedData LED2 = {
			PORT_C,
			PIN_4,
			SINK
	};
	strt_SwitchData SW1 = {
			PORT_A,
			PIN_0,
			PULLUP
	};
	strt_SwitchData SW2 = {
			PORT_A,
			PIN_5,
			PULLDOWN
	};

	while(1)
	{
		if( Switch_u8GetState( &SW1 ) == PRESSED )
		{
			LED_u8LightOn( &LED1 ) ;
		}
		else if( Switch_u8GetState( &SW1 ) == NOT_PRESSED )
		{
			LED_u8LightOff( &LED1 ) ;
		}

		if( Switch_u8GetState( &SW2 ) == PRESSED )
		{
			LED_u8LightOn( &LED2 ) ;
		}
		else if( Switch_u8GetState( &SW2 ) == NOT_PRESSED )
		{
			LED_u8LightOff( &LED2 ) ;
		}

	}

}
