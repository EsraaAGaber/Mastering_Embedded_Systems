/*
 * ca.h
 *
 *  Created on: ١٤‏/٠٧‏/٢٠٢٤
 *      Author: HP
 */

#ifndef CA_H_
#define CA_H_



#include "state.h"

enum{
	CA_waiting,
	CA_driving
}CA_state_id;
extern void US_set_distance(int d);
STATE_define(CA_waiting);
STATE_define(CA_driving);

extern void (*CA_state)();
#endif /* CA_H_ */
