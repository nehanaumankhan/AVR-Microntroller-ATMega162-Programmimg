/*
 * Lab3_Q1.c
 *
 * Created: 10/02/2025 01:10:08
 * Author : Malaika Mustafa
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void) {
	DDRA = 0xFF; 
	
	while(1) {
		PORTA = 0x55;
	}
}
