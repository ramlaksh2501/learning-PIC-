;here we need to load a value to the general purpose register (here used 0x20 GPR)
;and decrement it till zero 
;and an led needs to be turned on when ever there is an even value in that particular register 
; here we use the pin B0 as the output 
;the led must be off if the register has an odd value as we decremet 
#include <xc.inc>
COUNT EQU 0x20 ;defining a GPR in the name COUNT at the address 0x20
 
; =============================
; CONFIGURATION BITS
; =============================
CONFIG  FOSC  = HS     ; High-Speed Oscillator
CONFIG  WDTE  = OFF    ; Watchdog Timer Disabled
CONFIG  PWRTE = OFF    ; Power-up Timer Disabled
CONFIG  BOREN = OFF    ; Brown-out Reset Disabled
CONFIG  LVP   = OFF    ; Low-Voltage Programming Disabled
CONFIG  CPD   = OFF    ; Data EEPROM Code Protection Disabled
CONFIG  WRT   = OFF    ; Flash Program Memory Write Disabled
CONFIG  CP    = OFF    ; Flash Program Memory Code Protection Disabled

; =============================
; RESET VECTOR (Startup)
; =============================
psect RESET_VECT, class=CODE, delta=2
RESET_VECT:
    goto setup  ; Jump to setup after reset

; =============================S
; INTERRUPT VECTOR
; =============================
psect INT_VECT, class=CODE, delta=2
INT_VECT:
    retfie      ; Return from interruptATOVLW 0xFF

; =============================
; SETUP SECTION
; =============================
setup:
 ;as the 0x20 is in the 0th bank so we are acessing the 0th bank first .so need need to change the status register
   MOVLW 0x0A;value to be moved to the general purpose register 
   MOVWF COUNT ;loading the valut into that register 
   BSF STATUS ,5;going to the 1st bank to set a pin as output to connect the led .we do that via tris register //we use portb as output here
   MOVLW 0x00;loading 0 to the trisb register
   MOVWF TRISB ;this makes all the pins in the portb as output
   BCF STATUS , 5;going back to the 0th bank 
   GOTO main;we jump to the main function 
; =============================
; MAIN PROGRAM LOOP
; =============================
main:
    BTFSS COUNT ,0;to check if the register has an odd or even number //all odd number has lsb 1
    GOTO EVEN ;this will be skipped if the number is odd // or else jump to the even function
    GOTO ODD ;jumping to the odd function
    
EVEN: BSF PORTB,0 ;making the pin B0 high (LED ON )
     GOTO  delay;going to dealy which will also decrement the value at the end 
 
ODD:BCF PORTB,;making the pin B0 low (LED OFF )
    GOTO delay;going to dealy which will also decrement the value at the end 
   
    
CHECK: DECFSZ COUNT ,1;decrementing the value at the register 
    GOTO main ;if its not zero going to main again
    GOTO NOO;if zero it will enter a infinte loop of nothing 
  NOO:
    GOTO NOO
delay:MOVLW 0xFF ;this will make a dealy for about a second at 20MHz
   ;this is jus nested for loop 
    MOVWF C1
    LOOP:
    MOVLW 0x0F
    MOVWF C2
    LPP: MOVLW 0xFF
    MOVWF C3
    LOP:DECFSZ C3
    GOTO LOP
    DECFSZ C2
    GOTO LPP
    DECFSZ C1
    GOTO LOOP  
   
   
    GOTO CHECK;here we call a check function which will decrement the register and then goto main if it is not zero
    END RESET_VECT

