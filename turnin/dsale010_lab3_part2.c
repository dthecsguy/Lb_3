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

#define inputs (PINA & 0x0F)
#define low_ind 0x40
#define B PINB

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
    while (1) {
        unsigned char tmp = inputs;
        unsigned char outtie = 0;
        
        switch (tmp){
            case 1:
            case 2: outtie = 0x20 | low_ind;
                    break;
            case 3:
            case 4: outtie = 0x30 | low_ind;
                    break;
            case 5:
            case 6: outtie = 0x38;
                    break;
            case 7:
            case 8:
            case 9: outtie = 0x3C;
                    break;
            case 10:
            case 11:
            case 12: outtie = 0x3E;
                     break;
            case 13:
            case 14:
            case 15: outtie = 0x3F;
                     break;
                
            default: outtie = 0x00;
                     break;
        }
        
        PORTC = outtie;

    }
    return 1;
}
