#include "yl_sensor.h"

namespace yeelink
{

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

}
