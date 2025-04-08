/*
 * AVR code to compare A (0x0A) with a free-running counter B,
 * and glow LEDs on Port B using constant values:
 *
 * Logic:
 * - If A == B → Glow LED 0 only (0b00000001)
 * - If A != B → LED 1 must glow always
 *   - If A > B → Glow LED 1 and LED 2 (0b00000110)
 *   - If A < B → Glow LED 1 and LED 3 (0b00001010)
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    int A = 0x0A;      // Fixed value A = 10
    int B = 0x00;      // Free-running counter

    DDRB = 0xFF;       // Set Port B as output

    while (1) {
        PORTB = 0x00;  // Clear output initially

        if (A == B) {
            PORTB = 0x01;  // 0b00000001 → LED 0 ON (A == B)
        } 
        else if (A > B) {
            PORTB = 0x06;  // 0b00000110 → LED 1 and LED 2 ON (A ≠ B and A > B)
        } 
        else {
            PORTB = 0x0A;  // 0b00001010 → LED 1 and LED 3 ON (A ≠ B and A < B)
        }

        _delay_ms(500);  // Delay for visibility
        B++;             // Increment B continuously (free-running counter)
    }
}
