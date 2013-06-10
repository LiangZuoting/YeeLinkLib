#ifndef ARDUINO_YEELINKLIB_TCPCLLIENT_H
#define ARDUINO_YEELINKLIB_TCPCLLIENT_H

#include <WString.h>

class yl_tcp_client
{
public:
	virtual int connect(const char *host, uint16_t port) = 0;
	virtual size_t send(int) = 0;
	virtual size_t send_ln(int) = 0;
	virtual size_t send(const String &) = 0;
	virtual int available() = 0;
	virtual int recv() = 0;
	virtual int recv(uint8_t *buf, size_t size) = 0;
	virtual void flush() = 0;
	virtual void stop() = 0;
};

#endif
