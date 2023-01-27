/*******************************************************
 * FILE DESCRIPTON
*******************************************************/

/*file Interrupt.c
 *breif  Represent the static part of  Interrupt controller
 *details
 *******************************************************/

 /*******************************************************
 *INCLUDES
 *******************************************************/
#include "Inc/Interrupt.h"
#include"../../SERVICE/Interrupt_Cfg.h"

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
 * LOCAL FUNCTION PROTOTYPES
 ***************************************/


/***************************************
 * LOCAL FUNCTIONS
 ***************************************/


/****************************************
 * GLOBAL FUNCTIONS
 *****************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize the riquired interrupt                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void IntCrtl_Init(void)
{
	  uint16_t i ;
	  APINT = ((0x05FA<<10)|(uint16_t)(Priorit<<8));

    for(i = 0; i < Num_Int; i++)
    {
    	uint32_t Int_Number = Conf_Interrupt[i].gates;

        uint32_t Pri_Bit_Offset = (((Int_Number % 4) * 8) + 5); 
           if (Priorit == 4)
            {
                PRIx(Int_Number / 4) |= (Conf_Interrupt[i].group_priority << (Pri_Bit_Offset));
            }
            else if(Priorit == 5) {
                PRIx(Int_Number / 4) |= (Conf_Interrupt[i].group_priority << (Pri_Bit_Offset + 1));
                PRIx(Int_Number / 4) |= (Conf_Interrupt[i].sub_group_priority << (Pri_Bit_Offset));
            }
            else if(Priorit == 6) {
                PRIx(Int_Number / 4) |= (Conf_Interrupt[i].group_priority << (Pri_Bit_Offset + 2));
                PRIx(Int_Number / 4) |= (Conf_Interrupt[i].sub_group_priority << (Pri_Bit_Offset));
            }
            else if (Priorit == 7) {
                PRIx(Int_Number / 4) |= (Conf_Interrupt[i].sub_group_priority << (Pri_Bit_Offset));
            }
    	
    }

    for(i=0; i < Num_Int; i++)
    {
        uint32_t Int_Number = Conf_Interrupt[i].gates;
        uint32_t En_Bit_Offset = (Int_Number %32) ;
    	ENx(Int_Number/4) |= ((1) << (En_Bit_Offset));
    }
}


/****************************************************************************
 * END OF FILE:Interrupt.c
 ****************************************************************************/