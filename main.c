/*
 */

#include "Header.h"
#include<util/delay.h>

int main(void)
{
  DDRB|=(1<<PB0);
  DDRB&=~(2<<PD0);
  DDRD&=~(4<<PD0);
  PORTD|=(2<<PD0);
  PORTD|=(4<<PD0);
   while(1){
     if(!(PIND&(2<<PD0)) && !(PIND&(4<<PD0))){
        PORTB|=(1<<PB0);
        _delay_ms(2000);
     }
     else{
        PORTB&=(1<<PB0);
        _delay_ms(2000);
     }
   }

    return 0;
}
