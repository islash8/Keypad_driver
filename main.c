/*
 * main.c
 *
 *  Created on: Feb 16, 2019
 *      Author: islash8
 */

#include "STD_Types.h"
#include "Lib_Delay.h"

#include "DIO_Interface.h"
#include "LEDMAT_Interface.h"
#include "Keypad_Interface.h"
#define SINGLE_PIC_DELAY 10

u8 arr[4][4]={};
u8 Center[1][8] = {{60, 66, 66, 60, 24, 126, 24, 36}};

u8 rotate_right[9][8] = {
		{60, 66, 66, 60, 24, 126, 24, 36},
		{30, 33, 33, 30, 12, 63, 12, 18},
		{15, 144, 144, 15, 6, 159, 6, 9},
		{135, 72, 72, 135, 3, 207, 3, 132},
		{195, 36, 36, 195, 129, 231, 129, 66},
		{225, 18, 18, 225, 192, 243, 192, 33},
		{240, 9, 9, 240, 96, 249, 96, 144},
		{120, 132, 132, 120, 48, 252, 48, 72},
		{60, 66, 66, 60, 24, 126, 24, 36}
};

u8 sleeping[1][8] = {{0, 0, 38, 169, 121, 121, 169, 38}};

u8 up_and_down[5][8] = {
		{60, 66, 66, 60, 24, 126, 24, 36},
		{66, 66, 60, 24, 126, 24, 36, 0},
		{60, 24, 126, 24, 36, 0, 0 , 0},
		{126, 24, 36, 0, 0, 0, 0, 0},
		{36, 0, 0, 0, 0, 0, 0, 0}
};

void main (void)
{
	DIO_vInit();
	u8 Local_u8Error;
	u8 i=0,j=0;
	for (i = 0 ; i < 1 ; i++)
	{
		for (u8 j = 0 ; j < SINGLE_PIC_DELAY ; j++)
		{
			Local_u8Error = LEDMAT_SetPattern(Center[i],LEDMAT_GREEN);
		}
	}

	while(1)
	{
		Local_u8Error = Keypad_u8ReadValueu8(arr);

		// jumping
		if (arr[2][1] == KEYPAD_u8_KEY_PRESSED)
		{
			for (i = 0 ; i < 5 ; i++)
			{
				for (j = 0 ; j < 30 ; j++)
				{
					Local_u8Error = LEDMAT_SetPattern(up_and_down[i],LEDMAT_GREEN);
				}
			}
			for (i = 4 ; i != 0 ; i--)
			{
				for (j = 0 ; j < 30 ; j++)
				{
					Local_u8Error = LEDMAT_SetPattern(up_and_down[i],LEDMAT_GREEN);
				}
			}
		}

		// sleeping
		else if (arr[0][1] == KEYPAD_u8_KEY_PRESSED)
		{
			for (i = 0 ; i < 1 ; i++)
			{
				for (u8 j = 0 ; j < KEYPAD_u8_KEY_PRESSED ; j++)
				{
					Local_u8Error = LEDMAT_SetPattern(sleeping[i],LEDMAT_GREEN);
				}
			}
		}

		// rotate right
		else if (arr[1][2] == KEYPAD_u8_KEY_PRESSED)
		{
			for (i = 0 ; i < 9 ; i++)
			{
				for (j = 0 ; j < SINGLE_PIC_DELAY ; j++)
				{
					Local_u8Error = LEDMAT_SetPattern(rotate_right[i],LEDMAT_GREEN);
				}
			}
		}

		// rotate left
		else if (arr[1][0] == KEYPAD_u8_KEY_PRESSED)
		{
			for (i = 9 ; i != 0 ; i--)
			{
				for (j = 0 ; j < SINGLE_PIC_DELAY ; j++)
				{
					Local_u8Error = LEDMAT_SetPattern(rotate_right[i],LEDMAT_GREEN);
				}
			}
		}
		// center
		else
		{
			for (i = 0 ; i < 1 ; i++)
			{
				for (j = 0 ; j < SINGLE_PIC_DELAY ; j++)
				{
					Local_u8Error = LEDMAT_SetPattern(Center[i],LEDMAT_GREEN);
				}
			}
		}
	}
}
