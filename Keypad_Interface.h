/*
 * Keypad_Interface.h
 *
 *  Created on: Feb 16, 2019
 *      Author: islash8
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define KEYPAD_u8_NO_OF_ROWS	(u8)4
#define KEYPAD_u8_NO_OF_COLUMNS	(u8)4

#define KEYPAD_u8_KEY_PRESSED	(u8)1
#define KEYPAD_u8_KEY_RELEASED	(u8)0

u8 Keypad_u8ReadValueu8(u8 (*PAu8KpdState)[KEYPAD_u8_NO_OF_ROWS]);


#endif /* KEYPAD_INTERFACE_H_ */
