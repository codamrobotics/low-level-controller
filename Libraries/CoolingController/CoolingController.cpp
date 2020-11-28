#include "CoolingController.hpp"
#include <Arduino.h>

CoolingController::CoolingController(const unsigned int pinCooling)
    : _pinCooling(pinCooling)
{
    pinMode(pinCooling, OUTPUT);
    digitalWrite(pinCooling, LOW);
}

CoolingController::~CoolingController()
{
}

void CoolingController::setState(bool state)
{
    _state = state;
    digitalWrite(_pinCooling, state);
}

bool CoolingController::getState()
{
    return (_state);
}