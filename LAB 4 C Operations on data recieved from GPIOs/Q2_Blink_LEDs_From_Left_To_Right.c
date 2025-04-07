/* 
 * Write code to blink LEDs from left to right and then right to left  
 * using shift operators
 */

 #include <avr/io.h>
 #include <util/delay.h>
 
 int main(void) {
     DDRB = 0xFF;  // Configure Port B as output (all 8 pins)
 
     while (1) {
         // Blink LEDs from left to right (PB0 to PB7)
         uint8_t led = 0x01;  // Start with the first LED (bit 0)
         for (int i = 0; i < 8; i++) {
             PORTB = led;      // Output the current LED pattern to Port B
             _delay_ms(200);   // Wait for 200 milliseconds
             led = led << 1;   // Shift LED one bit to the left
         }
 
         // Blink LEDs from right to left (PB6 to PB0)
         led = 0x40;           // Start with the second last LED (bit 6)
         for (int i = 0; i < 7; i++) {
             PORTB = led;      // Output the current LED pattern to Port B
             _delay_ms(200);   // Wait for 200 milliseconds
             led = led >> 1;   // Shift LED one bit to the right
         }
     }
 }
 