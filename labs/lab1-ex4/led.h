#ifndef LED_H
#define LED_H

/** Turn LED1 on.  */
void led_on (void);


/** Turn LED1 off.  */
void led_off (void);

/** return LED state 1=on 0=off  */
_Bool led_state(void);

/** Initialise LED1.  */
void led_init (void);
#endif
