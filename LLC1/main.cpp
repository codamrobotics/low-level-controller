#include "Common/Deployment.hpp"
#include "Sandbox/Sandbox.hpp"

/*
** SAMPLE CODE
*/

using namespace sb;

Sandbox *sandbox;

void setup() //runs on startup
{
	sandbox = new Sandbox();
	sandbox->Setup();
}

void loop() // loops indefinitely
{
	// all your code here
	sandbox->SpinOnce();
}
