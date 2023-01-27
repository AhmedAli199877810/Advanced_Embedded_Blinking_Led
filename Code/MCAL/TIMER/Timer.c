/*******************************************************
 * FILE DESCRIPTON
*******************************************************/

/*file: Timer.c
 *breif:  Implementation of Timer DRIVER
 *
 *******************************************************/
 
/*******************************************************
  *INCLUDES
  *******************************************************/
#include "Inc/Timer.h"
#include"../../SERVICE/Timer_Cfg.h"
/***************************************
 * LOCAL MACROS CONSTANT\FUNCTION
 **************************************/

/***************************************
 * LOCAL DATA
 ***************************************/
Sys_Timer callback_ptr = NULL;
/**************************************
 * GLOBAL DATA
 *************************************/

 /***************************************
  * LOCAL FUNCTIONS
  ***************************************/

/****************************************
 * GLOBAL FUNCTIONS
 *****************************************/
 
/******************************************************************************
 * \Syntax          : void SysCtrl_Init(void)
 * \Description     : initialize Systimer
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : none
 * \Parameters (out): none
 * \Return value:   : none
 *******************************************************************************/
void SysCtrl_Init(void)
{
	STCTRL.INTEN = 1;
	STCTRL.CLK_SRC = 1;
}
 /******************************************************************************
 * \Syntax          : void SysCtrl_Start(uint32_t delay)
 * \Description     : Start Systimer
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Required Time &callbak
 * \Parameters (out): none
 * \Return value:   : none
 *******************************************************************************/
void SysCtrl_Start(uint32_t delay,Sys_Timer ptr)
{
	if (NULL != ptr)
	{
		callback_ptr = ptr;
		SysTimer_Handler();
	}
	STRELOAD = (uint32_t)((delay* Fre_quancy) - 1);
	STCTRL.ENABLE = 1;
}

void SysTimer_Handler(void)
{
	if (NULL != callback_ptr)
	{
		callback_ptr();
	}
}
/****************************************************************************
 * END OF FILE:Timer.c
 ****************************************************************************/
