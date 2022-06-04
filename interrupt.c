#define F_CPU   12000000UL      //freqency
#include <avr/io.h>             //I/O declarations
#include <avr/interrupt.h>      //Interrupt declarations

int main(void)
{
    DDRC  = 0xFF;    //set DDRC as an Output
    PORTC = 0x00;   //shutdown all LED's

    DDRD  = 0x00;    //set DDRD as an Input
    PORTD = 0xFF;   //active pull-ups

    //Interrupt Register
    MCUCR |= (1 << ISC11);  //Interrupt INT1 in MCUCR(set flag)
    GICR  |= (1 << INT1);   //Interrupt INT1 set

    //global Interrupt set 
    while (1)
    {
        if (GIFR & (1 << INTF1))    //when INTF1 is zero
        {
            PORTC++;                //Output(PORTC) more than 1
            GIFR = (1 << INTF1);    //INTF1 Flag RS
        }
    }
}