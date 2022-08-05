/*
 * main.c
 *
 *  Created on: Jul 30, 2022
 *      Author: User
 */



#include "4-LIB/STD_TYPES.h"

#include "1-MCAL/1-DIO/DIO_interface.h"

void main ( void )
{
	/*variable*/
	u8 Local_u8ButtonState, Local_u8PortValue ;

	/* active pull up for port B */
	DIO_u8SetPortDirection(PORT_B, INPUT);
	DIO_u8SetPortValue(PORT_B, 255);

	/* set pin of led */
	DIO_u8SetPinDirection( PORT_A, PIN_1, OUTPUT);
	DIO_u8SetPinValue(PORT_A, PIN_5, LOW);

	/* set port C */
	DIO_u8SetPortDirection(PORT_C, OUTPUT);
	DIO_u8SetPortValue(PORT_C, 0);

	while( DIO_u8ReadPin( PORT_B, PIN_5, &Local_u8ButtonState ) )
	{
		switch( Local_u8ButtonState )
		{
		case LOW : DIO_u8SetPinValue(PORT_A, PIN_1, HIGH); break;
		case HIGH: DIO_u8SetPinValue(PORT_A, PIN_1, LOW); break;
		}//end switch
		/* read port B */
		DIO_u8ReadPort(PORT_B, &Local_u8PortValue);
		/* set port C as port B */
		DIO_u8SetPortValue(PORT_C, Local_u8PortValue);
	}//end while loop
}//end main
