/*
 * Keypad_Prog.c
 *
 *  Created on: Feb 16, 2019
 *      Author: islash8
 */
#include "STD_Types.h"

#include "DIO_Interface.h"

#include "Keypad_Private.h"
#include "Keypad_Config.h"
#include "Keypad_Interface.h"

u8 Keypad_u8ReadValueu8 (u8 (*PAu8KpdState)[KEYPAD_u8_ROW_SIZE])
{
	/*Local Variable holding the error state*/
		u8 Local_u8Error;
		u8 Local_u8KeySt;

		u8 i,j,k;

		/*checking the error possibilities of the inputs*/
		if (PAu8KpdState == NULL)
		{
			Local_u8Error = STD_ERROR_NOK;
		}
		else
		{
			if (KPD_u8_TYPE == KEYPAD_ACTIVE_LOW)
			{
				for (i = NULL ; i < KEYPAD_u8_COLUMN_SIZE ; i++)
				{
					/*firstly Setting all column pins to high to disable any key*/
					for (j = NULL ; j < KEYPAD_u8_COLUMN_SIZE ; j++)
					{
						Local_u8Error = DIO_u8SetPinValue (KPD_Au8ColumnsPins[j],DIO_u8_PIN_HIGH);
					}

					/*Setting the column you want to check as low as it is a pull up type KPD*/
					Local_u8Error = DIO_u8SetPinValue (KPD_Au8ColumnsPins[i],DIO_u8_PIN_LOW);

					/*Checking the row pins connected to this column*/
					for (k = 0 ; k < KEYPAD_u8_ROW_SIZE ; k++)
					{
						Local_u8Error = DIO_u8ReadPinValue(KPD_Au8RowsPins[k],&Local_u8KeySt);
						if (Local_u8KeySt == KEYPAD_u8_INPUT_LOW)
						{
							PAu8KpdState[i][k] = KEYPAD_u8_KEY_PRESSED;
						}
						else
						{
							PAu8KpdState[i][k] =	KEYPAD_u8_KEY_RELEASED;
						}
					}
				}
			}
			else
			{
				for (i = NULL ; i < KEYPAD_u8_COLUMN_SIZE ; i++)
				{
					/*firstly Setting all column pins to high to disable any key*/
					for (j = NULL ; j < KEYPAD_u8_COLUMN_SIZE ; j++)
					{
						Local_u8Error = DIO_u8SetPinValue (KPD_Au8ColumnsPins[j],DIO_u8_PIN_LOW);
					}

					/*Setting the column you want to check as low as it is a pull up type KPD*/
					Local_u8Error = DIO_u8SetPinValue (KPD_Au8ColumnsPins[i],DIO_u8_PIN_HIGH);

					/*Checking the row pins connected to this column*/
					for (k = 0 ; k < KEYPAD_u8_ROW_SIZE ; k++)
					{
						Local_u8Error = DIO_u8GetPinValue(KPD_Au8RowsPins[k],&Local_u8KeySt);
						if (Local_u8KeySt == KEYPAD_u8_INPUT_HIGH)
						{
							PAu8KpdState[i][k] = KEYPAD_u8_KEY_PRESSED;
						}
						else
						{
							PAu8KpdState[i][k] = KEYPAD_u8_KEY_RELEASED;
						}
					}
				}
			}
		}

		/*Function return*/
		return Local_u8Error;

}
