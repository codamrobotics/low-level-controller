#include <Arduino.h>

#include "SensorHall.hpp"

// i am not proud of this

// attach interrupt doesnt allow arguments, so hardcoded globs are required
static unsigned int pulses[HALL_INTERRUPT_COUNT];

void SensorHall::update()
{
    unsigned long millisDev = this->getDuration();
    this->_rpm = millisDev == 0 ? 0 : (pulses[this->_pulseIndex] / this->_cpr) / (millisDev / 60000);
    pulses[this->_pulseIndex] = 0;
}

int SensorHall::getRPM()
{
    return (this->_rpm);
}

void interruptCallA()
{
    pulses[0]++;
}

void interruptCallB()
{
    pulses[1]++;
}

void interruptCallC()
{
    pulses[2]++;
}
void interruptCallD()
{
    pulses[3]++;
}

SensorHall::SensorHall(const unsigned int pinA,
    const unsigned int pinB,
    const unsigned int interrupt,
    const unsigned int cpr,
    const unsigned long* globMillis)
    : Sensor(globMillis)
    , _pinA(pinA)
    , _pinB(pinB)
    , _interrupt(interrupt)
    , _cpr(cpr)
{
    static unsigned int cc;

    pinMode(_pinB, INPUT); // What is this function doing?
        // Unclear why there are extra semi-colons here, or what attachInterrupt
        // is here to do.
    switch (cc) {
    case 0:
        attachInterrupt(_interrupt, interruptCallA, CHANGE);
        this->_pulseIndex = 0;
        break;
        ;
        ;
    case 1:
        attachInterrupt(_interrupt, interruptCallB, CHANGE);
        this->_pulseIndex = 1;
        break;
        ;
        ;
    case 2:
        attachInterrupt(_interrupt, interruptCallB, CHANGE);
        this->_pulseIndex = 2;
        break;
        ;
        ;
    case 3:
        attachInterrupt(_interrupt, interruptCallB, CHANGE);
        this->_pulseIndex = 3;
        break;
        ;
        ;
    }
    cc++;
}

SensorHall::~SensorHall()
{
}
