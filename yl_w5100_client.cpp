#include "yl_w5100_client.h"

yl_w5100_client::yl_w5100_client()
{}

yl_w5100_client::yl_w5100_client(uint8_t sock)
	: client_(sock)
{}

int yl_w5100_client::connect(const char *host, uint16_t port)
{
	return client_.connect(host, port);
}

size_t yl_w5100_client::send(int n)
{
	return client_.print(n);
}

size_t yl_w5100_client::send_ln(int n)
{
	return client_.println(n);
}

size_t yl_w5100_client::send(const String &s)
{
	if (s.length() == 0)
	{
		return 0;
	}
	String temp(s);
	char *c = &temp[0];
	return client_.write((uint8_t*)c, temp.length());
}

int yl_w5100_client::available()
{
	return client_.available();
}

int yl_w5100_client::recv()
{
	return client_.read();
}

int yl_w5100_client::recv(uint8_t *buf, size_t size)
{
	return client_.read(buf, size);
}

void yl_w5100_client::flush()
{
	client_.flush();
}

void yl_w5100_client::stop()
{
	client_.stop();
}

