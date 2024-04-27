 /******************************************************************************
 *
 * Module: GPIO
 *
 * Description: Source file for TivaC GPIO driver
 *
 * Author: Abdelrahman
 *
 *
 * Versions:02
 *******************************************************************************/

#include "GPIO.h"
#include "common_macros.h"
#include "tm4c123gh6pm.h"



/*
 * Description :
 * Enable and disable GPIO modules in Run mode.
 * When enabled,a module is provided a clock and accesses to module registers are allowed.
 * When disabled, the clock is disabled
 * ports are locked by default, to unlock it you will need to set a certain value to the lock register.
 */
void GPIO_portControl (uint8 port_num, GPIO_portClcStatus status ){

    switch (port_num){

     case PORTA_ID:
         if( status == portON )
         {
             SET_BIT(RCGCGPIO,GPIO_PORTA_ID)             //Enable clock to portA
             while((GET_BIT(RCGCGPIO,GPIO_PORTA_ID)) == 0){};    //The MCU take few cycles to enable the portA
             GPIOA->GPIOLOCK = 0x4C4F434B;                //portA unlock
         }
         else
         {
             RCGCGPIO &= 0xFFFFFFFE;   //Disable ClK for portA
         }
         break;

     case PORTB_ID:
         if(status==portON)
         {
             SET_BIT(RCGCGPIO,GPIO_PORTB_ID);              //Enable clock to portB
             while((GET_BIT(RCGCGPIO,GPIO_PORTB_ID)) == 0){};    //The MCU take few cycles to enable the portB
             GPIOB->GPIOLOCK = 0x4C4F434B;                //PortB unlock
         }
         else
         {
             RCGCGPIO &= 0xFFFFFFFD;   //Disable ClK for portB
         }
         break;

     case PORTC_ID:
         if(status==portON)
         {
             SET_BIT(RCGCGPIO,GPIO_PORTC_ID);                        //Enable clock to portC
             while((GET_BIT(RCGCGPIO,GPIO_PORTC_ID)) == 0){};        //The MCU take few cycles to enable the portC
             GPIOC->GPIOLOCK = 0x4C4F434B;                           //portC unlock
         }
         else
         {
             RCGCGPIO &= 0xFFFFFFFB;      //Disable ClK for portC
         }
         break;

     case PORTD_ID:
         if(status==portON)
         {
             SET_BIT(RCGCGPIO,GPIO_PORTD_ID);                        //Enable clock to portD
             while((GET_BIT(RCGCGPIO,GPIO_PORTD_ID)) == 0){};        //The MCU take few cycles to enable the portD
             GPIOD->GPIOLOCK = 0x4C4F434B;                           //portD unlock
         }
         else
         {
             RCGCGPIO &= 0xFFFFFFF7;   //Disable ClK for portD
         }
         break;

     case PORTE_ID:
          if(status==portON)
          {
             SET_BIT(RCGCGPIO,GPIO_PORTE_ID);                        //Enable clock to portE
             while((GET_BIT(RCGCGPIO,GPIO_PORTE_ID)) == 0){};        //The MCU take few cycles to enable the portE
             GPIOE->GPIOLOCK = 0x4C4F434B;                           //portE unlock
          }
          else
          {
              RCGCGPIO &= 0xFFFFFFEF;  //Disable ClK for portE
          }
          break;

     case PORTF_ID:
          if(status==portON)
          {
              SET_BIT(RCGCGPIO,GPIO_PORTF_ID);                        //Enable clock to portF
             while((GET_BIT(RCGCGPIO,GPIO_PORTF_ID)) == 0){};        //The MCU take few cycles to enable the portF
             GPIOF->GPIOLOCK = 0x4C4F434B;                           //portF unlock
          }
          else
          {
              RCGCGPIO &= 0xFFFFFFDF;  //Disable ClK for portF
          }
          break;

    }

 }





/*
 * Description :
 * Pins are locked by default, to unlock it you will need to set a certain value to the lock register.
 */
void GPIO_pinsUnlock (uint8 port_num, uint8 pin_num){

    switch (port_num){

     case PORTA_ID:
         SET_BIT(GPIOA->GPIOCR<<pin_num);
         break;

     case PORTB_ID:
         SET_BIT(GPIOB->GPIOCR<<pin_num);
         break;

     case PORTC_ID:
         SET_BIT(GPIOC->GPIOCR<<pin_num);
         break;

     case PORTD_ID:
         SET_BIT(GPIOD->GPIOCR<<pin_num);
         break;

     case PORTE_ID:
         SET_BIT(GPIOE->GPIOCR<<pin_num);
          break;

     case PORTF_ID:
         SET_BIT(GPIOF->GPIOCR<<pin_num);
          break;

    }

}



