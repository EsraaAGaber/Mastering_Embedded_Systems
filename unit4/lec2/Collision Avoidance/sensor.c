/*
 * sensor.c
 *
 *  Created on: ١٤‏/٠٧‏/٢٠٢٤
 *      Author: HP
 */


#include "sensor.h"
#include "state.h"
unsigned int US_distance ;
void (*US_state)();

int generate_random(int l ,int r ,int count)
{
	int i ;
	for (i = 0 ; i < count ; i++)
	{
		int rand_num = (rand() % (r - l + 1)) + l;
		return rand_num ;
	}
}

void US_init()
{
	printf("US_init\n");
}


STATE_define(US_busy)
{
	US_state_id = US_busy ;
	US_distance = generate_random(45,55,1);
	printf("US_busy : distance = %d\n",US_distance);

	US_set_distance(US_distance);
	US_state = STATE(US_busy);

}
