/*
 * Timer.c
 *
 * Created: 13-Feb-21 2:20:16 PM
 * Author : Ahmed Hassan
 * Task   : 003  delay with timer
 */ 

#ifndef F_CPU
	#define F_CPU 1000000U
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void set_TIM1(uint16_t compareMatchValue, uint16_t prescalerValue);

int main(void)
{
	//set pins 0, 1, and 2 in port B as output pins
	DDRB  |= (1<<0) | (1<<1) | (1<<2);
	//the output of the pins is low 
	PORTB &= ~(1<<0) & ~(1<<1) & ~(1<<2);
	//call the timer1 function to start the timer --> interrupts every 1 sec
	set_TIM1(15624,64);
    /* Replace with your application code */
    while (1) 
    {
    }
}

void set_TIM1(uint16_t compareMatchValue, uint16_t prescalerValue){
	//disable global interrupts
	cli();
	//set the counter register to start counting from 0
	TCNT1 = 0;
	//set the compare match value 
	OCR1A = compareMatchValue /*0x3D08*/;
	//enable the interrupt of compare match A
	TIMSK |= 1 << OCIE1A;
	//enable global interrupts
	sei();
	//set the counter in ClearTimer on Compare match mode CTC 
	TCCR1A &= ~(1<<1) & ~(1<<0);
	TCCR1B &= ~(1<<4);
	TCCR1B |=  (1<<3);
	//set the prescaler value
	switch (prescalerValue)
	{
		case 0:
			TCCR1B &= ~(1<<2) & ~(1<<1);
			TCCR1B |= (1<<0);
			break;
		case 8:
			TCCR1B &= ~(1<<2) & ~(1<<0);
			TCCR1B |= (1<<1);
			break;
		case 64:
			TCCR1B &= ~(1<<2);
			TCCR1B |= (1<<1) | (1<<0);
			break;
		case 256:
			TCCR1B &= ~(1<<1) & ~(1<<0);
			TCCR1B |= (1<<2);
			break;
		case 1024:
			TCCR1B &= ~(1<<1);
			TCCR1B |= (1<<2) | (1<<0);
			break;
		default:
			TCCR1B &= ~(1<<2) & ~(1<<1) & ~(1<<0);
	}
}

//interrupt function
ISR(TIMER1_COMPA_vect){
	//toggle pins state
	PORTB ^= (1<<0) ^ (1<<1) ^ (1<<2);
}