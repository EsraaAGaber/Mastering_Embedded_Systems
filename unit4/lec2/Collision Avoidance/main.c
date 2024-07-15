/*
 * main.c
 *
 *  Created on: ١٤‏/٠٧‏/٢٠٢٤
 *      Author: HP
 */
#include "motor.h"
#include "CA.h"
#include "sensor.h"


void setup(){
	//init the drives
	US_init();
	DC_init();
	//set the states
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}

int main(){
	volatile int d;
	setup();
	while(1){
		US_state();
		CA_state();
		DC_state();
		for(d = 0; d < 1000; ++d);//delay
	}
	return 0;
}

