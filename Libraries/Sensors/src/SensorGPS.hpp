#ifndef SENSOR_GPS_HPP
#define SENSOR_GPS_HPP

// TinyGPS documentation:
// https://github.com/neosarchizo/TinyGPS/blob/master/examples/test_with_gps_device/test_with_gps_device.ino

#include <SoftwareSerial.h>
#include <TinyGPS.h>

#include <Sensor.hpp>

class SensorGPS : public Sensor {
public:
    SensorGPS(	HardwareSerial& serial,
				const uint16_t baudrate,
				const uint16_t timeout,
				const unsigned long sampling_interval);
    ~SensorGPS();
	bool Init();
    bool Update();
    void GetLocation(float* flat, float* flon);
    void GetTime(unsigned long* age, unsigned long* date, unsigned long* time);
    float GetSpeed();
    float GetCourse();
private:
    HardwareSerial& _ss;
    TinyGPS _gps;
    float _flat,
        _flon,
        _kmph,
        _course;
    unsigned long _age,
        _date,
        _time,
        _chars = 0;
    unsigned short _sentences = 0,
                   _checksum = 0;
    int _year;
    uint8_t _month,
        _day,
        _hour,
        _minute,
        _second,
        _hundredths;
	const uint16_t _baudrate, _timeout;
};

#endif