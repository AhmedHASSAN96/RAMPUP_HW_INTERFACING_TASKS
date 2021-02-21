/*
 * UART.c
 *
 * Created: 16-Feb-21 2:49:57 PM
 * Author : Ahmed Hassan
 */ 

#include "Lcfg.h"

uint8_t data = 'a';
extern uint8_t receivedByte;

int main(void)
{
	DDRB = 0xFF;
	USART_Init(9600);
    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR(USART_RXC_vect){
	receivedByte = UDR;
}

ISR(USART_UDRE_vect){
	UDR = data;
}