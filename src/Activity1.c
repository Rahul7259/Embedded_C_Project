#include"Activity1.h"
void DelayMilliSecond(uint32_t delay_time)
{
	uint32_t units = 0;
	for (units = 0; units <= delay_time; units++)
	{
		_delay_ms(1);
	}
}

void ChangeLEDState(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}

void SetButtonSensorPin(void)
{
	BUTTON_SENSOR_PORT |= (2 << BUTTON_SENSOR_PIN);
}

void SetHeaterSensorPin(void)
{
	HEATER_SENSOR_PORT |= (4 << HEATER_SENSOR_PIN);
}

void InitializePeripherals(void)
{
	/* Configure LED Pin */
	SET_PORTB0;//Makes first pin of PORTB as Output
    SET_PORTD; //Makes all pins of PORTD input
	SET_PD1_AND_PD2; //Pull Up
    SetButtonSensorPin();
    SetHeaterSensorPin();
}
