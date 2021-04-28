#ifndef ACTIVITY1_H_INCLUDED
#define ACTIVITY1_H_INCLUDED

#include <avr/io.h>
#include <util/delay.h>

#define LED_ON 	(0x01)			/**< LED state HIGH */
#define LED_OFF	(0x00)			/**< LED state LOW */
#define LED_PORT (PORTB)    /**< LED Port Number */
#define LED_PIN  (PORTB0)   /**< LED Pin number  */
#define BUTTON_SENSOR_PORT  (PORTD) /**< BUTTON_SENSOR Port number  */
#define HEATER_SENSOR_PORT  (PORTD) /**< HEATER_SENSOR Port number  */
#define BUTTON_SENSOR_PIN  (PORTD1) /**< BUTTON_SENSOR Pin number  */
#define HEATER_SENSOR_PIN  (PORTD2) /**< HEATER_SENSOR Pin number  */
#define BUTTON_SENSOR_ON 	!(PIND & 2<<PD0)	/**< BUTTON_SENSOR state HIGH */
#define HEATER_SENSOR_ON	!(PIND & 4<<PD0)	/**< HEATER_SENSOR state HIGH */
#define SET_PORTB0  DDRB |= (1<<PORTB0) /** PortB0 as output */
#define SET_PD1_AND_PD2  PORTD |= (4<<PORTD0)|(2<<PORTD0) /** PD1 and PD2 as pullup */
#define SET_PORTD  DDRD = 0x00 /** PortD as input */
void ChangeLEDState(uint8_t state);
void SetButtonSensorPin(void);
void SetHeaterSensorPin(void);
void InitializePeripherals(void);


#endif // ACTIVITY1_H_INCLUDED
