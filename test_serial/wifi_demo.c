#include "usart.h"
#include <util/delay.h>
#include <avr/interrupt.h>

#define FOSC 7372800
#define BAUD 115200
#define MYUBRR (FOSC/16/BAUD-1)

int main(void)
{
	USART_Init(MYUBRR);	/* Initiate USART */
	sei();
	
	while(1) {
		// Use AT+GMR rather than AT to get wider response signals
		// Helpful for testing defective chips
		USART_SendString("AT+GMR\r\n");
		_delay_ms(100);
	}
}
