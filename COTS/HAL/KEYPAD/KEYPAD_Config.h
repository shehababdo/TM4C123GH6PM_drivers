 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * Description: this file is for Hardware Keypad driver
 *
 * Author: Shehab Abdo
 *
 * Date: 5/8/2024
 *
 * File Name: KEYPAD_Config.h
 * Versions:01
 *******************************************************************************/

 #ifndef KEYPAD_CONFIG_H_
 #define KEYPAD_CONFIG_H_


uint8 arr[4][3] = {
					{'1', '2', '3'},
					{'4', '5', '6'},
					{'7', '8', '9'},
					{'*', '0', '#'}
				};



/*keypad (col/row) port selection*/
#define Keypad_Col_Port    GPIO_PORTD_ID
#define Keypad_Row_Port    GPIO_PORTA_ID

/*keypad column pins selection*/
#define Keypad_Col_0       GPIO_PIN0_ID
#define Keypad_Col_1       GPIO_PIN1_ID
#define Keypad_Col_2       GPIO_PIN2_ID
//#define Keypad_Col_3       GPIO_PIN0_ID

/*keypad row pins selection*/
#define Keypad_Row_0       GPIO_PIN2_ID
#define Keypad_Row_1       GPIO_PIN3_ID
#define Keypad_Row_2       GPIO_PIN4_ID
#define Keypad_Row_3       GPIO_PIN5_ID

#define Keypad_Col_start   0
#define Keypad_Col_end     2

#define Keypad_Row_start   2
#define Keypad_Row_end     5


 #endif /*KEYPAD_CONFIG_H_*/
