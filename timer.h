/*
 * timer.h
 *
 *  Created on: 
 *      Author: RASHAD
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"



typedef enum
{
	Normal, CTC
}Timer_Modes;


typedef enum
{
	NO_CLOCK, F_CPU_CLOCK, F_CPU_8, F_CPU_64, F_CPU_256, F_CPU_1024, Ext_Falling , Ext_Rising
}Timer_Clock;

typedef struct
{
	Timer_Modes TM;      // TM: Timer Modes Normal or CTC
	uint8 Init_Val;      // Init_Val: Initial value
	Timer_Clock TC;		 // TC: Timer Clock
	uint8 Comp_Val;      // Comp_Val: Compare Value for CTC Mode
}Timer1_Configtype;


void timer1_init(const Timer1_Configtype * Config_Ptr);
//void timer1_init(const Timer1_Configtype * Config_Ptr);
//void timer2_init(const Timer2_Configtype * Config_Ptr);

void Timer_setCallBack(void(*a_ptr)(void));

void Timer0_Stop (void);



#endif /* TIMER_H_ */
