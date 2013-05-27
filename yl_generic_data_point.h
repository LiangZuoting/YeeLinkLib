#ifndef ARDUINO_YEELINKLIB_GENERICDATAPOINT_H
#define ARDUINO_YEELINKLIB_GENERICDATAPOINT_H

#include "yl_data_point.h"

namespace yeelink
{

	class yl_generic_data_point : public yl_data_point
	{
	public:
		yl_generic_data_point(const String &key);

		virtual String to_string() const;

	protected:
		virtual String to_string_value() const = 0;
		virtual bool from_string_get_key(const String &str);

	};

}

#endif
