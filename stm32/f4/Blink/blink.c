#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void delay( void ) {
   
   int i = 72e6 /2 /4;
   while( i > 0 )
     {
        i--;
        __asm__( "nop" );
     }
}


int main(){
    rcc_clock_setup_in_hse_8mhz_out_72mhz();
    // set this thing to 72MHz

    gpio_set_mode(uint32_t gpioport, uint8_t mode, uint8_t cnf,
		   uint16_t gpios)
}