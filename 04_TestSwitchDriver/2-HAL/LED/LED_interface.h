/**************************************************************************/
/**************************************************************************/
/****************       Author : Abdelrahman Reda      ********************/
/****************       Layer  : HAL                   ********************/
/****************       SWC    : LED                   ********************/
/****************       Version: 1.00                  ********************/
/**************************************************************************/
/**************************************************************************/


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define SINK   0
#define SOURCE 1


/* struct to save data of led */

typedef struct
{
	u8 HAL_u8LedPort ;
	u8 HAL_u8LedPin  ;
	u8 HAL_u8ConnectType ;          /* sink or source */
}strt_LedData;


u8 LED_u8LightOn  ( strt_LedData* Copy_strLedData ) ;
u8 LED_u8LightOff ( strt_LedData* Copy_strLedData ) ;


#endif
