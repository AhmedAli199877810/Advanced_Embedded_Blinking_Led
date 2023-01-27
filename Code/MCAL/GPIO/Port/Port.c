/*******************************************************
 * FILE DESCRIPTON
*******************************************************/
/*file: Port.c
 *breif:  Implementation of Port DRIVER
 *******************************************************/

 /*******************************************************
  *INCLUDES
  *******************************************************/
#include"Inc/Port.h"
 /***************************************
  * LOCAL MACROS CONSTANT\FUNCTION
  **************************************/

 /***************************************
  * LOCAL DATA
  ***************************************/

 /**************************************
  * GLOBAL DATA
  *************************************/

 /***************************************
  * LOCAL FUNCTIONS
  ***************************************/

 /****************************************
  * GLOBAL FUNCTIONS
  *****************************************/
        
 
/*******************************************
 * \Syntax          : void Port_Init()
 * \Description     : Settting direction,alternate and current
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 ********************************************/
void Port_Init()
{

    for (uint16_t i = 0; i < Num_Pins; i++)
    {
        uint32_t bit_mask = (Conf_Port[i].pin & 0xf);
        uint32_t port = (Add_Base_Gpio | (Conf_Port[i].pin >> 8));
        switch (Conf_Port[i].direction)
        {
        case Port_INPUT:
            GPIODIR(port) &= ~(1 << bit_mask);
            break;
        case Port_OUTPUT:
            GPIODIR(port) |= (1 << (bit_mask-1));
            break;
        }
        
        switch (Conf_Port[i].mode)
        {
        case Port_Digital: 
            GPIOAFSEL(port) &= ~(1 << bit_mask);
            GPIODEN(port) |= (1 << (bit_mask-1));
            break;
        //case Port_Digital:  TO DO ANALOG

        }

        switch (Conf_Port[i].internal_att)
        {
        case  Port_OpenDrain:
            GPIOODR(port) |= (1 << (bit_mask - 1));
            break;
        case Port_PullUp:
            GPIOPUR(port) |= (1 << (bit_mask - 1));
            break;
        case Port_PullDown:
            GPIOPDR(port) |= (1 << (bit_mask-1));
            break;
        }

        switch (Conf_Port[i].current)
        {
        case  Port_2MA:
            GPIODR2R(port) |= (1 << (bit_mask - 1));
            break;
        case Port_4MA:
            GPIODR4R(port) |= (1 << (bit_mask - 1));
            break;
        case Port_8MA:
            GPIODR8R(port) |= (1 << (bit_mask - 1));
            break;
        }
    }
}
/****************************************************************************
 * END OF FILE:Port.c
 ****************************************************************************/
