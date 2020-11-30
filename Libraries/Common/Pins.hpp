/*
*	Pinlayout is defined here.
*	-- layout for Atmega2560/Mega
*/

#ifndef COMMON_PINS_HPP
# define COMMON_PINS_HPP

# include <stdint.h>
# include <pins_arduino.h>
# include "Common/Datatypes.hpp"

# define NUM_MOTORS											4
# define NUM_ULTRASONIC										4
# define NUM_RELAYS											4

namespace LLC1												{

const t_pins_motor pins_motors[NUM_MOTORS] =				{
																(4,23,25),
																(5, 27, 29),
																(6, 31, 33),
																(7, 35, 37)
															};

const t_pins_imu pins_imu = 								{
																(20, 21)
															};

const t_pins_gps pins_gps = 								{
																(16, 17)
															};

const uint8_t pins_hall[NUM_MOTORS] = 						{
																18,
																19,
																2,
																3
															};

const uint8_t pins_current[NUM_MOTORS] = 					{
																A0,
																A1,
																A2,
																A3
															};

const uint8_t pins_ultrasonic[NUM_ULTRASONIC] = 			{
																A4,
																A5,
																A6,
																A7
															};

const uint8_t pins_relay[NUM_RELAYS] = 						{
																48,
																46,
																44,
																42
															};
} // namespace LLC1

//#define RELAY_POWER				48	// DIGITAL
//#define RELAY_FAN				46	// DIGITAL
//#define RELAY_V12				44	// DIGITAL
//#define RELAY_MOTORS			42	// DIGITAL
//
//
//#define RELAY_POWER				48	// DIGITAL
//#define RELAY_FAN				46	// DIGITAL
//#define RELAY_V12				44	// DIGITAL
//#define RELAY_MOTORS			42	// DIGITAL
//
////ready
//#define MOTOR_FRONT_LEFT_PWM	4	// DIGITAL
//#define MOTOR_FRONT_LEFT_A		23	// DIGITAL
//#define MOTOR_FRONT_LEFT_B		25	// DIGITAL
//
//#define MOTOR_FRONT_RIGHT_PWM	5	// DIGITAL
//#define MOTOR_FRONT_RIGHT_A		27	// DIGITAL
//#define MOTOR_FRONT_RIGHT_B		29	// DIGITAL
//
//#define MOTOR_BACK_LEFT_PWM		6	// DIGITAL
//#define MOTOR_BACK_LEFT_A		31	// DIGITAL
//#define MOTOR_BACK_LEFT_B		33	// DIGITAL
//
//#define MOTOR_BACK_RIGHT_PWM	7	// DIGITAL
//#define MOTOR_BACK_RIGHT_A		35	// DIGITAL
//#define MOTOR_BACK_RIGHT_B		37	// DIGITAL
//
//#define HALL_FRONT_LEFT			18	// DIGITAL
//#define HALL_FRONT_RIGHT		19	// DIGITAL
//#define HALL_BACK_LEFT			2	// DIGITAL
//#define HALL_BACK_RIGHT			3	// DIGITAL
//
//#define IMU_SDA					20	// DIGITAL
//#define IMU_SCL					21	// DIGITAL
//
//#define GPS_TX					16	// DIGITAL
//#define GPS_RX					17	// DIGITAL
//
//#define CURRENT_FRONT_LEFT		0	// ANALOG
//#define CURRENT_FRONT_RIGHT		1	// ANALOG
//#define CURRENT_BACK_LEFT		2	// ANALOG
//#define CURRENT_BACK_RIGHT		3	// ANALOG
//
//#define SONAR_FRONT_LEFT		4	// ANALOG
//#define SONAR_FRONT_RIGHT		5	// ANALOG
//#define SONAR_BACK_LEFT			6	// ANALOG
//#define SONAR_BACK_RIGHT		7	// ANALOG

#endif