#include "yl_value_data_point.h"

yl_value_data_point::yl_value_data_point(float value /*= 0.0f*/, const String &key /* = String */)
: yl_data_point(key)
, value_(value)
{}

void yl_value_data_point::set_value(float value)
{
	value_ = value;
}

float yl_value_data_point::get_value() const
{
	return value_;
}

String yl_value_data_point::value_to_string() const
{
	return ftoa(value_, 2);
}

bool yl_value_data_point::value_from_string(const String &str)
{
	if (str.length() == 0)
	{
		return false;
	}

	String value = sub_string(str, 0, "\"value\":", "}");
	value_ = atof(&value[0]);
	return true;
}

