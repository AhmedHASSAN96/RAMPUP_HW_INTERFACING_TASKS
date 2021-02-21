#include "Lcfg.h"

void USART_Init(uint32_t baudrate){
	receivedByte = 0;
	//set baud rate
	uint32_t ubrr = 6;
	UBRRH = ubrr >> 8;
	UBRRL = ubrr;
	//enable Tx and Rx
	UCSRB |= (1 << RXEN) | (1 << TXEN);
}

void USART_Transmit( uint8_t data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR = data;
}

unsigned char USART_ReceiveByte( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
	return UDR;
}

void USART_Init_IT(uint32_t baudrate){
	uint32_t ubrr = (F_CPU / 16 / baudrate) -1;
	UBRRH = ubrr >> 8;
	UBRRL = ubrr;
	
	cli();
	//enable Tx & Rx
	UCSRB |= (1 << RXEN)  | (1 << TXEN);
	//enable RxC interrupt and UDR empty interrupt
	UCSRB |= (1 << RXCIE) | (1 << UDRIE);
	
	sei();
}
