/*******************************************************
 * FILE DESCRIPTON
*******************************************************/

/*Interrupt_Typ
 *Description  <Typedef for Interrupt Driver>
 *******************************************************/

#ifndef INTERRUPT_Typ_H
#define INTERRUPT_Typ_H

 /*******************************************************
  *INCLUDES
  *******************************************************/
#include "../../../LIBRARIES/Basic.h"
  /*****************************************************
   * LOCAL MACROS CONSTANT\FUNCTION
   *****************************************************/

   /******************************************************
    * GLOBAL FUNCTION MACROS
    ******************************************************/

#define Add_Base_Interrupt 0xE000E000
#define APINT  (*((volatile uint32_t*)((Add_Base_Interrupt)+(0xD0C))))
#define PRIx(i) (*((volatile uint32_t*)(Add_Base_Interrupt+(0x0400+(i*4)))))    
#define ENx(i) (*((volatile uint32_t*)(Add_Base_Interrupt+(0x100+(i*4)))))    

    /*****************************************************
     * GLOBAL DATA TYPES AND STRUCTURES
     ******************************************************/

typedef enum
{xxx=4,xxy,xyy,yyy} Priorit_value;


typedef enum
{
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    UART_0,
    UART_1,
    SSI_0,
    I2C_0,
    PWM_0_FAULT,
    PWM_0_GEN_0,
    PWM_0_GEN_1,
    PWM_0_GEN_2,
    QEI_0,
    ADC_0_SEQ_0,
    ADC_0_SEQ_1,
    ADC_0_SEQ_2,
    ADC_0_SEQ_3,
    TIMER_WATCHDOG_0_1,
    I_16_32_TIMER_0_A,
    I_16_32_TIMER_0_B,
    I_16_32_TIMER_1_A,
    I_16_32_TIMER_1_B,
    I_16_32_TIMER_2_A,
    I_16_32_TIMER_2_B,
    ANALOG_COMPARATOR_0,
    ANALOG_COMPARATOR_1,
    SYSTEM_CONTROL = 28,
    FLASH_EEPROM_MEMORY_CONTROL,
    GPIO_PORT_F,
    UART_2 = 33,
    SSI_1,
    I_16_32_TIMER_3_A,
    I_16_32_TIMER_3_B,
    I2C_1,
    QEI_1,
    CAN_0,
    CAN_1,
    HIBERNATION = 43,
    USB,
    PWM_GEN_3,
    UDMA_SOFTWARE,
    UDMA_ERROR,
    ADC_1_SEQ_0,
    ADC_1_SEQ_1,
    ADC_1_SEQ_2,
    ADC_1_SEQ_3,
    SSI_2 = 57,
    SSI_3,
    UART_3,
    UART_4,
    UART_5,
    UART_6,
    UART_7,
    I2C_2 = 68,
    I2C_3,
    I_16_32_TIMER_4_A,
    I_16_32_TIMER_4_B,
    I_16_32_TIMER_5_A = 92,
    I_16_32_TIMER_5_B,
    I_32_64_TIMER_0_A,
    I_32_64_TIMER_0_B,
    I_32_64_TIMER_1_A,
    I_32_64_TIMER_1_B,
    I_32_64_TIMER_2_A,
    I_32_64_TIMER_2_B,
    I_32_64_TIMER_3_A,
    I_32_64_TIMER_3_B,
    I_32_64_TIMER_4_A,
    I_32_64_TIMER_4_B,
    I_32_64_TIMER_5_A,
    I_32_64_TIMER_5_B,
    SYSTEM_EXCEPTION,
    PWM_1_GEN_0 = 134,
    PWM_1_GEN_1,
    PWM_1_GEN_2,
    PWM_1_GEN_3,
    PWM_1_FAULT
} IntCtrl_InterruptsType;

typedef struct{
    IntCtrl_InterruptsType gates;
    uint32_t group_priority;
    uint32_t sub_group_priority;
} Conf_Type;

/*****************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *****************************************************/


/*********************************************************
 * GLOBAL DATA FUNCTIONS
 **********************************************************/

/************************************************************
 * END OF FILE:Interrupt_Typ.h
 **********************************************************/

#endif 

 