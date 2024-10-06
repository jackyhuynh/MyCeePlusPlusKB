// RobotArm.cpp : Defines the entry point for the console application.
//

#include "Robot.h"

ROBOT_SDK_DEFINES(opcode)
ROBOT_SDK_CONTAINER(Container,queue,unsigned char)
ROBOT_SDK_AUTO(Robot,unsigned char)

void Test0()
{
	Robot robot(true);
}

void main()
{
	Test0();
}