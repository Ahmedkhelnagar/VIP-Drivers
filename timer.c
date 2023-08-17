/*
 * timer.c
 *
 *  Created on: 
 *      Author: RASHAD
 */
#include "timer.h"

static volatile void (*g_callBackPtr)(void) = NULL_PTR ;

ISR(TIMER1_COMPA_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)();
	}
}

ISR(TIMER1_OVF_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)();
	}
}


void timer1_init(const Timer1_Configtype * Config_Ptr)
{
	//Set Timer initial value to 0
	TCNT1 = (Config_Ptr -> Init_Val);
	// Non PWM mode FOC1A=1 and FOC1B=1
	TCCR1A = (1<<FOC1A) | (1<<FOC1B);
	// Configure the timer control register
	TCCR1B = (TCCR1B & 0xF7) | ((Config_Ptr->TM)<<3);
	TCCR1B = (TCCR1B & 0xF8) | (Config_Ptr->TC);

	if ((TCCR1B & 0x08) == 0x08){
		TIMSK |= (1<<OCIE1A);			   // Output Compare A Match Interrupt Enable
		OCR1A  = (Config_Ptr -> Comp_Val); // Compare Value
	}
	else{
		TIMSK |= (1<<TOIE0);               // Overflow Interrupt Enable
	}
}

void Timer_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}


void Timer0_Stop (void)
{
	TCCR0 &= 0xF8;
}
