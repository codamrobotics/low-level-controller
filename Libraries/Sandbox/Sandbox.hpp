#ifndef SANDBOX_HPP
#define SANDBOX_HPP

#include "ros.h"

#include "Common/Datatypes.hpp"
#include "Common/Vec3.hpp"

#include "Controllers/Anomaly.hpp"
#include "Controllers/Awareness.hpp"
#include "Controllers/Lifetime.hpp"
#include "Controllers/Motor.hpp"
#include "Controllers/PhysicalFeedback.hpp"
#include "Interfaces/ROS.hpp"

#include "Sensors/GPS.hpp"
#include "Sensors/IMU.hpp"
#include "Sensors/Temp.hpp"
#include "Sensors/Ultrasonic.hpp"

namespace sb {

class Sandbox {
public:
    void Setup();
    void Shutdown();
    void SpinOnce();
    Sandbox();
    ~Sandbox();

    void ROSAddSubscriber(ros::Subscriber_& s);
    void ROSAddPublisher(ros::Publisher& p);
    bool Driver(const e_side side, const e_drive_action action);
    bool Driver(const e_side side, const e_drive_action action, const uint8_t throttle);
    bool DriverIsReady();
    bool DriverIsMoving();
    bool DriverIsAccelerating();
    bool DriverIsDecelerating();
    void DriverHalt();
    void DriverSlowHalt();
    void DriverSlowHalt(const e_side side);

    uint8_t DriverGetThrottle(const e_side side);
    void DriverSetThrottle(const e_side side, const uint8_t throttle);

    int16_t IMUGetNavigationAngle();
    Vec3 IMUGetMagnetoData();
    Vec3 IMUGetAcceleroData();

    int16_t USGetDistance(e_corner corner);

    void GPSGetLocation(float* flat, float* flon);
    void GPSGetTime(unsigned long* age, unsigned long* date, unsigned long* time); // overkill?
    int16_t GPSGetSpeed();
    int16_t GPSGetCourse();
    int8_t TEMPGetTemperature();

    void SIGBeep(const e_siglevel siglevel, const uint8_t count);

    int8_t GetRPM(const e_corner corner);
    int8_t GetRevolutions(const e_corner corner);

    void SetLogicDriverUpdate(bool (*f)(void));

private:
    unsigned long _glob_millis;
    InterfaceROS _interface_ros;
    ControllerMotor _controller_motor;
    ControllerLifetime _controller_lifetime;
    ControllerPhysicalFeedback _controller_physical_feedback;
    ControllerAnomaly _controller_anomaly;
    ControllerAwareness _controller_awareness;

    bool (*_LogicDriverUpdate)(void);
};

// public functions
void ROSAddSubscriber(ros::Subscriber_& s);
void ROSAddPublisher(ros::Publisher& p);

bool Driver(const e_side side, const e_drive_action action);
bool Driver(const e_side side, const e_drive_action action, const uint8_t throttle);
bool DriverIsReady();
bool DriverIsMoving();
bool DriverIsAccelerating();
bool DriverIsDecelerating();
void DriverHalt();
void DriverSlowHalt();
uint8_t DriverGetThrottle(const e_side side);
void DriverSetThrottle(const e_side side, const uint8_t throttle);

int8_t GetRPM(const e_corner corner);

int16_t IMUGetNavigationAngle();
Vec3 IMUGetMagnetoData();
Vec3 IMUGetAcceleroData();

int16_t USGetDistance(e_corner corner);

void GPSGetLocation(float* flat, float* flon);
void GPSGetTime(unsigned long* age, unsigned long* date, unsigned long* time); // overkill?
int16_t GPSGetSpeed();
int16_t GPSGetCourse();

int8_t TEMPGetTemperature();

void SIGBeep(const e_siglevel siglevel, const uint8_t count);
} // namespace sb
#endif
