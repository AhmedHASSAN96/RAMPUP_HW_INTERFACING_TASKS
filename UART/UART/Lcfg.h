
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint8_t receivedByte;

void USART_Init(uint32_t baudrate);

void USART_Transmit( uint8_t data );

unsigned char USART_ReceiveByte( void );

void USART_Init_IT(uint32_t baudrate);