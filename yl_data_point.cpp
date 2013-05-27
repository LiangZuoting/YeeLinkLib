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

	String yl_data_point::to_string() const
	{
		String result("{");
		String key = key_to_string();
		if (key.length())
		{
			result += key;
			result += ",";
		}
		result += "\"value\":";
		result += value_to_string();
		result += "}";

		return result;
	}

	String yl_data_point::key_to_string() const
	{
		if (key_.length())
		{
			String key("\"timestamp\":\"");
			key += key_;
			key += "\"";
			return key;
		}
		return "";
	}

	bool yl_data_point::from_string(const String &str)
	{
		if (!key_from_string(str)
			|| !value_from_string(str))
		{
			return false;
		}
		return true;
	}

	bool yl_data_point::key_from_string(const String &str)
	{
		if (str.length() == 0)
		{
			return true;
		}

		key_ = sub_string(str, 0, "\"timestamp\":\"", "\",");
		return key_.length();
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
		resolution = (resolution <= 6 ? resolution : 6);
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

	String yl_data_point::sub_string(const String &str, int from_index, const String &start_str, const String &end_str)
	{
		int start_index = str.indexOf(start_str, from_index);
		if (start_index < 0)
		{
			return "";
		}
		start_index += start_str.length();
		int end_index = str.indexOf(end_str, start_index);
		String value = str.substring(start_index, end_index);
		value.trim();
		if (value.length() == 0)
		{
			return "";
		}
		return value;
	}

}

