/**************************************************************************/
/**************************************************************************/
/****************       Author : Abdelrahman Reda      ********************/
/****************       Layer  : HAL                   ********************/
/****************       SWC    : KPD                   ********************/
/****************       Version: 1.00                  ********************/
/**************************************************************************/
/**************************************************************************/

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_


/***********************************************************************************
 ** Description => get the key pressed by user                                    **
 ** Input       => pointer to hold pressed key                                    **
 ** Output      => none                                                           **
 ***********************************************************************************/
void KPD_voidGetPressedKey( u8* Copy_pu8PressedKey );

/***********************************************************************************
 ** Description => set port and pins of keypad                                    **
 ** Input       => none  					                                      **
 ** Output      => none                                                           **
 ***********************************************************************************/
void KPD_voidInit( void );




#endif