#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void my_delay_1( void )
{
   int i = 72e6/2/16;

   while( i > 0 )
     {
        i--;
        __asm__( "nop" );
     }
}

int main( void )
{
   //set STM32 to 72 MHz
   rcc_clock_setup_in_hse_8mhz_out_72mhz();
   // rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ]);
   // Enable GPIOC clock
   rcc_periph_clock_enable( RCC_GPIOC );
   //Set GPIO13 (inbuild led connected) to 'output push-pull'
   //Manually:
   // GPIOC_CRH = (GPIO_CNF_OUTPUT_PUSHPULL << (((12 - 8) * 4) + 3));
   // GPIOC_CRH |= (GPIO_MODE_OUTPUT_2_MHZ << ((12 - 8) * 4));
   /* Using API functions: */
   gpio_set_mode( GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL, GPIO13 );

   while( 1 )
     {
        gpio_toggle( GPIOC, GPIO13 );
        my_delay_1();
     }
}
