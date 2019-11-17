/*
 * ADC_Code_with_Library_Serial.c
 * Created: 1/17/2019 2:59:35 AM
 * Author : Christian Arevalo
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "ADC_Library.h"
#include "SerialLibrary.h"


#define F_CPU 16000000				// Set 16MHz Atmega 2560
#define BAUD 9600					// Set Baud Rate to 9600
#define BRC (F_CPU/16/BAUD-1)		// Calculation of UBRR0 (Normal Mode)

int main(void)
{
	char data[10];					// Data saved in character array.
	char data2[10];
	SerialInit(BRC);				// Initializes the serial port.
	ADCInit();					    // Initializes the ADC conversion hardware. 
	
	while (1)
	{
		int adcReadValue1 = ReadADC(1);				// Reads channel 1
		itoa(adcReadValue1, data, 10);				// Converts integer value from ADC to a String of 10 Characters.
		//dtostrf(adcReadValue,3,3,charArray);      // Converts double value from ADC to a string of characters.
		
		SerialSend(data);
		_delay_ms(2500);
		
		int adcReadValue2 = ReadADC(2);             // Reads channel 2
		itoa(adcReadValue2, data2, 10);				// Converts integer value from ADC to a String of 10 Characters.
		//dtostrf(adcReadValue,3,3,charArray);      // Converts double value from ADC to a string of characters.
		
		SerialSend(data2);
		_delay_ms(2500);
		
	}
}


