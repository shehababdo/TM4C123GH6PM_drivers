  /******************************************************************************
  *
 * Module: GPIO
 *
 * Description: Header file for the TivaC GPIO driver
 *
 * Author: Abdelrahman
 *
 * Versions:02
 *
 *******************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "STD.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NUM_OF_PORTS                6
#define NUM_OF_PINS_PER_PORT        8
                                    
#define GPIO_PORTA_ID               0
#define GPIO_PORTB_ID               1
#define GPIO_PORTC_ID               2
#define GPIO_PORTD_ID               3
#define GPIO_PORTE_ID               4
#define GPIO_PORTF_ID               5

#define GPIO_PIN0_ID                0
#define GPIO_PIN1_ID                1
#define GPIO_PIN2_ID                2
#define GPIO_PIN3_ID                3
#define GPIO_PIN4_ID                4
#define GPIO_PIN5_ID                5
#define GPIO_PIN6_ID                6
#define GPIO_PIN7_ID                7


#define LOGIC_HIGH                  1
#define LOGIC_LOW                   0
/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
    PIN_INPUT,
    PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
    PORT_INPUT,
    PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;

typedef enum
{
    portOFF,
    portON
}GPIO_portClcStatus;


typedef enum
{
    PullUp,
    PullDown,
    
}GPIO_pullResistorCONTROL;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);


/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction);

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value);


/*
 * Description :
 * Enable and disable GPIO modules in Run mode.
 * When enabled,a module is provided a clock and accesses to module registers are allowed.
 * When disabled, the clock is disabled
 * ports are locked by default, to unlock it you will need to set a certain value to the lock register.
 */
void GPIO_portControl (uint8 port_num, GPIO_portClcStatus status );

/*
 * Description :
 * Pins are locked by default, to unlock it you will need to set a certain value to the lock register.
 */
void GPIO_pinsUnlock (uint8 port_num, uint8 pin_num);

/*
 * Description :
 *  To use the pin as a digital input or output the corresponding GPIODEN bit must be set.
 *  TheGPIODENregisteristhedigitalenableregister.
 */
void GPIO_digitalPinEN (uint8 port_num, uint8 pin_num);

/*
 * Description :
 * TheGPIOPUR register is the pull-up control register. When a bit is set ,a pull-up resisto is enabled.
 * TheGPIOPDR register is the pull-down control register. When a bit is set, a pull-down resistor is enabled..
 */
void pullUp_pullDown_resistorPinCONTROL (uint8 port_num, uint8 pin_num, GPIO_pullResistorCONTROL pull);


uint32 Get_PinValue(uint8 port_num, uint8 pin_num);

#endif /* GPIO_INTERFACE_H_ */
