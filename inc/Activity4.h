#ifndef ACTIVITY4_H_INCLUDED
#define ACTIVITY4_H_INCLUDED


//to initialize USART
void initUSART(uint16_t ubrreg_value);

// to send the USART the modified temperature value
void UARTsend(char temp_value);



#endif // ACTIVITY4_H_INCLUDED
