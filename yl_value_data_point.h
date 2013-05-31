#ifndef ARDUINO_YEELINKLIB_VALUEDATAPOINT_H
#define ARDUINO_YEELINKLIB_VALUEDATAPOINT_H

#include "yl_data_point.h"

class yl_value_data_point : public yl_data_point
{
public:
	yl_value_data_point(float value = 0.0f, const String &key = String());

	void set_value(float value);
	float get_value() const;

protected:
	virtual String value_to_string() const;
	virtual bool value_from_string(const String &str);

private:
	float value_;
};

#endif
