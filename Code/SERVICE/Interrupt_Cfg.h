/*******************************************************
 * FILE DESCRIPTON
*******************************************************/
/*Interrupt_Cfg.h
 *Description  <Congiguration for INTERRUPT Driver>
 *******************************************************/
#ifndef INTERRUPT_CFG_H
#define INTERRUPT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include"../MCAL/INTERRUPT/Inc/Interrupt_Typ.h"
 /**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*****************************************************
 * LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************/
#define Num_Int  1
/******************************************************
* GLOBAL FUNCTION PROTOTYPES
******************************************************/

/***************************************
 * LOCAL FUNCTION PROTOTYPES
 ***************************************/

/*****************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 ******************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern Priorit_value Priorit;
extern Conf_Type Conf_Interrupt[Num_Int];

#endif 
/**********************************************************************************************************************
 *  END OF FILE: Interrupt_Cfg.h
 *********************************************************************************************************************/
