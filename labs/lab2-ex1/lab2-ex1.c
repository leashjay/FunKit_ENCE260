#include <avr/io.h>
#include "system.h"
#include "led.h"

//FCPU 8 bit, TIME1 = 8 x 10**6 delay = ms
#define F_CPU 8000000
#define TIMER1_PRESCALE 1024

int main (void)
{
    system_init ();
    led_init ();

    TCCR1A = 0x00;
    TCCR1B = 0x05;
    TCCR1C = 0x00;

    uint16_t ticks = 500 * (F_CPU/ TIMER1_PRESCALE)/ 1000;
    //uint16_t ticks_off = 50 * (F_CPU/ TIMER1_PRESCALE)/ 1000;

    while (1) {

        /* Turn LED on.  */
        led_set (LED1, 1);
        TCNT1 = 0;
        while (TCNT1 < ((ticks * 3) /2)) {
            continue;
        }

        /* Turn LED off.  */
        led_set (LED1, 0);

        TCNT1 = 0;
        /* TODO: wait for 500 milliseconds.  */
        while (TCNT1 < (ticks /2)) {
            continue;
        }
    }

}
