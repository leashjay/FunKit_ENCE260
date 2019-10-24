#include "pio.h"
#include "led.h"

#define LED_PIO PIO_DEFINE (PORT_C, 2)
/** Turn LED1 on.  */
void led_on (void)
{
    pio_output_high (LED_PIO);
}


/** Turn LED1 off.  */
void led_off (void)
{
    pio_output_low (LED_PIO);
}

/** return LED state 1=on 0=off  */
_Bool led_state()
{
    int state;

    if (pio_output_get(LED_PIO)) {
        state = 1;
    } else {
        state = 0;
    }
    return state;
}


/** Initialise LED1.  */
void led_init (void)
{
    pio_config_set(LED_PIO, PIO_OUTPUT_LOW);
}
