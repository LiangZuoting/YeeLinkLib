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

}

