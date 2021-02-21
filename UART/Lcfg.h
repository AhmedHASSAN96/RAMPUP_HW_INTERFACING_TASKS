#ifndef F_CPU
#define F_CPU 1000000U
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Det.h"

uint8_t receivedByte;
uint8_t USART_INIT_CHECK = 0;

void USART_Init(uint32_t baudrate);

void USART_Transmit( uint8_t data );

unsigned char USART_ReceiveByte( void );

void USART_Init_IT(uint32_t baudrate);