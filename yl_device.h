#ifndef ARDUINO_YEELINKLIB_DEVICE_H
#define ARDUINO_YEELINKLIB_DEVICE_H

class yl_device
{
public:
	yl_device(int id = 0);

	void set_id(int id);
	int get_id() const;

private:
	int id_;
};


#endif
