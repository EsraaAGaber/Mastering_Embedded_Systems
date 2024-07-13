
#include "sensor.h"
#include "alarm.h"
const volatile int threshord_ = 20;
int main()
{
	GPIO_INITIALIZATION();
	
	while (1)
	{
		volatile unsigned int pressure = get_pressure();
		if (pressure >= threshord_)//check if the pressure reach the threshord
			{
			Alarm_On();
			Alarm_delay();
			}

			Alarm_Off();
		sensor_delay();
	}
}


