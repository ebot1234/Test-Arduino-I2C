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
<<<<<<< HEAD
frc::I2C I2Channel = {frc::I2C::Port::kOnboard, 2};
=======
uint8_t leds;

frc::I2C arduino = {frc::I2C::Port::kOnboard, 2};
>>>>>>> parent of b2ad690... added arduino data to store returned data from the arduino
frc::Joystick stick0{0};
frc::DigitalInput limBot(0);

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}
<<<<<<< HEAD
//This function is for sending data through I2C
void I2CWrite(uint8_t data){
  I2Channel.Write(8, data);
  //This should print out what was sent through I2C
  std::cout << "Wrote:" << data << endl;
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
=======

void setLedsBeforeMatch(){
//Sets the leds if FMS or DS is present and to the alliance color when robot is ready
  if(frc::DriverStation::IsFMSAttached() == true || frc::DriverStation::IsDSAttached() == true){
    if(frc::DriverStation::Alliance::kRed){
      leds[0] = 1;
      arduino.Transaction(leds, 1, NULL, NULL);
      std::cout << "Robot is connected and is red alliance\n" << endl;
    }
    else{
      leds[0] = 9;
      arduino.Transaction(leds, 1, NULL, NULL);
      std::cout << "Robot is connected and no alliance is selected\n";
    }
  }
  if(frc::DriverStation::IsFMSAttached() == true ||frc::DriverStation::IsDSAttached() == true){
    if(frc::DriverStation::Alliance::kBlue){
      leds[0] = 2;
      arduino.Transaction(leds, 1, NULL, NULL);
      std::cout << "Robot is connected and is blue alliance\n" << endl;
    }
    else{
      leds[0] = 9;
      arduino.Transaction(leds, 1, NULL, NULL);
      std::cout << "Robot is connected and no alliance is selected\n";
    }
  }
}

void setLedsDuringMatch(int mode){
  switch(mode){
    case 1:
      leds[0] = 1;
      arduino.Transaction(leds, 1, NULL, NULL);
      break;
    case 2:
      leds[0] = 2;
      arduino.Transaction(leds, 1, NULL, NULL);
      break;
    case 3:
      leds[0] = 3;
      arduino.Transaction(leds, 1, NULL, NULL);
      break;
    case 4:
      leds[0] = 4;
      arduino.Transaction(leds, 1, NULL, NULL);
      break;
    case 5:
      leds[0] = 5;
      arduino.Transaction(leds, 1, NULL, NULL);
      break;
    case 6:
      leds[0] = 6;
      arduino.Transaction(leds, 1, NULL, NULL);
      break;
    case 7:
      leds[0] = 7;
      arduino.Transaction(leds, 1, NULL, NULL);
      break;
    case 8:
      leds[0] = 8;
      arduino.Transaction(leds, 1, NULL, NULL);
      break;
    case 9:
      leds[0] = 9;
      arduino.Transaction(leds, 1, NULL, NULL);
      break;
>>>>>>> parent of b2ad690... added arduino data to store returned data from the arduino
  }
}


void Robot::Autonomous() {
  
}


void Robot::OperatorControl() {
 if(stick0.GetRawButton(1)){
	 setLeds(114); //red
 }
 else{
	 setLeds(111);
 }

 if(stick0.GetRawButton(2)){
	 setLeds(103); //green
 }
 else{
	 setLeds(111);
 }

 if(stick0.GetRawButton(3)){
	 setLeds(98); //blue
 }
 else {
	 setLeds(111);
 }
}


void Robot::Test() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
