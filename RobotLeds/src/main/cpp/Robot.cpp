#include "Robot.h"
#include <iostream>
#include <frc/Timer.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DigitalInput.h>
#include <frc/I2C.h>
#include <frc/DriverStation.h>
#include <frc/Joystick.h>
#include <frc/DigitalInput.h>

using namespace frc;
using namespace std;

Robot::Robot() {
  
}
uint8_t leds;

frc::I2C arduino = {frc::I2C::Port::kOnboard, 2};
frc::Joystick stick0{0};
frc::DigitalInput limBot(0);

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  frc::wait(1000);
  setLedsBeforeMatch();
}

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
  }
}

void Robot::Autonomous() {
 
}


void Robot::OperatorControl() {
 
}


void Robot::Test() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
