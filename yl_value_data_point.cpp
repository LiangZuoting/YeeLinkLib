#include "yl_value_data_point.h"

namespace yeelink
{

	yl_value_data_point::yl_value_data_point(const String &key /* = String */, float value /*= 0.0f*/)
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
		value += int(value_);
		value += "}";
		result += value;

		return result;
	}

}

