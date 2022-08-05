/*
 * main.c
 *
 *  Created on: Jul 26, 2022
 *      Author: Abdelrahman Reda
 */

#include <avr/io.h> /* library includes address of registers of avr */

void main ( void )
{
	/* make portA output */
	DDRC  = 0b11111111 ;
	/* make pin of led High */
	PORTC = 0b00000001 ;
}
