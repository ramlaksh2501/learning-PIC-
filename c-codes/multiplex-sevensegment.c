/*
 * File:   mux_seven_lib.c
 * Author: ramlaksh
 *
 * Created on 27 January, 2026, 5:53 PM
 */


#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF      // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF   
#define _XTAL_FREQ 20000000
#include <xc.h>
#include"/home/ramlaksh/learnings/pic-library/DSP.h"//this is my own library you can able to see it in the pic library repo 
//here we have used common cathode sevensegment displays
void main(void) {
    TRISB=0x00;
    TRISC&=~(0x07);
    PORTB=0;
    PORTC=0;
    while(1){mux_seven(145);}//refer the header for the function code
    return;
}