/*
 * Description :
 *  To use the pin as a digital input or output the corresponding GPIODEN bit must be set.
 *  TheGPIODENregisteristhedigitalenableregister.
 */
void GPIO_digitalPinEN (uint8 port_num, uint8 pin_num){

    switch (port_num){

     case PORTA_ID:
         SET_BIT(GPIOA->GPIODEN<<pin_num);
         break;

     case PORTB_ID:
         SET_BIT(GPIOB->GPIODEN<<pin_num);
         break;

     case PORTC_ID:
         SET_BIT(GPIOC->GPIODEN<<pin_num);
         break;

     case PORTD_ID:
         SET_BIT(GPIOD->GPIODEN<<pin_num);
         break;

     case PORTE_ID:
         SET_BIT(GPIOE->GPIODEN<<pin_num);
          break;

     case PORTF_ID:
        SET_BIT(GPIOF->GPIODEN<<pin_num);
         break;

    }

}


/*
 * Description :
 * TheGPIOPUR register is the pull-up control register. When a bit is set ,a pull-up resisto is enabled.
 * TheGPIOPDR register is the pull-down control register. When a bit is set, a pull-down resistor is enabled..
 */
void pullUp_pullDown_resistorPinCONTROL (uint8 port_num, uint8 pin_num, GPIO_pullResistorCONTROL pull   ){

    switch (port_num){

     case PORTA_ID:
         if( pull == PullUp )
         {
             SET_BIT(GPIOA->GPIOPUR<<pin_num);
         }
         else if (pull == PullDown )
         {
             SET_BIT(GPIOA->GPIOPDR<<pin_num);
         }
         else
         {
             GPIOA->GPIOPUR = 0 ;
             GPIOA->GPIOPDR = 0 ;
         }
         break;

     case PORTB_ID:
         if( pull == PullUp )
         {
             SET_BIT(GPIOB->GPIOPUR<<pin_num);
         }
         else if (pull == PullDown )
         {
             SET_BIT(GPIOB->GPIOPDR<<pin_num);
         }
         else
         {
             GPIOB->GPIOPUR = 0 ;
             GPIOB->GPIOPDR = 0 ;
         }
         break;

     case PORTC_ID:
        if( pull == PullUp )
         {
             SET_BIT(GPIOC->GPIOPUR<<pin_num);
         }
         else if (pull == PullDown )
         {
             SET_BIT(GPIOC->GPIOPDR<<pin_num);
         }
         else
         {
             GPIOC->GPIOPUR = 0 ;
             GPIOC->GPIOPDR = 0 ;
         }
         break;

     case PORTD_ID:
         if( pull == PullUp )
         {
             SET_BIT(GPIOD->GPIOPUR<<pin_num);
         }
         else if (pull == PullDown )
         {
             SET_BIT(GPIOD->GPIOPDR<<pin_num);
         }
         else
         {
             GPIOD->GPIOPUR = 0 ;
             GPIOD->GPIOPDR = 0 ;
         }
         break;

     case PORTE_ID:
         if( pull == PullUp )
         {
             SET_BIT(GPIOE->GPIOPUR<<pin_num);
         }
         else if (pull == PullDown )
         {
             SET_BIT(GPIOE->GPIOPDR<<pin_num);
         }
         else
         {
             GPIOE->GPIOPUR = 0 ;
             GPIOE->GPIOPDR = 0 ;
         }
          break;

     case PORTF_ID:
         if( pull == PullUp )
         {
             SET_BIT(GPIOF->GPIOPUR<<pin_num);
         }
         else if (pull == PullDown )
         {
             SET_BIT(GPIOF->GPIOPDR<<pin_num);
         }
         else
         {
             GPIOF->GPIOPUR = 0 ;
             GPIOF->GPIOPDR = 0 ;
         }   
          break;

    }


}



