/*
 * SerialLibrary.h
 * Created: 1/17/2019 1:05:00 AM
 *  Author: Christian Arevalo
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>

#define F_CPU 16000000				// Define the Micro to 16MHZ
#define BAUD 9600					// Set Baud Rate to 9600
#define BRC (F_CPU/16/BAUD-1)		// Calculation of UBRR0 (Normal Mode)
#define BufferSize 128				// Limits each char[] to 128

char serialb[BufferSize];			// Character array of 128 elements.
uint8_t serialReadP = 0;				// Variable declaration.
uint8_t serialWriteP =0;				// Variable declaration.

void SerialInit(unsigned int ubrr);		// Initializes the Serial Communication.
unsigned char SerialRX(void);			// Receiving function.
void SerialTX(unsigned char data);		// Transmitting function.
void SerialSend(char* stringptr);

void SerialInit(unsigned int ubrr)		
{
	UBRR0H = (ubrr >> 8);				// Setting UBRR0H to 0b00000000 (BAUD Rate)
	UBRR0L = ubrr;					// Setting UBRR0L to 0b01100111 calculated UBRR (BAUD Rate)
	UCSR0B = 1 << RXEN0;				// Receiver Enabled
	UCSR0B = 1 << TXEN0 | 1 << TXCIE0;		// Transmitter Enabled
	UCSR0C = 1 << UCSZ01 | 1 << UCSZ00;		// Set Character Size to 8-Bit Data
	
}

void SerialSend(char* stringptr)
{
	while( *stringptr != 0x00)
	{
		SerialTX(*stringptr);
		stringptr++;
	}
}

unsigned char SerialRX(void)					// Serial Receiving Function from Computer to Microcontroller.
{
	while ( !(UCSR0A & (1 << RXC0)) )		// Wait for Data to to be received.
	;
	return UDR0;								// Returns data received as a unsigned character.
}

void SerialTX(unsigned char data)			// Serial Transmitter Function from Microcontroller to Computer.
{
	while ( !(UCSR0A & (1 << UDRE0)) )		// Wait for empty Transmit Buffer.
	;
	UDR0 = data;								// Puts Data into buffer to be sent.
	
}