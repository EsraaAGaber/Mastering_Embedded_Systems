/*
 * main.c
 *
 * Created: 8/8/2024 1:24:09 PM
 *  Author: HP
 */ 
#include "MemMap.h"
#include "Utils.h"


int main(void)
{
	SETBIT(DDRD,4);
		SETBIT(DDRD,5);
	SETBIT(DDRD,6);
	SETBIT(DDRD,7);

    while(1)
    { volatile unsigned int i,j;
		for (i=5;i<8;i++)
		{
			PORTD|=(1<<i);
			for (j=0;j<60000;j++);
			PORTD&=~(1<<i);
		}
		PORTD|=(1<<4);
		for (j=0;j<60000;j++);

		PORTD&=~(1<<4);
		
		
    }
}