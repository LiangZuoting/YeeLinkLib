#ifndef ARDUINO_YEELINKLIB_SENSOR_H
#define ARDUINO_YEELINKLIB_SENSOR_H

#include "yl_device.h"

class yl_messenger;
class yl_data_point;
class yl_sensor
{
public:
	yl_sensor(void);
	yl_sensor(int id, yl_device *d);

	void set_id(int id);
	int get_id() const;
	void set_device(yl_device *dev);
	yl_device * get_device() const;

	virtual bool single_post(yl_messenger &sock, const yl_data_point &dp);
	virtual bool post(yl_messenger &sock, const yl_data_point &dp, bool keep_alive);
	virtual bool single_get(yl_messenger &sock, yl_data_point &dp);
	virtual bool get(yl_messenger &sock, yl_data_point &dp, bool keep_alive);

protected:
	int id_;
	yl_device *device_;
};

#endif

