#include <Ethernet.h>
#include <SPI.h>
#include <http_client.h>
#include <yl_data_point.h>
#include <yl_device.h>
#include <yl_messenger.h>
#include <yl_sensor.h>
#include <yl_value_data_point.h>
#include <yl_value_sensor.h>

//this example reads data from a lm35dz sensor, convert value to degree Celsius
//and then post it to yeelink.net

//replace 2633 3539 with ur device id and sensor id
yeelink::yl_device ardu(2633);
yeelink::yl_value_sensor therm(3539, &ardu);
//replace first param value with ur u-apikey
yeelink::yl_messenger messenger("your u-apikey here", "api.yeelink.net");

const int THERM_PIN	= 0;

float lm35_convertor(int analog_num)
{
	return analog_num * (5.0 / 1024.0 * 100);
}

void setup()
{
    Serial.begin(9600);	//for output information
	byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xAA};
	Ethernet.begin(mac);
}

void loop()
{
	int v = 0;
	if (!messenger.connect_yl())
			{
                              Serial.println("connect to yeelink failed !");
			}
			else
			{
                               Serial.println("connected.");
			}
		v = analogRead(THERM_PIN);
        Serial.println(lm35_convertor(v));
		yeelink::yl_value_data_point dp(lm35_convertor(v));
		therm.post_data_point(messenger, dp);
		messenger.flush_stop();
		delay(1000 * 30);
}