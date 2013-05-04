#include "yl_messenger.h"
#include "yl_sensor.h"

namespace yeelink
{
#define YEELINK_VERSION ("v1.0")

	yl_messenger::yl_messenger()
		: version_(YEELINK_VERSION)
	{}

	yl_messenger::yl_messenger(uint8_t sock)
		: EthernetClient(sock)
		, version_(YEELINK_VERSION)
	{}

	yl_messenger::yl_messenger(const String &api_key, const String &host)
		: EthernetClient()
		, api_key_(api_key)
		, host_(host)
		, version_(YEELINK_VERSION)
	{}

	yl_messenger::yl_messenger(uint8_t sock, const String &api_key, const String &host)
		: EthernetClient(sock)
		, api_key_(api_key)
		, host_(host)
		, version_(YEELINK_VERSION)
	{}

	void yl_messenger::set_api_key(const String &api_key)
	{
		api_key_ = api_key;
	}

	const String& yl_messenger::get_api_key() const
	{
		return api_key_;
	}

	String& yl_messenger::get_api_key()
	{
		return get_api_key();
	}

	void yl_messenger::set_host(const String &host)
	{
		host_ = host;
	}

	const String& yl_messenger::get_host() const
	{
		return host_;
	}

	String& yl_messenger::get_host()
	{
		return get_host();
	}

	void yl_messenger::set_version(const String &version)
	{
		version_ = version;
	}

	const String& yl_messenger::get_version() const
	{
		return version_;
	}

	String& yl_messenger::get_version()
	{
		return get_version();
	}

	bool yl_messenger::connect_yl()
	{
		return connect(&host_[0], 80);
	}

	bool yl_messenger::post_yl_dp(const yl_sensor &sensor, const yl_data_point &dp)
	{
		String data = dp.to_string();
		if (data.length() == 0)
		{
			return false;
		}

		String temp("POST /");
		temp += version_;
		temp += "device/";
		if (!send(temp)
			|| !print(sensor.get_device()->get_id())
			|| !send("/sensor/") 
			|| !print(sensor.get_id())
			|| !send("/datapoints HTTP/1.1\r\nHost:")
			|| !send(host_)
			|| !send("\r\nAccept: */*\r\nU-ApiKey:")
			|| !send(api_key_)
			|| !send("\r\nContent-Length:")
			|| !println(data.length())
			|| !send("Content-Type: application/x-www-form-urlencoded\r\n\r\n")
			|| !send(data))
		{
			return false;
		}
		return true;
	}

	size_t yl_messenger::send(const String &data)
	{
		char c = data[0];
		return write((uint8_t*)&c, data.length());
	}
}