/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
    /*
     * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
     * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
     * In this case the input is not valid port/pin number
     */
    if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
    {
        /* Do Nothing */
    }
    else
    {
        /* Setup the pin direction as required */
        switch(port_num)
        {
            case PORTA_ID:
                if(direction == PIN_OUTPUT)
                {
                    SET_BIT(GPIOA->GPIODIR<<pin_num) ; //set pin (=1) >output direction
                }
                else
                {
                    CLR_BIT(GPIOA->GPIODIR<<pin_num) ; //clear pin (=0) >input direction
                }
                break;

            case PORTB_ID:
                if(direction == PIN_OUTPUT)
                {
                    SET_BIT(GPIOB->GPIODIR<<pin_num) ; //set pin (=1) >output direction
                }
                else
                {
                    CLR_BIT(GPIOB->GPIODIR<<pin_num) ; //clear pin (=0) >input direction
                }
                break;

            case PORTC_ID:
                if(direction == PIN_OUTPUT)
                {
                    SET_BIT(GPIOC->GPIODIR<<pin_num) ; //set pin (=1) >output direction
                }
                else
                {
                    CLR_BIT(GPIOC->GPIODIR<<pin_num) ; //clear pin (=0) >input direction
                }
                break;

            case PORTD_ID:
                if(direction == PIN_OUTPUT)
                {
                    SET_BIT(GPIOD->GPIODIR<<pin_num) ; //set pin (=1) >output direction
                }
                else
                {
                    CLR_BIT(GPIOD->GPIODIR<<pin_num) ; //clear pin (=0) >input direction
                }
                break;

            case PORTE_ID:
                if(direction == PIN_OUTPUT)
                {
                    SET_BIT(GPIOE->GPIODIR<<pin_num) ; //set pin (=1) >output direction
                }
                else
                {
                    CLR_BIT(GPIOE->GPIODIR<<pin_num) ; //clear pin (=0) >input direction
                }
                break;

            case PORTF_ID:
                if(direction == PIN_OUTPUT)
                {
                    SET_BIT(GPIOF->GPIODIR<<pin_num) ; //set pin (=1) >output direction
                }
                else
                {
                    CLR_BIT(GPIOF->GPIODIR<<pin_num) ; //clear pin (=0) >input direction
                }
                break;
        }
    }
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
    /*
     * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
     * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
     * In this case the input is not valid port/pin number
     */
    if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
    {
        /* Do Nothing */
    }
    else
    {
        /* Write the pin value as required */
        switch(port_num)
        {
        case PORTA_ID:
            if(value == LOGIC_HIGH)
            {
                SET_BIT(GPIOA->GPIODATA<<pin_num);
            }
            else
            {
                CLR_BIT(GPIOA->GPIODATA<<pin_num);
            }
            break;
        case PORTB_ID:
            if(value == LOGIC_HIGH)
            {
                SET_BIT(GPIOB->GPIODATA<<pin_num);
            }
            else
            {
                CLR_BIT(GPIOB->GPIODATA<<pin_num);
            }
            break;
        case PORTC_ID:
            if(value == LOGIC_HIGH)
            {
                SET_BIT(GPIOC->GPIODATA<<pin_num);
            }
            else
            {
                CLR_BIT(GPIOC->GPIODATA<<pin_num);
            }
            break;
        case PORTD_ID:
            if(value == LOGIC_HIGH)
            {
                SET_BIT(GPIOD->GPIODATA<<pin_num);
            }
            else
            {
                CLR_BIT(GPIOD->GPIODATA<<pin_num);
            }
            break;

        case PORTE_ID:
            if(value == LOGIC_HIGH)
            {
                SET_BIT(GPIOE->GPIODATA<<pin_num);
            }
            else
            {
                CLR_BIT(GPIOE->GPIODATA<<pin_num);
            }
            break;

        case PORTF_ID:
            if(value == LOGIC_HIGH)
            {
                SET_BIT(GPIOF->GPIODATA<<pin_num);
            }
            else
            {
                CLR_BIT(GPIOF->GPIODATA<<pin_num);
            }
            break;
        }
    }
}


/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)
{
    /*
     * Check if the input number is greater than NUM_OF_PORTS value.
     * In this case the input is not valid port number
     */
    if(port_num >= NUM_OF_PORTS)
    {
        /* Do Nothing */
    }
    else
    {
        /* Setup the port direction as required */
        switch(port_num)
        {
        case PORTA_ID:
            GPIOA->GPIODIR = direction;
            break;
        case PORTB_ID:
            GPIOB->GPIODIR = direction;
            break;
        case PORTC_ID:
            GPIOC->GPIODIR = direction;
            break;
        case PORTD_ID:
            GPIOD->GPIODIR = direction;
            break;

        case PORTE_ID:
            GPIOE->GPIODIR = direction;
            break;

        case PORTF_ID:
            GPIOF->GPIODIR = direction;
            break;
        }
    }
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value)
{
    /*
     * Check if the input number is greater than NUM_OF_PORTS value.
     * In this case the input is not valid port number
     */
    if(port_num >= NUM_OF_PORTS)
    {
        /* Do Nothing */
    }
    else
    {
        /* Write the port value as required */
        switch(port_num)
        {
        case PORTA_ID:
            GPIOA->GPIODATA = value;
            break;
        case PORTB_ID:
            GPIOB->GPIODATA = value;
            break;
        case PORTC_ID:
            GPIOC->GPIODATA = value;
            break;
        case PORTD_ID:
            GPIOD->GPIODATA = value;
            break;

        case PORTE_ID:
            GPIOE->GPIODATA = value;
            break;

        case PORTF_ID:
            GPIOF->GPIODATA = value;
            break;

        }
    }
}
