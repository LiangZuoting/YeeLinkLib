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

	bool yl_value_sensor::post(yl_messenger &sock, const yl_data_point &dp, bool keep_alive)
	{
		if (!sock.request_post(*this, dp, keep_alive))
		{
			return false;
		}
		//wait for pending data, the value depends on ur network environment
		delay(1000);
		return sock.get_request_result();
	}

	bool yl_value_sensor::get(yl_messenger &sock, yl_data_point &dp, bool keep_alive)
	{
		if (!sock.request_get(*this, dp.get_key(), keep_alive))
		{
			return false;
		}
		delay(1000);
		String data;
		if (!sock.recv_get_data(data))
		{
			return false;
		}
		return dp.from_string(data);
	}

}
