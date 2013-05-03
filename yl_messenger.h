#ifndef ARDUINO_YEELINKLIB_MESSENGER_H
#define ARDUINO_YEELINKLIB_MESSENGER_H

#include "yl_data_point.h"
#include <WString.h>
#include <Ethernet.h>

namespace yeelink
{
	class yl_sensor;
	class yl_messenger : public EthernetClient
	{
	public:
		yl_messenger();
		yl_messenger(uint8_t sock);
		yl_messenger(const String &api_key, const String &host);
		yl_messenger(uint8_t sock, const String &api_key, const String &host);

		void set_api_key(const String &api_key);
		const String& get_api_key() const;
		String& get_api_key();
		void set_host(const String &host);
		const String& get_host() const;
		String& get_host();
		void set_version(const String &version);
		const String& get_version() const;
		String& get_version();

		bool connect_yl();
		bool post_yl_dp(const yl_sensor &sensor, const yl_data_point &dp);

	protected:
		size_t send(const String &data);

	private:
		String api_key_;
		String host_;
		String version_;
	};

}


#endif
