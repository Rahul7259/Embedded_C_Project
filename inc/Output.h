#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED
#define LED_ON (0x01)
#define LED_OFF (0x00)
#include<avr/io.h>

void change_led_state(uint8_t state);

#endif // OUTPUT_H_INCLUDED
