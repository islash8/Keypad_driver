/************************************************************************************/
/* Author  : Islam A.                                                               */
/* Date    : 11 FEB 2019                                                            */
/* Version : V01                                                                    */
/************************************************************************************/
/* Description                                                                      */
/* ------------                                                                     */
/*  This header file is used to define interfaces available for external usage 		*/
/************************************************************************************/

/* --------------------------------> Guard Section <------------------------------- */

#ifndef LEDMAT_INTERFACE_H_
#define LEDMAT_INTERFACE_H_

/************************************************************************************/

/* define LED matrix colors, This is written for two color matrix (8 x 8)			*/

#define LEDMAT_RED		0
#define LEDMAT_GREEN	1

/* API definition that will be used for setting pattern of LED matrix 				*/

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

u8 LEDMAT_SetPattern (u8 * copy_Au8Pattern, u8 copy_u8Color);

/************************************************************************************/

#endif /* LEDMAT_INTERFACE_H_ */
