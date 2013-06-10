#include "yl_sensor.h"
#include "yl_messenger.h"
#include <arduino.h>

yl_sensor::yl_sensor(void)
: id_(0), device_(0)
{
}

yl_sensor::yl_sensor(int id, yl_device *d)
: id_(id), device_(d)
{}

void yl_sensor::set_id(int id)
{
	id_ = id;
}

int yl_sensor::get_id() const
{
	return id_;
}

void yl_sensor::set_device(yl_device *dev)
{
	device_ = dev;
}

yl_device * yl_sensor::get_device() const
{
	return device_;
}

bool yl_sensor::single_post(yl_messenger &sock, const yl_data_point &dp)
{
	if (!sock.connect_yl())
	{
		return false;
	}
	bool ret = post(sock, dp, false);
	sock.flush_stop();
	return ret;
}

bool yl_sensor::single_get(yl_messenger &sock, yl_data_point &dp)
{
	if (!sock.connect_yl())
	{
		return false;
	}
	bool ret = get(sock, dp, false);
	sock.flush_stop();
	return ret;
}

bool yl_sensor::post(yl_messenger &sock, const yl_data_point &dp, bool keep_alive)
{
	if (!sock.request_post(*this, dp, keep_alive))
	{
		return false;
	}
	//wait for pending data, the value depends on ur network environment
	delay(1000);
	return sock.get_request_result();
}

bool yl_sensor::get(yl_messenger &sock, yl_data_point &dp, bool keep_alive)
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
