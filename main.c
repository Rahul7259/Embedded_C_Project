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

int main(void)
{
   /* Initialize Peripherals */
   peripheral_init();
   while(1){
        if(!(PIND&(2<<PD0)) && !(PIND&(4<<PD0))){
        PORTB|=(1<<PB0);
     }
     else{
       PORTB&=~(1<<PB0);
     }
   }

    return 0;
}
