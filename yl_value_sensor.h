#ifndef ARDUINO_YEELINKLIB_VALUESENSOR_H
#define ARDUINO_YEELINKLIB_VALUESENSOR_H

#include "yl_sensor.h"
#include "yl_data_point.h"

namespace yeelink
{
	class yl_messenger;
	class yl_value_sensor : public yl_sensor
	{
	public:
		yl_value_sensor(void);
		yl_value_sensor(int id, yl_device *d);

		virtual bool post_data_point(yl_messenger &sock, const yl_data_point &dp);
	};
}

#endif

