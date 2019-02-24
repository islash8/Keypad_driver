/************************************************************************************/
/* Author  : Islam A.                                                               */
/* Date    : 12 FEB 2019                                                            */
/* Version : V01	                                                                */
/************************************************************************************/
/* Description                                                                      */
/* ------------                                                                     */
/*  This source file is used for the implementation LED Matrix driver, provides a 	*/
/* layer of abstraction of the hardware of MCU (ATmega32) itself.                   */
/************************************************************************************/

/************************************************************************************/

/* --------------------------> Header Files <-------------------------------------- */

/**************************** STD Libraries *****************************************/

#include "STD_Types.h"
#include "Lib_Delay.h"
#include "LIB_Bit_Operations.h"

/************************************************************************************/

/**************************** DIO Libraries *****************************************/

#include "DIO_Interface.h"

/************************************************************************************/

/**************************** LED Matrix Libraries **********************************/

#include "LEDMAT_Private.h"
#include "LEDMAT_Config.h"
#include "LEDMAT_Interface.h"

/************************************************************************************/

/************************************************************************************/
/*  1. Set Matrix Pattern:															*/
/*  Description -> This API is responsible for taking the value of pattern and 		*/
/*				   color needed to be drawn with, and will set the pattern on the 	*/
/*				   LED matrix.														*/
/*  Input 		-> Array of pattern value that will be displayed (*copy_Au8Pattern) */
/*				   color to display the pattern with (copy_u8Color)					*/
/*  Output		-> Error status	(local_u8ErrorStatus)								*/
/*  note 		-> First argument to this function is an alias to the array, and 	*/
/*				   will be saved inside a pointer to u8 type.						*/
/*  Example	  	-> ErrorStatus = LEDMAT_SetPattern(myArray, LEDMAT_RED);			*/
/************************************************************************************/

u8 LEDMAT_SetPattern (u8 * copy_Au8Pattern, u8 copy_u8Color)
{
	/* Local Variables definitions and initializations								*/

	u8 local_u8ErrorState = STD_ERROR_OK;		/* Error status variable			*/
	u8 local_u8LoopCounter = NULL;				/* Loop counter variable			*/

	/* Validating inputs, whether the user entered the appropriate colors			*/

	if ((copy_u8Color != LEDMAT_GREEN) && (copy_u8Color != LEDMAT_RED))
	{
		local_u8ErrorState = STD_ERROR_NOK;
	}	/* ----> IF case on colors 													*/

	else
	{

		/* Check whether the LED Matrix is either active high or active low			*/

		if(LEDMAT_TYPE == LEDMAT_ACTIVE_LOW)
		{
			switch (copy_u8Color)
			{
			case LEDMAT_COLOR_ONE:
			/* Turn off the second color values, so it doesn't disturb the pattern */
				DIO_u8SetPortValue(LEDMAT_COLOR_TWO, STD_LOW);
			/* Writing the pattern of LEDs through looping 						   */
				for(local_u8LoopCounter = 0; local_u8LoopCounter < LEDMAT_SizeOfPattern; local_u8LoopCounter++)
				{
			/* Intialize value of Active pins on LED Matrix (Active low)   		   */
					DIO_u8SetPortValue(LEDMAT_COMMON_PORT, LEDMAT_InitialGndValue_Low);
			/* Draw the pattern using the color specified 						   */
					DIO_u8SetPortValue(LEDMAT_COLOR_ONE_PORT, *(copy_Au8Pattern + local_u8LoopCounter));
			/* Shift the enable pin to move to next row/column					   */
					LEDMAT_InitialGndValue_Low = CIRCULAR_SHIFT_LEFT(LEDMAT_InitialGndValue_Low, 1);
			/* Wait on it for 2 milli seconds									   */
					Lib_vDelayMs(2);
				}
				break;
			case LEDMAT_COLOR_TWO:
				DIO_u8SetPortValue(LEDMAT_COLOR_ONE, STD_LOW);
				for(local_u8LoopCounter = 0; local_u8LoopCounter < LEDMAT_SizeOfPattern; local_u8LoopCounter++)
				{
					DIO_u8SetPortValue(LEDMAT_COMMON_PORT, LEDMAT_InitialGndValue_Low);
					DIO_u8SetPortValue(LEDMAT_COLOR_TWO_PORT, *(copy_Au8Pattern + local_u8LoopCounter));
					LEDMAT_InitialGndValue_Low = CIRCULAR_SHIFT_LEFT(LEDMAT_InitialGndValue_Low, 1);
					Lib_vDelayMs(2);
				}
				break;
			}
		}
		else
		{
			switch (copy_u8Color)
			{
			case LEDMAT_COLOR_ONE:
				DIO_u8SetPortValue(LEDMAT_COLOR_TWO, STD_HIGH);
				for(local_u8LoopCounter = 0; local_u8LoopCounter < LEDMAT_SizeOfPattern; local_u8LoopCounter++)
				{
					DIO_u8SetPortValue(LEDMAT_COMMON_PORT, LEDMAT_InitialGndValue_High);
					DIO_u8SetPortValue(LEDMAT_COLOR_ONE_PORT, *(copy_Au8Pattern + local_u8LoopCounter));
					LEDMAT_InitialGndValue_High = CIRCULAR_SHIFT_LEFT(LEDMAT_InitialGndValue_High, 1);
					Lib_vDelayMs(2);
				}
				break;
			case LEDMAT_COLOR_TWO:
				for(local_u8LoopCounter = 0; local_u8LoopCounter < LEDMAT_SizeOfPattern; local_u8LoopCounter++)
				{
					DIO_u8SetPortValue(LEDMAT_COMMON_PORT, LEDMAT_InitialGndValue_High);
					DIO_u8SetPortValue(LEDMAT_COLOR_TWO_PORT, *(copy_Au8Pattern + local_u8LoopCounter));
					LEDMAT_InitialGndValue_High = CIRCULAR_SHIFT_LEFT(LEDMAT_InitialGndValue_High, 1);
					Lib_vDelayMs(2);
				}
				break;
			}
		}
	}

	return local_u8ErrorState;
}
