#include "yl_generic_data_point.h"

yl_generic_data_point::yl_generic_data_point(const String &key)
: yl_data_point(key)
{}

String yl_generic_data_point::key_to_string() const
{
	return "\"key\":\"" + key_ + "\"";
}

bool yl_generic_data_point::key_from_string(const String &str)
{
	if (str.length() == 0)
	{
		return false;
	}

	key_ = sub_string(str, 0, "\"key\":\"", "\",");
	return key_.length();
}

