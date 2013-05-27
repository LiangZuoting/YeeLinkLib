#include "yl_generic_data_point.h"

namespace yeelink
{

	yl_generic_data_point::yl_generic_data_point(const String &key)
		: yl_data_point(key)
	{}

	String yl_generic_data_point::to_string() const
	{
		//"key":"cantacts",
		//"value":{"name":"qinqingege","age":26,"sex":"male"}}
		String result("{\"key\":\"");
		result += key_;
		result += "\",\"value\":{";
		result += to_string_value();
		result += "}}";
		return result;
	}

	bool yl_generic_data_point::from_string_get_key(const String &str)
	{
		if (str.length() == 0)
		{
			return false;
		}

		key_ = sub_string(str, 0, "\"key\":", ",");
		return key_.length();
	}

}

