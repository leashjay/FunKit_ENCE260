#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include <stdbool.h>


#define PACER_RATE 500
#define MESSAGE_RATE 10

//static bool master = 0;

void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

int did_i_win(char sent_char, char received_char)
{
    int winner;
    if (sent_char == received_char) {
        winner = 0;
    } else if (sent_char == 'R' && received_char == 'S') {
        winner = 1;
    } else if (sent_char == 'P' && received_char == 'R') {
        winner = 1;
    } else if (sent_char == 'S' && received_char == 'P') {
        winner = 1;
    }   else {
        winner = 3;
    }
    return winner;
}




int main (void)
{
    char character = '*';
    char sent_char = '*';
    char received_char = '!';
    int who_won;
    bool sent = false;
    bool received = false;



    system_init ();
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    navswitch_init ();

    /* TODO: Initialise IR driver.  */
    ir_uart_init ();

    pacer_init (PACER_RATE);

    while (1) {
        pacer_wait ();
        tinygl_update ();
        navswitch_update ();

        /*scroll scren*/

        if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
            character = 'P';
        }
        if (navswitch_push_event_p (NAVSWITCH_WEST)) {
            character = 'R';
        }
        if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
            character = 'S';
        }



        /* TODO: Transmit the character over IR on a NAVSWITCH_PUSH
           event.  */
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            ir_uart_putc (character);
            sent_char = character;
            sent = true;
        }


        //while (!sent || !received) {

            display_character (character);

            if (ir_uart_read_ready_p()) {
                char buffer;
                buffer = ir_uart_getc();
                if (buffer == 'P' ||buffer == 'R'|| buffer == 'S') {
                    //character = buffer;
                    received_char = buffer;
                    received = true;

                }
            }
            if (received && sent) {
                who_won = did_i_win(sent_char, received_char);
                    if (who_won == 0) {
                        character = 'D';
                    } else if (who_won == 1) {
                        character = 'W';
                    } else {
                        character = 'L';
                    }
                display_character (character);
            }
        //}
    }

    return 0;
}
