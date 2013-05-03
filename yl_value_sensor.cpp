#include "yl_value_sensor.h"

namespace yeelink
{

	yl_value_sensor::yl_value_sensor(void)
	{
	}

	yl_value_sensor::yl_value_sensor(int id, yl_device *d)
		: yl_sensor(id, d)
	{}

	bool yl_value_sensor::post_data_point(yl_messenger &sock, const yl_data_point &dp)
	{
		return sock.post_yl_dp(*this, dp);
	}

}
