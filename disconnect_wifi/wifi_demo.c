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
	
	// Assumes we have run connect_wifi demo. Disconnect and check if pings fail	
	USART_SendString("AT+CWQAP\r\n");

	while(1) {
		_delay_ms(1000);
		USART_SendString("AT+PING=\"google.com\"\r\n");

	}
}
