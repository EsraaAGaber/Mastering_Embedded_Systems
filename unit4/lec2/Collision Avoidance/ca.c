/*
 * ca.c
 *
 *  Created on: ١٤‏/٠٧‏/٢٠٢٤
 *      Author: HP
 */

#include "CA.h"

int status = 0;
int CA_distance = 0;
int CA_threshold = 50;

void (*CA_state)();

void US_set_distance(int d){
	CA_distance = d;
	(CA_distance < CA_threshold)? (CA_state = STATE(CA_waiting)): (CA_state = STATE(CA_driving));
	printf("US --------distance=%d---------> CA\n",CA_distance);
}


STATE_define(CA_waiting)
{

	CA_state_id = CA_waiting;
	printf("CA_WAiting State: distance = %d and motor is off \n",CA_distance);

	status = 0;
	DC_motor(status);
}

STATE_define(CA_driving){
	// State Name
	CA_state_id = CA_driving;

	printf("CA_driving State: distance = %d and motor is on\n",CA_distance);
	// State_Action
	status =1 ;
	DC_motor(status);
}
