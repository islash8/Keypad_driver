/************************************************************************************/
/* Author  : Islam A.                                                               */
/* Date    : 11 FEB 2019                                                            */
/* Version : V01                                                                    */
/************************************************************************************/
/* Description                                                                      */
/* ------------                                                                     */
/*  This header file is used to define configurations macros that are used for		*/
/*  for connections of LED Matrix in hardware with controller used 					*/
/*  Here in this project the controller used is ATmega32 							*/
/************************************************************************************/

/* --------------------------------> Guard Section <------------------------------- */

#ifndef LEDMAT_CONFIG_H_
#define LEDMAT_CONFIG_H_

/************************************************************************************/

/* define LED matrix type, whether it's active high or active low 					*/

#define LEDMAT_TYPE				LEDMAT_ACTIVE_LOW

/* define LED matrix common pins, where it will be connected with DIO pins			*/

#define LEDMAT_COMMON_PORT		DIO_PORTC

/* define LED Colors connection														*/

#define LEDMAT_COLOR_ONE_PORT	DIO_PORTA
#define LEDMAT_COLOR_TWO_PORT	DIO_PORTB

/************************************************************************************/

#endif /* LEDMAT_CONFIG_H_ */
