/* 
 * AVR program to read two 4-bit integers from Port A 
 * and display the greater value on Port B using LEDs 
 */

 #include <avr/io.h>

 int main(void){
     DDRA = 0x00;     // Configure Port A as input (for two 4-bit numbers)
     DDRB = 0xFF;     // Configure Port B as output (to display the greater number on LEDs)
 
     while(1){
         // Read the lower 4 bits (PA0–PA3) as the first number
         int num1 = PINA & 0x0F;
 
         // Read the upper 4 bits (PA4–PA7) as the second number
         int num2 = PINA >> 4;
 
         // Compare the two numbers and output the greater one to Port B
         if (num1 > num2) {
             PORTB = num1;   // Output num1 to Port B LEDs
         } else {
             PORTB = num2;   // Output num2 to Port B LEDs
         }
     }
 }
 