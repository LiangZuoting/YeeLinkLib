#ifndef ARDUINO_YEELINKLIB_MESSENGER_H
#define ARDUINO_YEELINKLIB_MESSENGER_H

#include "yl_data_point.h"
#include <WString.h>

class yl_sensor;
class yl_tcp_client;
class yl_messenger
{
public:
	yl_messenger();
	yl_messenger(yl_tcp_client *client);
	yl_messenger(const String &api_key, const String &host);
	yl_messenger(yl_tcp_client *client, const String &api_key, const String &host);

	void set_api_key(const String &api_key);
	const String& get_api_key() const;
	String& get_api_key();
	void set_host(const String &host);
	const String& get_host() const;
	String& get_host();
	void set_version(const String &version);
	const String& get_version() const;
	String& get_version();
	void set_tcp_client(yl_tcp_client *client);
	const yl_tcp_client* get_tcp_client() const;
	yl_tcp_client* get_tcp_client();

	bool connect_yl();
	bool request_post(const yl_sensor &sensor, const yl_data_point &dp, bool keep_alive);
	bool get_request_result();
	bool request_get(const yl_sensor &sensor, const String &key, bool keep_alive);
	bool recv_get_data(String &data);
	void flush_stop();

protected:
	bool recv_ln(String &data);
	bool recv_ln_start_with(const String start, String &data);

private:
	String api_key_;
	String host_;
	String version_;
	yl_tcp_client *client_;
};

#endif
