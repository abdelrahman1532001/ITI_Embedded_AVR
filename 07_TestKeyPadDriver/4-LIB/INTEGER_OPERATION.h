/*
 * INTEGER_OPERATION.h
 *
 *  Created on: Aug 19, 2022
 *      Author: User
 */

#ifndef INTEGER_OPERATION_H_
#define INTEGER_OPERATION_H_

/***********************************************************************************
 ** Description => convert integer into string to print it on LCD                 **
 ** Input       => array to hold string, array size, integer to convert it        **
 ** Output      => none                                                           **
 ***********************************************************************************/
void IntegerToString(char* Copy_pcString, u8 Copy_u8StringSize, u32 Copy_u32Integer)
{
	s8 Local_u8Iterator;
	u8 Local_u8OneDigit;

	Local_u8Iterator = Copy_u8StringSize - 1;
	Copy_pcString[Local_u8Iterator] = '\0';
	Local_u8Iterator--;

	while(Local_u8Iterator >= 0)
	{
		Local_u8OneDigit = Copy_u32Integer % 10;
		Copy_pcString[Local_u8Iterator] = Local_u8OneDigit + '0';
		Copy_u32Integer  = Copy_u32Integer / 10;
		Local_u8Iterator--;
	}//end while

}

/***********************************************************************************
 ** Description => calculate number of digit of integer positive number           **
 ** Input       => unsigned integer number                                        **
 ** Output      => number of digit                                                **
 ***********************************************************************************/
u8 CalcNumOfDigit( u32 Copy_u8Integer )
{
	u8 Copy_pu8NumOfDigit = 1;

	while( Copy_u8Integer > 9 )
	{
		Copy_pu8NumOfDigit++;
		Copy_u8Integer = Copy_u8Integer / 10 ;
	}

	return Copy_pu8NumOfDigit;
}

#endif /* INTEGER_OPERATION_H_ */
