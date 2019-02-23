#include "Robot.h"
#include <iostream>
#include <frc/Timer.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DigitalInput.h>
#include <frc/I2C.h>
#include <frc/DriverStation.h>
#include <frc/Joystick.h>
#include <frc/DigitalInput.h>

#define I2C_Slave_Id 0x08;

using namespace frc;
using namespace std;

Robot::Robot() {
  
}
frc::I2C I2Channel = {frc::I2C::Port::kOnboard, 2};
frc::Joystick stick0{0};
frc::DigitalInput limBot(0);

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

void setLeds(int ledMode){
  switch(ledMode){
   case 0:
		I2CWrite(111); // all off
		break;
	case 1:
		I2CWrite(114); // wipe to red
		break;
	case 2:
		I2CWrite(103); // wipe to green
		break;
	case 3:
		I2CWrite(98); // wipe to blue
		break;
	case 4:
		I2CWrite(117); // static rainbow
		break;
	case 5:
		I2CWrite(99); // rainbow cycle
		break;
	case 6:
		I2CWrite(104); // chase along with the color byte as defined in cases 0 - 2
		break;
	case 7:
    I2CWrite(121);
    break; // wipe to amber
  }
}

//This function is for sending data through I2C
void I2CWrite(uint8_t data){
  I2Channel.Write(8, data);
  //This should print out what was sent through I2C
  std::cout << "Wrote:" << data << endl;
}

void Robot::Autonomous() {
  
}


void Robot::OperatorControl() {
 
}


void Robot::Test() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
