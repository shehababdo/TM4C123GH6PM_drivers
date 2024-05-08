#include "STD.h"
#include "bitmaths.h"

#include "GPIO_Interface.h"

#include "KEYPAD_Config.h"
#include "KEYPAD_Interface.h"


void Keypad_Init(void)
{
    GPIO_portControl(Keypad_Col_Port,portON);
    GPIO_portControl(Keypad_Row_Port,portON);

    GPIO_pinsUnlock(Keypad_Col_Port,Keypad_Col_0);
    GPIO_pinsUnlock(Keypad_Col_Port,Keypad_Col_1);
    GPIO_pinsUnlock(Keypad_Col_Port,Keypad_Col_2);

    GPIO_pinsUnlock(Keypad_Row_Port,Keypad_Row_0);
    GPIO_pinsUnlock(Keypad_Row_Port,Keypad_Row_1);
    GPIO_pinsUnlock(Keypad_Row_Port,Keypad_Row_2);
    GPIO_pinsUnlock(Keypad_Row_Port,Keypad_Row_3);

    GPIO_setupPinDirection(Keypad_Col_Port, Keypad_Col_0,PIN_OUTPUT);
    GPIO_setupPinDirection(Keypad_Col_Port, Keypad_Col_1,PIN_OUTPUT);
    GPIO_setupPinDirection(Keypad_Col_Port, Keypad_Col_2,PIN_OUTPUT);
 //   GPIO_setupPinDirection(Keypad_Col_Port, Keypad_Col_3,PIN_OUTPUT);


    GPIO_setupPinDirection(Keypad_Row_Port, Keypad_Row_0,PIN_INPUT);
    GPIO_setupPinDirection(Keypad_Row_Port, Keypad_Row_1,PIN_INPUT);
    GPIO_setupPinDirection(Keypad_Row_Port, Keypad_Row_2,PIN_INPUT);
    GPIO_setupPinDirection(Keypad_Row_Port, Keypad_Row_3,PIN_INPUT);


    GPIO_writePin(Keypad_Col_Port, Keypad_Col_0,LOGIC_HIGH);
    GPIO_writePin(Keypad_Col_Port, Keypad_Col_1,LOGIC_HIGH);
    GPIO_writePin(Keypad_Col_Port, Keypad_Col_2,LOGIC_HIGH);
//    GPIO_writePin(Keypad_Col_Port, Keypad_Col_3,LOGIC_HIGH);


    pullUp_pullDown_resistorPinCONTROL(Keypad_Row_Port, Keypad_Row_0,PullUp);
    pullUp_pullDown_resistorPinCONTROL(Keypad_Row_Port, Keypad_Row_1,PullUp);
    pullUp_pullDown_resistorPinCONTROL(Keypad_Row_Port, Keypad_Row_2,PullUp);
    pullUp_pullDown_resistorPinCONTROL(Keypad_Row_Port, Keypad_Row_3,PullUp);
}
uint8 Keypad_GetValue(void)
{
    uint8 i,j, val = 0;
	
	for (i = Keypad_Col_start; i <= Keypad_Col_end; i++)
	{
	    GPIO_writePin(Keypad_Col_Port, i, LOGIC_LOW);
		for (j = Keypad_Row_start; j <= Keypad_Row_end; j++)
		{
			if (Get_PinValue(Keypad_Row_Port, j) == 0)
			{
				while(Get_PinValue(Keypad_Row_Port, j) == 1);
				val = arr[j - Keypad_Row_start][i - Keypad_Col_start];
			}
		}
		GPIO_writePin(Keypad_Col_Port, i, LOGIC_HIGH);
	}
	return val;
}
