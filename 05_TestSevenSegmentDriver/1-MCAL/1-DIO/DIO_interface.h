/**************************************************************************/
/**************************************************************************/
/****************       Author : Abdelrahman Reda      ********************/
/****************       Layer  : MCAL                  ********************/
/****************       SWC    : DIO                   ********************/
/****************       Version: 1.00                  ********************/
/**************************************************************************/
/**************************************************************************/

/* file guard */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

 enum
 {
	 LOW = 0,
	 HIGH,
	 INPUT = 0,
	 OUTPUT,
	 PIN_0 = 0,
	 PIN_1,
	 PIN_2,
	 PIN_3,
	 PIN_4,
	 PIN_5,
	 PIN_6,
	 PIN_7,
	 PORT_A = 0,
	 PORT_B,
	 PORT_C,
	 PORT_D,
 };


/*
 *  these functions return 0 when user insert false
 *  data and return 1 if everything is well .
 *
 */
u8 DIO_u8SetPinDirection ( u8 Copy_u8PortName , u8 Copy_u8PinNumber , u8 Copy_u8Direction ) ;
u8 DIO_u8SetPortDirection( u8 Copy_u8PortName , u8 Copy_u8Direction ) ;
u8 DIO_u8SetPinValue     ( u8 Copy_u8PortName , u8 Copy_u8PinNumber , u8 Copy_u8PinValue ) ;
u8 DIO_u8SetPortValue    ( u8 Copy_u8PortName , u8 Copy_u8PortValue ) ;
u8 DIO_u8ReadPin         ( u8 Copy_u8PortName , u8 Copy_u8PinNumber , u8* Copy_pu8ReadedValue ) ;
u8 DIO_u8ReadPort        ( u8 Copy_u8PortName , u8* Copy_pu8PortValue) ;


#endif
