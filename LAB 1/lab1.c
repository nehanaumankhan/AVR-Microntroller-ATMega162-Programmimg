/*
 * Lab1_LED_Blinking.c
 *
 * Created: 10/02/2025 01:00:35
 * Author : Malaika Mustafa 
 */ 

#include <avr/io.h>


#include <avr/io.h>
#define F_CPU 16000000UL
#include "util/delay.h"
int main(void)
{
	DDRB = 0xFF; //make port bas output port
	while(1){
		PORTB=0xFF;
		_delay_ms(500);
		PORTB=0x00;
		_delay_ms(500);
	}
}

