/*******************************************************
 * FILE DESCRIPTON
*******************************************************/

/*PORT_Type
 *Description  <Typedrf for PORT Driver>
 *******************************************************/

#ifndef PORT_Typ_H
#define PORT_Typ_H

/*******************************************************
 *INCLUDES
 *******************************************************/
#include "../../../../LIBRARIES/Basic.h"
#include"../../Dio/Inc/Dio_Typ.h"
/*****************************************************
 * LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************/

/*****************************************************
 * GLOBAL FUNCTION MACROS
 ******************************************************/
#define GPIODIR(x) (*((volatile uint32_t*)((x)+(0x400))))
#define GPIOAFSEL(x) (*((volatile uint32_t*)((x)+(0x420))))
#define GPIODEN(x) (*((volatile uint32_t*)((x)+(0x51C))))
#define GPIOODR(x) (*((volatile uint32_t*)((x)+(0x50C))))
#define GPIOPUR(x) (*((volatile uint32_t*)((x)+(0x510))))
#define GPIOPDR(x) (*((volatile uint32_t*)((x)+(0x514))))
#define GPIODR2R(x) (*((volatile uint32_t*)((x)+(0x500))))
#define GPIODR4R(x) (*((volatile uint32_t*)((x)+(0x504))))
#define GPIODR8R(x) (*((volatile uint32_t*)((x)+(0x508))))
#define GPIOLOCK(x) (*((volatile uint32_t*)((x)+(0x520))))
#define GPIOCR(x) (*((volatile uint32_t*)((x)+(0x524))))
#define GPIOMIS(x) (*((volatile uint32_t*)((x)+(0x418))))
#define GPIOICR(x) (*((volatile uint32_t*)((x)+(0x41C))))

 /*****************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 ******************************************************/


typedef enum
{
    Port_INPUT ,Port_OUTPUT
} Port_PinDirectionType;

typedef enum
{
    Port_OpenDrain ,Port_PullUp ,Port_PullDown
} PORT_PinInternalAttachType;

typedef enum
{
    Port_2MA,Port_4MA,Port_8MA

} PORT_PinOutputCurrentType;
typedef enum
{
    Port_Digital, Port_Analog
}
Port_PinModeType;

typedef struct
{
    Dio_ChannelType pin;
    Port_PinDirectionType direction;
    Port_PinModeType mode;
    PORT_PinInternalAttachType internal_att;
    PORT_PinOutputCurrentType current;
} Port_ConfigType;

/*****************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *****************************************************/


/*********************************************************
 * GLOBAL DATA FUNCTIONS
 **********************************************************/

#endif 

/**************************************************************************************************************
 * END OF FILE:Port_Typ.h
 **************************************************************************************************************/
