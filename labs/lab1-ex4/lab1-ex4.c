#include "button.h"
#include "led.h"
#include "system.h"


int main (void)
{
    system_init ();

    led_init ();
    button_init ();

    while (1) {
        if (button_pressed_p ()) {
            if (led_state()) {
                led_off ();
            } else {
                led_on ();
            }
        }
    }
}
