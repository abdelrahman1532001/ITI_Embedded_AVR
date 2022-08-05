/*
*
*   Bit Math Operations 
*
*/


#ifndef BitMathOpertaion_H_
#define BitMathOpertaion_H_

#define GetBit(Var, BitNumber)    ( ( Var >> BitNumber ) & 1 )
#define ClearBit(Var, BitNumber)  ( Var &= ( ~(1 << BitNumber) ) )
#define ToggleBit(Var, BitNumber) ( Var ^= ( 1 << BitNumber ) )
#define SetBit(Var, BitNumber)    ( Var |= ( 1 << BitNumber ) )

#endif
