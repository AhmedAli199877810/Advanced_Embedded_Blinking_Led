/*******************************************************
 * FILE DESCRIPTON
*******************************************************/
/**    \file: Pre_main.c
*****************************************************/
 
/*******************************************************
 *INCLUDES
 *******************************************************/
#include"Pre_main.h" 

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


/******************************************************************************
 * \Syntax          : void setup(void);
 * \Description     : this functoin set all initial sittings
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void setup(void)
{
	IntCrtl_Init();
	SysCtrl_Init();
	GPIOLOCK(Dio_Port_ADD(Dio_PORTA)) = 0x4C4F434B; //USED PORT
	GPIOCR(Dio_Port_ADD(Dio_PORTA)) = 0Xff;
	Port_Init();
}
/******************************************************************************
 * \Syntax          : void Normal_Mode(void)
 * \Description     : this functoin set normal mode
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void Normal_Mode(void)
	{
		if (On_Time != 0)
		{
			Dio_WriteChannel(Conf_Port[2].pin, Dio_High);
			On_Time--;
		}
		
		if (Off_Time != 0)
		{
			Dio_WriteChannel(Conf_Port[2].pin, Dio_Low);
			Off_Time--;
		}
			
	}
/******************************************************************************
 * \Syntax          : void Ab_Normal_Mode(void)
 * \Description     : this functoin set normal mode
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void Ab_Normal_Mode(void)
{
	uint16_t flag = 0;
	uint16_t Push = 0;
	if((GPIOMIS(Dio_Port_ADD(Dio_PORTA))&(1<<0)) ==  1)
	{
		GPIOICR(Dio_Port_ADD(Dio_PORTA)) |= 0Xff; 
			Push++ ;
	}
	else if((GPIOMIS(Dio_Port_ADD(Dio_PORTA)) & (1 << 1)) == 2 )
	{
		GPIOICR(Dio_Port_ADD(Dio_PORTA)) |= 0Xff; 
		if (flag == 0)	 
		{
			On_Time = Push; 		}
		else 
		{
			Off_Time = Push;
			flag = 0;
		}

		flag++;
		Push = 0;
	}
}
/****************************************************************************
 * END OF FILE:Pre_main.c
 ****************************************************************************/
