#include "yl_device.h"

yl_device::yl_device(int id /* = 0 */)
: id_(id)
{}

void yl_device::set_id(int id)
{
	id_ = id;
}

int yl_device::get_id() const
{
	return id_;
}

