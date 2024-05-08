 /******************************************************************************
  *
 * Module: GPIO
 *
 * Description: Private file for the TivaC GPIO driver
 *
 * File Name : GPIO_Private.h
 *
 * Author: Shehab Abdo
 *
 *******************************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/********************************BASE ADDRESSES**********************************/
#define GPIO_PORTA_BASE_ADDRESS         0x40004000
#define GPIO_PORTB_BASE_ADDRESS         0x40005000
#define GPIO_PORTC_BASE_ADDRESS         0x40006000
#define GPIO_PORTD_BASE_ADDRESS         0x40007000
#define GPIO_PORTE_BASE_ADDRESS         0x40024000
#define GPIO_PORTF_BASE_ADDRESS         0x40025000

#define RCGCGPIO                        *((volatile uint32 *)(0x400FE000 +0x608))       /*General-Purpose Input/Output Run Mode Clock Gating Control*/

#define GPIOLOCKA *((volatile uint32 *)(0x40004000+0x520))
#define GPIOLOCKB *((volatile uint32 *)(0x40005000+0x520))
#define GPIOLOCKC *((volatile uint32 *)(0x40006000+0x520))
#define GPIOLOCKD *((volatile uint32 *)(0x40007000+0x520))
#define GPIOLOCKE *((volatile uint32 *)(0x40024000+0x520))
#define GPIOLOCKF *((volatile uint32 *)(0x40025000+0x520))

typedef struct
{
    uint32 reserved0 [255];
    uint32 GPIODATA;
    uint32 GPIODIR;
    uint32 GPIOIS;
    uint32 GPIOIBE;
    uint32 GPIOIEV;
    uint32 GPIOIM;
    uint32 GPIORIS;
    uint32 GPIOMIS;
    uint32 GPIOICR;
    uint32 GPIOAFSEL;
    uint32 reserved1 [55];
    uint32 GPIODR2R;
    uint32 GPIODR4R;
    uint32 GPIODR8R;
    uint32 GPIOODR;
    uint32 GPIOPUR;
    uint32 GPIOPDR;
    uint32 GPIOSLR;
    uint32 GPIODEN;
    uint32 GPIOLOCK;
    uint32 GPIOCR;
    uint32 GPIOAMSEL;
    uint32 GPIOPCTL;
    uint32 GPIOADCCTL;
    uint32 GPIODMACTL;
    uint32 reserved2 [678];
    uint32 GPIOPeriphID4;
    uint32 GPIOPeriphID5;
    uint32 GPIOPeriphID6;
    uint32 GPIOPeriphID7;
    uint32 GPIOPeriphID0;
    uint32 GPIOPeriphID1;
    uint32 GPIOPeriphID2;
    uint32 GPIOPeriphID3;
    uint32 GPIOPCellID0;
    uint32 GPIOPCellID1;
    uint32 GPIOPCellID2;
    uint32 GPIOPCellID3;

}GPIO_Reg_t;


#define GPIOA       ((volatile GPIO_Reg_t*)GPIO_PORTA_BASE_ADDRESS)
#define GPIOB       ((volatile GPIO_Reg_t*)GPIO_PORTB_BASE_ADDRESS)
#define GPIOC       ((volatile GPIO_Reg_t*)GPIO_PORTC_BASE_ADDRESS)
#define GPIOD       ((volatile GPIO_Reg_t*)GPIO_PORTD_BASE_ADDRESS)
#define GPIOE       ((volatile GPIO_Reg_t*)GPIO_PORTE_BASE_ADDRESS)
#define GPIOF       ((volatile GPIO_Reg_t*)GPIO_PORTF_BASE_ADDRESS)
#endif /*GPIO_PRIVATE_H_*/
