#include "yl_value_data_point.h"

namespace yeelink
{

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

	String yl_value_data_point::to_string() const
	{
		String result("{");
		if (key_.length() != 0)
		{
			//"timestamp":"2012-03-15T16:13:14",
			String key("\"timestamp\":\"");
			key += key_;
			key += "\",";
			result += key;
		} 
		//"value":294.34}
		String value("\"value\":");
		value += int(value_ + 0.5f);
		value += "}";
		result += value;
		return result;
	}

	bool yl_value_data_point::from_string_get_value(const String &str)
	{
		if (str.length() == 0)
		{
			return false;
		}
		String flag("\"value\":");
		int start_index = str.indexOf(flag);
		if (start_index < 0)
		{
			return false;
		}
		start_index += flag.length();
		int end_index = str.indexOf('}', start_index);
		String value = str.substring(start_index, end_index);
		value.trim();
		if (value.length() == 0)
		{
			return false;
		}
		value_ = atof(&value[0]);
		return true;
	}

}

