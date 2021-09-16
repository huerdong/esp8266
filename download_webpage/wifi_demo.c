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
	
	USART_SendString("AT+CWMODE=0\r\n");
	USART_SendString("AT+CIPMUX=1\r\n");
	//_delay_ms(2000);
	//USART_SendString("AT+CWJAP=\"USC Guest Wireless\",\"\"\r\n");	
	_delay_ms(2000);
	// Begin connection to macduff.usc.edu
	USART_SendString("AT+CIPSTART=\"TCP\",\"macduff.usc.edu\",80\r\n");
	_delay_ms(2000);
	// Begin sending data
	USART_SendString("AT+CIPSEND=64\r\n");
	_delay_ms(2000);
	// Wait for acknowledgement then send data
	USART_SendString("GET /ee459/erdong/index.html HTTP/1.1\r\nHOST: ee-classes.usc.edu\r\n\r\n");
	_delay_ms(2000);

	while(1) {
		_delay_ms(1000);
	}
}
