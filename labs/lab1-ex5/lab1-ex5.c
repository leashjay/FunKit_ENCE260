#include "pio.h"
#include "system.h"

#define LEDMAT_COL1_PIO PC6_PIO
#define LEDMAT_COL2_PIO PB7_PIO
#define LEDMAT_COL3_PIO PC4_PIO
#define LEDMAT_COL4_PIO PC7_PIO
#define LEDMAT_COL5_PIO PC5_PIO
#define LEDMAT_COLS_NUM 5


/** LED matrix rows.  */
#define LEDMAT_ROW1_PIO PB6_PIO
#define LEDMAT_ROW2_PIO PB5_PIO
#define LEDMAT_ROW3_PIO PB4_PIO
#define LEDMAT_ROW4_PIO PB3_PIO
#define LEDMAT_ROW5_PIO PB2_PIO
#define LEDMAT_ROW6_PIO PB1_PIO
#define LEDMAT_ROW7_PIO PB0_PIO
#define LEDMAT_ROWS_NUM 7

int main (void)
{
    system_init ();

    pio_config_set (LEDMAT_ROW1_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (LEDMAT_ROW2_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (LEDMAT_ROW3_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (LEDMAT_ROW4_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (LEDMAT_ROW5_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (LEDMAT_ROW6_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (LEDMAT_ROW7_PIO, PIO_OUTPUT_HIGH);

    pio_config_set (LEDMAT_COL1_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (LEDMAT_COL2_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (LEDMAT_COL3_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (LEDMAT_COL4_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (LEDMAT_COL5_PIO, PIO_OUTPUT_HIGH);

    while (1) {
        /* uncheck to turn single LED in matric on*/
        //pio_output_low (LEDMAT_COL1_PIO);
        //pio_output_low (LEDMAT_ROW1_PIO);

        pio_output_low (LEDMAT_COL1_PIO);

        pio_output_low (LEDMAT_ROW1_PIO);
        pio_output_low (LEDMAT_ROW2_PIO);
        pio_output_low (LEDMAT_ROW3_PIO);
        pio_output_low (LEDMAT_ROW4_PIO);
        pio_output_low (LEDMAT_ROW5_PIO);
        pio_output_low (LEDMAT_ROW6_PIO);
        pio_output_low (LEDMAT_ROW7_PIO);

    }
}
