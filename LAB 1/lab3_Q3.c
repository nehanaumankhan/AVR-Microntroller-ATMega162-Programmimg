/*
 * Lab3_Q3.c
 *
 * Created: 10/02/2025 01:19:47
 * Author : Malaika Mustafa
 */ 
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void) {
	DDRA = 0x00; //input
	DDRB = 0xFF; //output
	int i=0;

	while(1) {
		
		if(PINA & (1 << PA0)){
			i++;
		}
		if(i==16){
			i=0;
		}
		PORTB=i;
		_delay_ms(300); // delay for 300ms
	}
}
