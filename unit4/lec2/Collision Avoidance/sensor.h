/*
 * sensor.h
 *
 *  Created on: ١٤‏/٠٧‏/٢٠٢٤
 *      Author: HP
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include "state.h"

enum{
	US_busy
}US_state_id;

STATE_define(US_busy);
extern void US_set_distance(int d);


void US_init();
extern void (*US_state)();
#endif /* SENSOR_H_ */
