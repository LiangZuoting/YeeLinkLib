#include <Ethernet.h>
#include <SPI.h>
#include <http_client.h>
#include <yl_data_point.h>
#include <yl_device.h>
#include <yl_w5100_client.h>
#include <yl_messenger.h>
#include <yl_sensor.h>
#include <yl_generic_data_point.h>

class personal_info_dp : public yl_generic_data_point
{
public:
	personal_info_dp(const String &key)
	: yl_generic_data_point(key)
	{}

	virtual String value_to_string() const
	{
		return "{\"name\":\"" + name_ + "\",\"age\":" + String(age_) + ",\"sex\":\"" + sex_ + "\"}";
	}

	virtual bool value_from_string(const String &str)
	{
		name_ = sub_string(str, 0, "\"name\":\"", "\",");
		age_ = sub_string(str, 0, "\"age\":\"", ",").toInt();
		sex_ = sub_string(str, 0, "\"sex\":\"", "\"}");
		return true;
	}


public:
	String name_;
	int age_;
	String sex_;
};

//replace 2633 3539 with ur device id and sensor id
yl_device ardu(2633);
yl_sensor generic(4013, &ardu);
//replace first param value with ur u-apikey
yl_w5100_client client;
yl_messenger messenger(&client, "u-apikey", "api.yeelink.net");
personal_info_dp qinqingege("personal_info");

void setup()
{
    Serial.begin(9600);	//for output information
	byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xAA};
	Ethernet.begin(mac);

	qinqingege.name_ = "qinqingege";
	qinqingege.age_ = 26;
	qinqingege.sex_ = "male";
}

void loop()
{
		generic.single_post(messenger, qinqingege);
		delay(1000 * 30);
}