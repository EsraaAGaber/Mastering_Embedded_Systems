#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


ISR(INT0_vect) {
  PORTD|=(1<<5);
  _delay_ms(1000);
  PORTD&=~(1<<5);
}
ISR(INT1_vect) {
  PORTD|=(1<<6);
  _delay_ms(1000);
  PORTD&=~(1<<6);
}
ISR(INT2_vect) {
  PORTD|=(1<<7);
  _delay_ms(1000);
  PORTD&=~(1<<7);
}
void main()
{
    //set portD7,6,5 to be output
    DDRD |=((1<<7)|(1<<6)|(1<<5));
    DDRD &=~(1<<2);
    DDRD &=~(1<<3);
    DDRb &=~(1<<2);

    //mcu control register to aany logical change 
    MCUCR&=~(0b1111);
    MCUCR|=(0b0101);
    //int2 has only falling and raising detection
    MCUCSR&=~(1<<6);
    //enable int0,1,2 register 
    GICR |= (1 << INT0)|(1<<INT1)|(1<<INT2);
    //enable global interupt register 
    SREG|=(1<<7);
    while (1);

}