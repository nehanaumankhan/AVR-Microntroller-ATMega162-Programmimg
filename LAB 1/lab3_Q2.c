/*
 * Lab3_Q2.c
 *
 * Created: 10/02/2025 01:17:03
 * Author : Malaika Mustafa
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void) {
	DDRA = 0xFF; 

	while(1) {
		PORTA = 0x55; 
		_delay_ms(500);
		PORTA = 0xAA;
		_delay_ms(500); 
	}
}