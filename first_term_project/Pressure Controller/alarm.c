
#include "alarm.h"
//the alarm status
void Alarm_init(){
	//Initialize the alarm
	Alarm_Off();
}
void Alarm_On(){
	//set the alarm on
	Set_Alarm_actuator(ON);
}

void Alarm_Off(){
	//set the alarm off
	Set_Alarm_actuator(OFF);

}
void Alarm_delay()
{
	Delay(600000);
}
