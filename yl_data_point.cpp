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

	String yl_data_point::ftoa(float val, char resolution) const
	{
		if (val < 0.000001 && val > -0.000001)
		{
			return "0";
		}
		String result;
		bool positive = val > 0.0f ? true : false;
		if (!positive)
		{
			result += "-";
			val = -val;
		}
		int i_part = int(val);
		float f_part = val - i_part;
		result += i_part;

		String temp;
		resolution = min(resolution, 6);
		float min_val = 0.000001;
		for (int i = 0; i < resolution && f_part >= min_val; ++i)
		{
			temp += int(f_part * 10);
			f_part = f_part * 10 - int(f_part * 10);
			min_val *= 10;
		}
		if (temp.length())
		{
			result += ".";
			result += temp;
		}
		return result;
	}

}

