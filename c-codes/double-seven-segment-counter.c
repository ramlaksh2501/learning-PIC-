/*
 * File:   c_main.c
 * Author: ramlaksh
 *
 * Created on 12 January, 2026, 5:08 PM
 */
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF      // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 20000000
#include <xc.h>

void main(void) {
    TRISB=0x00;
    TRISC=0X00;
    
   unsigned char ss[11]={0b11111100,0b01100000,0b11011010,0b11110010,0b01100110,0b10110110,0b10111110,0b11100100,0b11111110,0b11110110,0};
   //binary for the 7-segment equivalent numbers
    while(1){unsigned char j=0;
        //begin counting 
    while(j<10){ PORTC=ss[j];
    unsigned char i=0;
    while(i<10){
    PORTB=ss[i];
    __delay_ms(500);//delay for 1 second
    i++;//move to the next number
    }
    j++;
    }
    }
    return;
}
