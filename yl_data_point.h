#ifndef ARDUINO_YEELINKLIB_DATAPOINT_H
#define ARDUINO_YEELINKLIB_DATAPOINT_H

#include <WString.h>

namespace yeelink
{

	class yl_data_point
	{
	public:
		yl_data_point(const String &key = String());

		void set_key(const String &key);
		const String& get_key() const;
		virtual String to_string() const;
		virtual bool from_string(const String &str);

	protected:
		virtual	String key_to_string() const;
		virtual String value_to_string() const = 0;
		virtual bool key_from_string(const String &str);
		virtual bool value_from_string(const String &str) = 0;
		String ftoa(float val, char resolution) const;
		String sub_string(const String &str, int from_index, const String &start_str, const String &end_str);

	protected:
		String key_;
	};

}

#endif
