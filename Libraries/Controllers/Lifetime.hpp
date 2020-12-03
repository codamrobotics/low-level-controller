#ifndef CONTROLLER_LIFETIME_HPP
# define CONTROLLER_LIFETIME_HPP

#include "Controllers/Controller.hpp"
#include "Common/Datatypes.hpp"
#include "Common/Platform.hpp"
#include "Actuators/Relay.hpp"

class ControllerLifetime : public Controller
{
	public:
		ControllerLifetime(const uint8_t pins_relays[NUM_RELAYS]);
		~ControllerLifetime();
		void Lifephase(e_lifephase lifephase);
	private:
		ActuatorRelay *_relays[NUM_RELAYS];
		
};

#endif