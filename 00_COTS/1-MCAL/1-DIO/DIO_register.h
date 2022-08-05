
/**************************************************************************/
/**************************************************************************/
/****************       Author : Abdelrahman Reda      ********************/
/****************       Layer  : MCAL                  ********************/
/****************       SWC    : DIO                   ********************/
/****************       Version: 1.00                  ********************/
/**************************************************************************/
/**************************************************************************/

/* file guard */

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

/* port A addresses */
#define PORTA      *( ( volatile u8 * ) 0x3B )
#define DDRA       *( ( volatile u8 * ) 0x3A )
#define PINA       *( ( volatile u8 * ) 0x39 ) 
/* port B addresses */
#define PORTB      *( ( volatile u8 * ) 0x38 )
#define DDRB       *( ( volatile u8 * ) 0x37 )
#define PINB       *( ( volatile u8 * ) 0x36 )
/* port C addresses */
#define PORTC      *( ( volatile u8 * ) 0x35 )
#define DDRC       *( ( volatile u8 * ) 0x34 )
#define PINC       *( ( volatile u8 * ) 0x33 )
/* port D addresses */
#define PORTD      *( ( volatile u8 * ) 0x32 )
#define DDRD       *( ( volatile u8 * ) 0x31 )
#define PIND       *( ( volatile u8 * ) 0x30 )

#endif
