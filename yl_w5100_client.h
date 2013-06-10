#ifndef ARDUINO_YEELINKLIB_W5100CLLIENT_H
#define ARDUINO_YEELINKLIB_W5100CLLIENT_H

#include <WString.h>
#include <EthernetClient.h>
#include "yl_tcp_client.h"

class yl_w5100_client : public yl_tcp_client
{
public:
	yl_w5100_client();
	yl_w5100_client(uint8_t sock);

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
	EthernetClient client_;
};

#endif
