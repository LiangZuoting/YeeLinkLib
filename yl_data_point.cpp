#include "yl_data_point.h"

namespace yeelink
{

	yl_data_point::yl_data_point(const String &key /* = String */)
		: key_(key)
	{}

	void yl_data_point::set_key(const String &key)
	{
		key_ = key;
	}

	const String& yl_data_point::get_key() const
	{
		return key_;
	}

	bool yl_data_point::from_string(const String &str)
	{
		if (!from_string_get_key(str)
			|| !from_string_get_value(str))
		{
			return false;
		}
		return true;
	}

	bool yl_data_point::from_string_get_key(const String &str)
	{
		if (str.length() == 0)
		{
			return true;
		}
		String flag("\"timestamp\":");
		int start_index = str.indexOf(flag);
		if (start_index < 0)
		{
			return true;
		}
		start_index += flag.length();
		int end_index = str.indexOf(',', start_index);
		key_ = str.substring(start_index, end_index);
		key_.trim();
		return true;
	}

}

