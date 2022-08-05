/**************************************************************************/
/**************************************************************************/
/****************       Author : Abdelrahman Reda      ********************/
/****************       Layer  : HAL                   ********************/
/****************       SWC    : LED                   ********************/
/****************       Version: 1.00                  ********************/
/**************************************************************************/
/**************************************************************************/


#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

#define PULLUP      0
#define PULLDOWN    1
#define PRESSED     0
#define NOT_PRESSED 1

/* struct to save data of led */

typedef struct
{
	u8 HAL_u8SwitchPort ;
	u8 HAL_u8SwitchPin  ;
	u8 HAL_u8ConnectType ;          /* PULLUP OR PULLDOWN */
}strt_SwitchData;


u8 Switch_u8GetState ( strt_SwitchData* Copy_pstructSwitchData ) ;

#endif
