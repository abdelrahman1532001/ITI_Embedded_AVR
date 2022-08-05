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


void main ( void )
{
	strt_LedData LED1 = {
			PORT_A,
			PIN_1,
			SOURCE
	};
	strt_LedData LED2 = {
			PORT_B,
			PIN_5,
			SINK
	};

	while(1)
	{
		LED_u8LightOn(&LED1) ;
		LED_u8LightOn(&LED2) ;
		_delay_ms(500);
		LED_u8LightOff(&LED1) ;
		LED_u8LightOff(&LED2) ;
		_delay_ms(500);

	}

}
