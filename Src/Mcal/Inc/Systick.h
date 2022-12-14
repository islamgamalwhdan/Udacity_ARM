/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Systick.h
 *       Module:  Systick
 *
 *  Description:  header file for Systick Module     
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_H
#define SYSTICK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Systick_cfg.h"
#include "SysCtrl.h"   // toget system clock

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	SYSTIC_FREQ_1KHZ  =    1   ,
	SYSTIC_FREQ_100HZ =    10  ,
	SYSTIC_FREQ_10HZ  =    100 ,
}Systick_FreqType ;

typedef enum 
{
	SYTICK_PIOSC_DIV4_CLK = 0 ,
	SYTICK_SYSTEM_CLK     
}Systick_ClKSourceType ;

typedef enum
{
	SYSTIC_INTERRUPT_DISABLE  = 0 ,
	SYSTIC_INTERRUPT_ENABLE
}Systick_InterruptModeType ;


typedef uint32 Systick_TicksType ;

typedef struct
{
	Systick_FreqType           TickFreq    ;
	Systick_ClKSourceType      ClockSource ;
	SysCtr_CLockType           SystemClock ;
	Systick_InterruptModeType  IntrMode    ;
}Systick_ConfigType ;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const Systick_ConfigType SystickCfg ;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Systick_Init(void) ;
void Systick_Start(Systick_TicksType Ticks) ;
void Systick_Disable(void) ;
Systick_TicksType Systick_GetTicksElapsed(void);
Systick_TicksType Systick_GetTicksRemaining(void);
 
#endif  /* SYSTICK_H */

/**********************************************************************************************************************
 *  END OF FILE: Systick.h
 *********************************************************************************************************************/
