/*
 * Design a 4 operation (add, sub, AND, OR) calculator with the following specs:
 * Take two 3-bit operands from port A and operator from port B as input. 
 * Display result on LED Bank.
 *
 * AVR 4-operation calculator
 * - Takes two 3-bit operands from Port A (A: bits 0-2, B: bits 3-5)
 * - Takes 2-bit operation code from Port B:
 *     00 → Addition
 *     01 → Subtraction
 *     10 → AND
 *     11 → OR
 * - Displays result on PORTC (LED bank)
 */

 #include <avr/io.h>

 int main(void) {
     DDRA = 0x00;    // Port A as input (for operands)
     DDRB = 0x00;    // Port B as input (for operator selection)
     DDRC = 0xFF;    // Port C as output (for result display)
 
     int A, B, operand, output;
 
     while (1) {
         A = PINA & 0x07;              // Get operand A from bits 0–2
         B = (PINA >> 3) & 0x07;       // Get operand B from bits 3–5
         operand = PINB & 0x03;        // Get operation code from bits 0–1
 
         if (operand == 0) {
             output = A + B;           // 00 → Addition
         } 
         else if (operand == 1) {
             output = A - B;           // 01 → Subtraction
         } 
         else if (operand == 2) {
             output = A & B;           // 10 → Bitwise AND
         } 
         else {
             output = A | B;           // 11 → Bitwise OR
         }
 
         PORTC = output;               // Display result on PORTC (LEDs)
     }
 }
 