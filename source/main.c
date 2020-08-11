/*	Author: dsale010
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

#define A PINA
#define B PINB

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
    while (1) {
        unsigned char loop = 8;
        unsigned char tmpA = A;
        unsigned char tmpB = B;
        unsigned char cnt = 3;
        
        while (loop >= 0){
            if ((tmpA & 0x01) == 0x01)
                cnt++;
            
            if ((tmpB & 0x01) == 0x01)
                cnt++;
            
            tmpA = tmpA >> 1;
            tmpB = tmpB >> 1;
            loop--;
        }
        
        PORTC = cnt;

    }
    return 1;
}
