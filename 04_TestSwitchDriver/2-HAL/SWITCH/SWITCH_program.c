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
#include "SWITCH_interface.h"



u8 Switch_u8GetState ( strt_SwitchData* Copy_pstructSwitchData )
{
	u8 Local_u8SwtichState ;

	DIO_u8ReadPin( Copy_pstructSwitchData->HAL_u8SwitchPort, Copy_pstructSwitchData->HAL_u8SwitchPin, &Local_u8SwtichState );

	if( Copy_pstructSwitchData->HAL_u8ConnectType == PULLUP )
	{
		switch( Local_u8SwtichState )
		{
		case LOW : Local_u8SwtichState = PRESSED ; break ;
		case HIGH: Local_u8SwtichState = NOT_PRESSED ; break ;
		}
	}
	else if( Copy_pstructSwitchData->HAL_u8ConnectType == PULLDOWN )
	{
		switch( Local_u8SwtichState )
		{
		case LOW : Local_u8SwtichState = NOT_PRESSED ; break ;
		case HIGH: Local_u8SwtichState = PRESSED ; break ;
		}
	}
	return Local_u8SwtichState ;
}
