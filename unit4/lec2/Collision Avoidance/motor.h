/*
 * motor.h
 *
 *  Created on: ١٤‏/٠٧‏/٢٠٢٤
 *      Author: HP
 */

#ifndef MOTOR_H_
#define MOTOR_H_


#include "state.h"

enum{
	DC_idle,
	DC_busy
}DC_state_id;

STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();


extern void (*DC_state)();

#endif /* MOTOR_H_ */
