#include <Ethernet.h>
#include <SPI.h>
#include <yl_device.h>
#include <yl_w5100_client.h>
#include <yl_messenger.h>
#include <yl_value_data_point.h>
#include <yl_sensor.h>

//this example gets newest data point from yeelink

//replace 2633 3539 with ur device id and sensor id
yl_device ardu(2633);
yl_sensor therm(3539, &ardu);
//replace first param value with ur u-apikey
yl_w5100_client client;
yl_messenger messenger(&client, "u-apikey", "api.yeelink.net");

void setup()
{
    Serial.begin(9600);	//for output information
	byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xAA};
	Ethernet.begin(mac);
}

void loop()
{
  yl_value_data_point dp;
  therm.single_get(messenger, dp);
        Serial.println(dp.get_value());
}