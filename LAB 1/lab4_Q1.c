/*
 * Lab4_Q1.c
 *
 * Created: 10/02/2025 01:25:01
 * Author : Malaika Mustafa
 */ 

/*
 * Lab4_Q1_Greater_Number_Display.c
 * Created: 10/02/2025
 * Author : HP
 */

#include <avr/io.h>

int main(void)
{
    // Set PORTA as input (for two 4-bit numbers)
    DDRA = 0x00;  // Configure PORTA as input
    PORTA = 0xFF; // Enable pull-up resistors (if switches are used)

    // Set PORTB as output (for LED display)
    DDRB = 0xFF;  // Configure PORTB as output

    while (1) 
    {
        // Read two numbers from PORTA
        uint8_t num1 = PINA & 0x0F;   // Lower nibble (4 bits)
        uint8_t num2 = (PINA >> 4);   // Upper nibble (4 bits)

        // Compare the numbers and display the greater one
        if (num1 > num2)
        {
            PORTB = num1;  // Display num1 on LEDs
        }
        else
        {
            PORTB = num2;  // Display num2 on LEDs
        }
    }
}

