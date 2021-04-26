/*
 */

#include "Header.h"

void peripheral_init(void)
{
  DDRB|=(1<<PB0);//Initialize OUTPUT(LED) PIN
  DDRB&=~(2<<PD0);//Initialize switch 1 PIN
  DDRD&=~(4<<PD0);//Initialize switch 2 PIN
  PORTD|=(2<<PD0);
  PORTD|=(4<<PD0);
}
void change_led_state(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}

int main(void)
{
   /* Initialize Peripherals */
   peripheral_init();
   while(1){
     if(!(PIND&(2<<SW1_PIN)) && !(PIND&(4<<SW2_PIN))){
        change_led_state(LED_ON);
     }
     else{
       change_led_state(LED_OFF);
     }
   }

    return 0;
}
