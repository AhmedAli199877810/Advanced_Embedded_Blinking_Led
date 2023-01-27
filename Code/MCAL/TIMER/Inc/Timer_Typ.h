/*******************************************************
 * FILE DESCRIPTON
 *******************************************************/
/*Timer_Typ
 *Description  <Typedrf for Timer Driver>
 *******************************************************/

#ifndef TIMER_TYP_H
#define TIMER_TYP_H

/*******************************************************
 *INCLUDES
 *******************************************************/
#include"../../../LIBRARIES/Basic.h"

/*****************************************************
 * LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************/

/******************************************************
 * GLOBAL FUNCTION MACROS
 ******************************************************/
#define NULL 0x0
#define Add_Base_Timer 0xE000E000
#define STCTRL (*((volatile SysTimer*)((0x010)+Add_Base_Timer)))
#define STRELOAD (*((volatile uint32_t*)((0x014)+Add_Base_Timer)))

/*****************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
******************************************************/
typedef	void(*Sys_Timer)(void);
typedef struct
{
    uint32_t ENABLE : 1;
    uint32_t INTEN : 1;
    uint32_t CLK_SRC : 1;
    uint32_t RES1 : 13;
    uint32_t COUNT : 1;
    uint32_t RES2 : 15;
}SysTimer;
#endif 
/**************************************************************************************************************
 * END OF FILE:Timer_Typ.h
 **************************************************************************************************************/