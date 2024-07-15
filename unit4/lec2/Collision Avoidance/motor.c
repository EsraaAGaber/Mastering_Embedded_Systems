/*
 * motor.c
 *
 *  Created on: ١٤‏/٠٧‏/٢٠٢٤
 *      Author: HP
 */

#include "motor.h";
int DC_speed=0;
void (*DC_state)();

void DC_init()
{
	printf("-----DC_init------\n");
}
void DC_motor(int s){
	DC_speed = s;
	DC_state = STATE(DC_busy);
	printf("CA------>DC");
}
STATE_define(DC_idle)
{
	DC_state_id = DC_idle ;

	printf("DC_idle State\n");

}
STATE_define(DC_busy)
{
	DC_state_id = DC_busy ;

	DC_state = STATE(DC_idle);
	printf("DC_busy State \n");

}
