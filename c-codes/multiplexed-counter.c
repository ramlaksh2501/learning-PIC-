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
#include"C:\piclib\library-for-pic16f877a\DSP.h"//this is my own library you can able to see it in the pic library repo 
//here we use portb for data and port c's last 2 bits for selection
//we use a common cathode sevegment which is enable one at a time
void main(void) {
    while(1){
        for(int i=100;i<1000;i++){
             mux_seven(i);//increment by one
        }
}//see the function definition for more information on the function 
    return;
}