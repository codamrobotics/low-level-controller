// #include "Common/Deployment.hpp"
// #include "Sandbox/Sandbox.hpp"
// #include "Interfaces/ROS.hpp"
// /*
// ** SAMPLE CODE
// */

// using namespace sb;

// Sandbox sandbox;
// ROS ros_test;



#include <ros.h>
#include <std_msgs/String.h>
  
ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";

void setup()
{
	nh.initNode();
	nh.advertise(chatter);
}

void loop(void)
{
	while (!nh.connected())
	{
		nh.spinOnce();
	}

	str_msg.data = hello;
	chatter.publish( &str_msg );
	nh.logerror("Testing error");
	nh.spinOnce();
	delay(5000);
}

// int main(void)
// {

// 	sandbox.Setup();
// 	while (true)
// 	{
// 		// all your code here
// 		sandbox.SpinOnce();
// 		ros_test.SpinOnce();
// 	}
// }
