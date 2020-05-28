/*
         program to control a led using a switch
*/

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

int main(void)
{
	uint8_t pushButton = 0;
	DDRB  &= ~(1<<PB0);  // configure pin 0 of PORTB as input pin
	PORTB |= (1<<PB0);   // internal pull-up resistor activation of PB0
	
	DDRC |= (1<<PC0);    // configure pin 0 of PORTC as output pin
	PORTC|= (1<<PC0);    // led is initially off - negative logic configuration

    for(;;)
    {
		// check if the switch is pressed
		if(!(PINB & (1<<PB0)))
		{
			_delay_ms(30); // delay for bouncing effect
			if(!(PINB & (1<<PB0)))
			{
				if(pushButton == 0)
				{
					PORTC ^= (1<<PC0); // toggle the led
					pushButton = 1;
				}
			}
		}
		else
		{
            pushButton = 0;
		} 
    }
}
