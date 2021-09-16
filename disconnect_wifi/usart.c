#include "usart.h"						/* Include USART header file */

static volatile char buffer[16];
static volatile int j = 0;

void USART_Init(unsigned int ubrr)				/* USART initialize function */
{
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);	/* Enable USART transmitter and receiver, receiver interrupt enabled */
	UCSR0C |= (3 << UCSZ00);	/* Asynchronous mode for 8 bit data and 1 stop bit */ 
	UBRR0 = ubrr;						/* Load 8 bit of prescale value */
}

char USART_RxChar()							/* Data receiving function */
{
	while (!(UCSR0A & (1 << RXC0)));					/* Wait until new data receive */
	return(UDR0);									/* Get and return received data */ 
}

void USART_TxChar(char data)						/* Data transmitting function */
{
	while ((UCSR0A & (1<<UDRE0)) == 0);					/* Wait until data transmit and buffer get empty */
	UDR0 = data;
}

void USART_SendString(char *str)					/* Send string of USART data function */ 
{
	int i=0;																	
	while (str[i]!=0)
	{
		USART_TxChar(str[i]);						/* Send each char of string till the NULL */
		i++;
	}
}

// Test ISR
ISR(USART_RX_vect)
{
    // Handle recevied character
    char ch;
    ch = UDR0;

   buffer[j] = ch;
   j++;

   // Sets null character for the last element of the buffer to prevent gibberish messages
   if (j == 15){
    buffer[15] = '\0';
    j = 0;
   }
}
