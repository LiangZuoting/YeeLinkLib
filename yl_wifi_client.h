#ifndef ARDUINO_YEELINKLIB_WIFICLLIENT_H
#define ARDUINO_YEELINKLIB_WIFICLLIENT_H

#include <WString.h>
#include <WiFiClient.h>
#include "yl_tcp_client.h"

class yl_wifi_client : public yl_tcp_client
{
public:
	yl_wifi_client();
	yl_wifi_client(uint8_t sock);

	virtual int connect(const char *host, uint16_t port);
	virtual size_t send(int);
	virtual size_t send_ln(int);
	virtual size_t send(const String &);
	virtual int available();
	virtual int recv();
	virtual int recv(uint8_t *buf, size_t size);
	virtual void flush();
	virtual void stop();

private:
	WiFiClient client_;
};

#endif