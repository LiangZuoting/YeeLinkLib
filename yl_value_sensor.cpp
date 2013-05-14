#include "yl_value_sensor.h"
#include "yl_messenger.h"

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
		if (!sock.request_post(*this, dp))
		{
			return false;
		}
		//wait for pending data, the value depends on ur network environment
		delay(1000);
		return sock.get_request_result();
	}

}
