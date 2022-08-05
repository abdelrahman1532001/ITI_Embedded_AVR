/*
 * main.c
 *
 *  Created on: Aug 5, 2022
 *      Author: User
 */

#include <util/delay.h>
#include "4-LIB/STD_TYPES.h"
#include "1-MCAL/1-DIO/DIO_interface.h"
#include "2-HAL/SSD/SSD_interface.h"

//SSD1 Data
#define SSD1_DATA_PORT   PORT_C
#define SSD1_ENABLE_PORT PORT_D
#define SSD1_ENABLE_PIN  PIN_1

//SSD2 Data
#define SSD2_DATA_PORT   PORT_C
#define SSD2_ENABLE_PORT PORT_D
#define SSD2_ENABLE_PIN  PIN_2

void main ( void )
{

	strt_SSDConfig SSD1 = {SSD1_ENABLE_PORT, SSD1_ENABLE_PIN, SSD1_DATA_PORT, 2, COM_CATHODE};
	strt_SSDConfig SSD2 = {SSD2_ENABLE_PORT, SSD2_ENABLE_PIN, SSD2_DATA_PORT, 1, COM_CATHODE};

	SSD_u8Initiate( &SSD1 );
	SSD_u8Initiate( &SSD2 );


	for ( u8 i = 0 ; i < 15 ; i++ )
	{
		for( u8 j = 0 ; j < 100 ; j++ )
		{
			SSD_u8Disable( &SSD2 ) ;
			SSD_u8Show( i , &SSD1 );
			SSD_u8Enable ( &SSD1 );
			_delay_ms(4);
			SSD_u8Disable( &SSD1 ) ;
			SSD_u8Show( i , &SSD2 );
			SSD_u8Enable ( &SSD2 );
			_delay_ms(4);
		}
	}
	SSD_u8Disable( &SSD1 );
	SSD_u8Disable( &SSD2 );
}

