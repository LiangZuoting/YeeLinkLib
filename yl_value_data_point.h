#ifndef ARDUINO_YEELINKLIB_VALUEDATAPOINT_H
#define ARDUINO_YEELINKLIB_VALUEDATAPOINT_H

#include "yl_data_point.h"

namespace yeelink
{

	class yl_value_data_point : public yl_data_point
	{
	public:
		yl_value_data_point(const String &key = String(), float value = 0.0f);

		void set_value(float value);
		float get_value() const;

		virtual String to_string() const;

	private:
		float value_;
	};

}

#endif
