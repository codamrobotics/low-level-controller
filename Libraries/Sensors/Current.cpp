#include "Sensors/Current.hpp"
#include <Arduino.h>

float SensorCurrent::GetCurrent()
{
    return (this->_DCCurrent);
}

/*read DC Current Value*/
float SensorCurrent::_readDCCurrent()
{
    int analogValueArray[31];
    for (int index = 0; index < 31; index++) {
        analogValueArray[index] = analogRead(this->_analogPin);
    }
    int i, j, tempValue;
    for (j = 0; j < 31 - 1; j++) {
        for (i = 0; i < 31 - 1 - j; i++) {
            if (analogValueArray[i] > analogValueArray[i + 1]) {
                tempValue = analogValueArray[i];
                analogValueArray[i] = analogValueArray[i + 1];
                analogValueArray[i + 1] = tempValue;
            }
        }
    }
    float medianValue = analogValueArray[(31 - 1) / 2];
    float DCCurrentValue = (medianValue / 1024.0 * this->_Vref - this->_Vref / 2.0)
        / _mVperAmp; //Sensitivity:100mV/A, 0A @ Vcc/2
    return DCCurrentValue;
}

/*read reference voltage*/
long SensorCurrent::_readVref()
{
    long result;
#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
    ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
#elif defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) || defined(__AVR_AT90USB1286__)
    ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
    ADCSRB &= ~_BV(MUX5); // Without this the function always returns -1 on the ATmega2560 http://openenergymonitor.org/emon/node/2253#comment-11432
#elif defined(__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
    ADMUX = _BV(MUX5) | _BV(MUX0);
#elif defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
    ADMUX = _BV(MUX3) | _BV(MUX2);
#endif
#if defined(__AVR__)
    delay(2); // Wait for Vref to settle
    ADCSRA |= _BV(ADSC); // Convert
    while (bit_is_set(ADCSRA, ADSC))
        ;
    result = ADCL;
    result |= ADCH << 8;
    result = 1126400L / result; //1100mV*1024 ADC steps http://openenergymonitor.org/emon/node/1186
    return result;
#elif defined(__arm__)
    return (3300); //Arduino Due
#else
    return (3300); //Guess that other un-supported architectures will be running a 3.3V!
#endif
}

bool SensorCurrent::Update()
{
    if (!this->IsTimeToExecute())
        return (true);
    this->_DCCurrent = this->_readDCCurrent();
    // check for out of range updates and restore old value if necessary
    return (true);
}

SensorCurrent::SensorCurrent(const uint8_t analogPin, const uint16_t exec_interval)
    : Sensor(exec_interval)
    , _analogPin(analogPin)
{
    this->_Vref = _readVref(); //read the reference voltage(default:VCC)
}

SensorCurrent::~SensorCurrent()
{
}
