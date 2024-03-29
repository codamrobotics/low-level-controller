#include "Common/Deployment.hpp"
#include "Common/Platform.hpp"
#include "Logic/Steering.hpp"
#include "Sandbox/Sandbox.hpp"
#include "Sensors/IMU.hpp"

/*
** SAMPLE CODE
*/

using namespace sb;

Sandbox* sandbox;

bool LogicDriverUpdate(void) // is called just before update of motorcontroller in Sandbox::Spinonce
{
    return (true);
}

void setup() //runs on startup
{
    sandbox = new Sandbox();
    sandbox->Setup();
    sandbox->SetLogicDriverUpdate(LogicDriverUpdate);

    Serial.begin(115200);

    Serial.println("Test_SimpleSpinAngle.cpp");
}

void loop() // loops indefinitely
{
    int16_t angle = IMUGetNavigationAngle();
    const int16_t target = 175;

    Serial.print("Angle : "); Serial.println(angle);

    if (abs(target - angle) > 1) {
        if (angle > target) {
            Serial.println("RIGHT");
            Driver(LEFT, BACKWARD, 50);
            Driver(RIGHT, FORWARD, 50);
        } else {
            Serial.println("LEFT");
            Driver(LEFT, FORWARD, 50);
            Driver(RIGHT, BACKWARD, 50);
        }
    } else {
        Serial.println("HALTING");
        Driver(ALL_SIDES, HALT);
    }
	sandbox->SpinOnce();
}

void post() // runs after break in loop()
{
	sandbox->Shutdown();
}
