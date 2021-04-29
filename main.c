/*
 */

#include <avr/io.h>
#include <util/delay.h>
#include "Activity1.h"
#include "Activity2.h"
#include "Activity3.h"
#include "Activity4.h"

int main(void)
{
    initADC();
    uint16_t temp=0,temprature=0;
    InitializePeripherals();
    InitPWM();
     initUSART(103);//Initialize ports for USART
    while(1){
         if(BUTTON_SENSOR_ON && HEATER_SENSOR_ON){
                ChangeLEDState(LED_ON);
                temp=ReadADC(0);
                 temprature=GeneratePWM(temp);
                 UARTsend(temprature);//send data to UART
                 DelayMilliSecond(200);

    }
         else{
            ChangeLEDState(LED_OFF);
         }
    }
    return 0;
}
