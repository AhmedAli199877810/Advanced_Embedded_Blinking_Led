/*******************************************************
 * FILE DESCRIPTON
*******************************************************/

/*Dio.h
 *Description  <API for Dio Driver>
 *******************************************************/

#ifndef DIO_H
#define DIO_H

/*******************************************************
 *INCLUDES
 *******************************************************/
#include "Dio_Typ.h"

/*****************************************************
 * LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************/

/******************************************************
 * GLOBAL FUNCTION PROTOTYPES
 ******************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
void Dio_FlipChannel(Dio_ChannelType ChannelId);

/***************************************
 * LOCAL FUNCTION PROTOTYPES
 ***************************************/

/*****************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 ******************************************************/
#endif
/**************************************************************************************************************
 * END OF FILE:Dio.h
 **************************************************************************************************************/
