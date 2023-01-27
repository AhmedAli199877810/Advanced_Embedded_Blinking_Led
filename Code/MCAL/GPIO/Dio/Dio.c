/*******************************************************
 * FILE DESCRIPTON
*******************************************************/
/**    \file: Dio.c
 *     \breif:  Implementation of DIO DRIVER
 *
 *******************************************************/
 
/*******************************************************
  *INCLUDES
  *******************************************************/
#include "Inc/Dio.h"

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
 /******************************************
  * \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
  * \Description     : reads the value of a channel
  * \Sync\Async      : Synchronous
  * \Reentrancy      : Reentrant
  * \Parameters (in) : The required channel to be read 
  * \Parameters (out): None
  * \Return value:   : The level of the channel (High,Low)
  ****************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    uint32_t bit_mask = (ChannelId & 0xff);
    uint32_t port = ((Add_Base_Gpio)|(ChannelId >> 8));//40000000 
    if ((GPIODATA(port)&(bit_mask)) > 0)
        return 1;
    else
        return 0;
}
/*****************************************
 * \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
 * \Description     : set value to channel 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : The required channel & value of level
 * \Parameters (out): None
 * \Return value:   : None
 *****************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint32_t bit_mask = (ChannelId & 0xff);
    uint32_t port = (Add_Base_Gpio | (ChannelId >> 8));
    GPIODATA(port) = (Level << (bit_mask-1));
}

/******************************************
 * \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
 * \Description     : reads level of Port
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : The required
 * \Parameters (out): None
 * \Return value:   : The value of the Port
 ******************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    return (GPIODATA(Dio_Port_ADD(PortId)));
}
/******************************************
 * \Syntax          : void Dio_WritePort(Dio_PortLevelType PortId, Dio_PortLevelType Level)
 * \Description     : write data to Port 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : The required Port & The required level 
 * \Parameters (out): None
 * \Return value:   : None
 *  ***************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    GPIODATA(Dio_Port_ADD(PortId)) = Level;
}

/******************************************
 * \Syntax          : void Dio_FlipChannel(Dio_ChannelType ChannelId)
 * \Description     : toggle value of channel
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : The required channel  * \Parameters (out): None
 * \Return value:   : None
 ******************************************/
void Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    uint32_t port = (0x40000000 | (ChannelId >> 8));
    GPIODATA(Dio_Port_ADD(port)) ^= (ChannelId);
}

/****************************************************************************
 * END OF FILE:Dio.c
 ****************************************************************************/
