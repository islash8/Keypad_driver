/************************************************************************************/
/* Author  : Islam A.                                                               */
/* Date    : 11 FEB 2019                                                            */
/* Version : V01                                                                    */
/************************************************************************************/
/* Description                                                                      */
/* ------------                                                                     */
/*  This header file is used to define private macros used internally in the driver */
/************************************************************************************/


/* --------------------------------> Guard Section <------------------------------- */

#ifndef LEDMAT_PRIVATE_H_
#define LEDMAT_PRIVATE_H_

/************************************************************************************/

/* Define width of LED matrix used 												    */

#define LEDMAT_SizeOfPattern			(u8)8

/* Define macros for colors used 													*/

#define LEDMAT_COLOR_ONE				(u8)0
#define LEDMAT_COLOR_TWO				(u8)1

/* Define macros for active high and active low										*/

#define LEDMAT_ACTIVE_LOW				(u8)0
#define LEDMAT_ACTIVE_HIGH				(u8)1

/* Initial values used for ground initialization either for active high/low			*/

u8 LEDMAT_InitialGndValue_Low  = 		(u8)0xFE;
u8 LEDMAT_InitialGndValue_High = 		(u8)0x01;
/************************************************************************************/

#endif /* LEDMAT_PRIVATE_H_ */
