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

	// Turn on Wi-Fi mode with single connection and station mode	
	USART_SendString("AT+CWMODE=0\r\n");
	USART_SendString("AT+CIPMUX=1\r\n");
	_delay_ms(1000);
	// Connect to USC Guest Wireless
	USART_SendString("AT+CWJAP=\"USC Guest Wireless\",\"\"\r\n");	// Test the module
	while(1) {
		// Test by pinging Google
		_delay_ms(1000);
		USART_SendString("AT+PING=\"google.com\"\r\n");
	}
}
