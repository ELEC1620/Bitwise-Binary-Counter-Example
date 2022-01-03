/*  Bitwise Binary Counter Example
*  
*   Operate multiple LED outputs. Code uses bitwise operations to simplify 4-bit binary counter implementation 
*
*   Board: NUCLEO L476RG
*   Author: Dr James H. Chandler, University of Leeds 2021  
*/

#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     1000ms

//define output pins
DigitalOut led1(PC_0);      // Create DigitalOut Object called led1 and assign pin PC_0
DigitalOut led2(PC_1);
DigitalOut led3(PB_0);
DigitalOut led4(PA_4);

int val = 0;                // Create variable for use in the for loop

void init_leds();                       // Declare led initialisation function 
int led_check(int val, int index);      // Declare led_check function


int main()
{
init_leds();

    while (true) {
        
        for(val=0; val<=15; val++){

            led1.write(led_check(val, 0));
            led2.write(led_check(val, 1));
            led3.write(led_check(val, 2));
            led4.write(led_check(val, 3));
            
            ThisThread::sleep_for(BLINKING_RATE);   // Sleep for specified duration
        }
                
    }
}

void init_leds(){
    led1 = 0;
    led2 = 0;
    led3 = 0;
    led4 = 0;
}

int led_check(int val, int index){
    return((val>>index)&0x0001);
};