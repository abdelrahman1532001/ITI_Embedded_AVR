/**************************************************************************/
/**************************************************************************/
/****************       Author : Abdelrahman Reda      ********************/
/****************       Layer  : HAL                   ********************/
/****************       SWC    : KPD                   ********************/
/****************       Version: 1.00                  ********************/
/**************************************************************************/
/**************************************************************************/


/* preprocessor file guard */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

/****************************************
 **                                    **
 **   preprocessor configurations      **
 **   of KPD                           **
 **   This section is be set by user   **
 **                                    **
 ****************************************/

#define  KPD_u8Map    {                        \
							{'7','8','9','/'},  \
							{'4','5','6','x'}, \
							{'1','2','3','-'},  \
							{'*','0','=','+'}  \
					  }                         \


#define KPD_DATA_PORT      PORT_A

#define KPD_COLUMN0_PIN    PIN_3
#define KPD_COLUMN1_PIN    PIN_2
#define KPD_COLUMN2_PIN    PIN_1
#define KPD_COLUMN3_PIN    PIN_0

#define KPD_ROW0_PIN       PIN_7
#define KPD_ROW1_PIN	   PIN_6
#define KPD_ROW2_PIN       PIN_5
#define KPD_ROW3_PIN       PIN_4


#define NOT_PRESSED        101


#endif
