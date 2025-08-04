/*
 * Lab4_Q2.c
 *
 * Created: 10/02/2025 15:47:48
 * Author : Malaika Mustafa
 */

#include <avr/io.h>
#include <util/delay.h> // For _delay_ms()

#define DELAY_TIME 200 // Delay in milliseconds

int main(void)
{
    DDRB = 0xFF;  // Set PORTB as output (LEDs)
    PORTB = 0x00; // Turn off all LEDs initially

    while (1)
    {
        uint8_t pattern = 0x01; // Start with the first LED ON

        // Shift LEDs from left to right using << (bitwise shift left)
        while (pattern != 0x00) // Stop after shifting past the last LED
        {
            PORTB = pattern;
            _delay_ms(DELAY_TIME);
            pattern <<= 1; // Shift left
        }

        pattern = 0x40; // Set pattern to second-last LED (PB6) for shifting back

        // Shift LEDs from right to left using >> (bitwise shift right)
        while (pattern != 0x00) // Stop after reaching the first LED
        {
            PORTB = pattern;
            _delay_ms(DELAY_TIME);
            pattern >>= 1; // Shift right
        }
    }
}
