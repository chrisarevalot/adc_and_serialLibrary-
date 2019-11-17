/*
 * ADC_Library.h
 * Created: 1/17/2019 1:05:28 AM
 *  Author: Christian Arevalo
 */
 
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

void ADCInit(void);
double ReadADC(unsigned int channel);

 double ReadADC(unsigned int channel)
 {
	 double adcReading = 0;
	 uint8_t low;					// Unsigned 8-bit, least significant digits of 10bit number. 
	 uint16_t tenBit;               // Unsigned 16-bit, hold the lsd and the two msd of the 10-bit adc reading. 
	 
	 switch(channel)
	 {
		 case (1):
			ADMUX |= 1 << MUX4 ;		// Setting Differential Inputs PF0 = Pos Input, PF1 = Neg Input.
			ADCSRA |= 1 << ADSC;			// Starts conversion of Analog to Digital.
			low = ADCL;					// 8-Bit variable.
			tenBit = ADCH << 2 | low >> 6;		// 16-Bit unsigned variable, to from the 10-Bit value.
			adcReading = tenBit;					// The converted value is saved to X.
			return adcReading;
		 break;
		 
		 case (2):
			ADMUX |= 1 << MUX1 | 1 << MUX4 ;		// Setting Differential Inputs PF2 = Pos Input, PF1 = Neg Input.
			ADCSRA |= 1 << ADSC;			// Starts conversion of Analog to Digital.
			low = ADCL;					// 8-Bit variable.
			tenBit = ADCH << 2 | low >> 6;		// 16-Bit unsigned variable, to from the 10-Bit value.
			adcReading = tenBit;					// The converted value is saved to X.
			return adcReading;
		 break;
		 
		 case (3):
			ADMUX |= 1 << MUX0 | 1 << MUX1 | 1 << MUX4 ;		// Setting Differential Inputs PF3 = Pos Input, PF1 = Neg Input.
			ADCSRA |= 1 << ADSC;			// Starts conversion of Analog to Digital.
			low = ADCL;					// 8-Bit variable.
			tenBit = ADCH << 2 | low >> 6;		// 16-Bit unsigned variable, to from the 10-Bit value.
			adcReading = tenBit;					// The converted value is saved to X.
			return adcReading;
		 break;
		 
		 case (4):
			ADMUX |= 1 << MUX2 | 1 << MUX4 ;		// Setting Differential Inputs PF2 = Pos Input, PF1 = Neg Input.
			ADCSRA |= 1 << ADSC;			// Starts conversion of Analog to Digital.
			low = ADCL;					// 8-Bit variable.
			tenBit = ADCH << 2 | low >> 6;		// 16-Bit unsigned variable, to from the 10-Bit value.
			adcReading = tenBit;					// The converted value is saved to X.
			return adcReading;
		 break;
		 
		 case (5):
			ADMUX |= 1 << MUX0 | 1 << MUX2 | 1 << MUX4 ;		// Setting Differential Inputs PF2 = Pos Input, PF1 = Neg Input.
			ADCSRA |= 1 << ADSC;			// Starts conversion of Analog to Digital.
			low = ADCL;			// 8-Bit variable.
			tenBit = ADCH << 2 | low >> 6;		// 16-Bit unsigned variable, to from the 10-Bit value.
			adcReading = tenBit;					// The converted value is saved to X.
			return adcReading;
		 break;
		 
		 default:								//SerialSend("No channel chosen.");
			ADCSRA |= 1 << ADSC;			// Starts conversion of Analog to Digital.
			return 0;
		 break;
		 
	 }
 }

 void ADCInit(void)
 {
	 ADCSRA |= 1 << ADPS2 | 1 << ADPS1 | 1 << ADPS0;		// Determines Prescaler of 120 (Division Factor).
	 ADMUX  |= 1 << ADLAR;									// Left Adjustment
	 ADMUX |= 1 << REFS0;									// Sets Voltage Reference to internal AVCC (AVCC connected to VCC = 5V)
	 ADMUX = 96;											// Clear Channels (ADMUX)
	 ADCSRA |= 1 << ADEN;									// ADC Enable. Initiates ADC.
 }
