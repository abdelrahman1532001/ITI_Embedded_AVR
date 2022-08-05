/**************************************************************************/
/**************************************************************************/
/****************       Author : Abdelrahman Reda      ********************/
/****************       Layer  : HAL                   ********************/
/****************       SWC    : SSD                   ********************/
/****************       Version: 1.00                  ********************/
/**************************************************************************/
/**************************************************************************/


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define COM_CATHODE   0
#define COM_ANODE     1


/* struct to save data of led */

typedef struct
{
	u8 HAL_u8SSDEnablePort ; /* port of enable pin */
	u8 HAL_u8SSDEnablePin  ; /* pin of enable pin */
	u8 HAL_u8SSDDataPort ;    /* Port of Pins */
	u8 HAL_u8Digit ;
	u8 HAL_u8Type ;          /* common Anode or common cathode */
}strt_SSDConfig;


u8 SSD_u8Show      ( u8 Copy_u8NumberToShow , strt_SSDConfig* Copy_strt_SSDData ) ;
u8 SSD_u8Initiate  ( strt_SSDConfig* Copy_strt_SSDData ) ;
u8 SSD_u8Enable    ( strt_SSDConfig* Copy_strt_SSDData ) ;
u8 SSD_u8Disable   ( strt_SSDConfig* Copy_strt_SSDData ) ;
u8 SSD_u8Count     ( u8 Copy_u8Start , u8 Copy_u8End , strt_SSDConfig* Copy_strt_SSDData);

#endif
