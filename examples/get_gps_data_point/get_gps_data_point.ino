#include <Ethernet.h>
#include <SPI.h>
#include <http_client.h>
#include <yl_data_point.h>
#include <yl_device.h>
#include <yl_messenger.h>
#include <yl_sensor.h>
#include <yl_gps_data_point.h>
#include <yl_sensor.h>

//replace 2633 3539 with ur device id and sensor id
yeelink::yl_device ardu(2633);
yeelink::yl_sensor gps(3539, &ardu);
//replace first param value with ur u-apikey
yeelink::yl_messenger messenger("ur u-apikey here", "api.yeelink.net");


void setup()
{
    Serial.begin(9600);	//for output information
	byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xAA};
	Ethernet.begin(mac);
}

void loop()
{
	yeelink::yl_gps_data_point dp;
	gps.single_get(messenger, dp);
	Serial.print("lat:");
	Serial.print(dp.get_location().lat);
	Serial.print("lng:");
	Serial.println(dp.get_location().lng);
	delay(1000 * 30);
}