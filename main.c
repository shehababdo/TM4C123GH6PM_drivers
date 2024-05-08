
#include "GPIO_Interface.h"
#include "KEYPAD_Interface.h"
#include "GPIO_Private.h"
int main(void)
{

 /*   GPIO_portControl(GPIO_PORTF_ID,portON);
    GPIO_pinsUnlock(GPIO_PORTF_ID,2);
    GPIO_setupPinDirection(GPIO_PORTF_ID,GPIO_PIN2_ID,PIN_OUTPUT);
    GPIO_digitalPinEN(GPIO_PORTF_ID,GPIO_PIN2_ID);

    GPIO_writePin(GPIO_PORTF_ID,GPIO_PIN2_ID,LOGIC_HIGH);
    GPIO_writePin(GPIO_PORTF_ID,GPIO_PIN2_ID,LOGIC_LOW);
*/
    Keypad_Init();


    while(1)
    {
        GPIOF->GPIODATA=Keypad_GetValue();
    }

	return 0;
}
