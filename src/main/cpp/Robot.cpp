// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <iostream>
#include <cmath>

using namespace ctre::phoenix6;

Robot::Robot() {}

void Robot::RobotInit(){
  FRR.SetNeutralMode(signals::NeutralModeValue::Coast);
  FLR.SetNeutralMode(signals::NeutralModeValue::Coast);
  BLR.SetNeutralMode(signals::NeutralModeValue::Coast);
  BRR.SetNeutralMode(signals::NeutralModeValue::Coast);
}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  FRR.SetNeutralMode(signals::NeutralModeValue::Brake);
  FLR.SetNeutralMode(signals::NeutralModeValue::Brake);
  BLR.SetNeutralMode(signals::NeutralModeValue::Brake);
  BRR.SetNeutralMode(signals::NeutralModeValue::Brake);

  FRD.SetNeutralMode(signals::NeutralModeValue::Brake);
  FLD.SetNeutralMode(signals::NeutralModeValue::Brake);
  BLD.SetNeutralMode(signals::NeutralModeValue::Brake);
  BRD.SetNeutralMode(signals::NeutralModeValue::Brake);
}

void Robot::TeleopPeriodic() {
  double fwd = -joystick.GetRawAxis(1)/2;
  double rot = joystick.GetRawAxis(4)/2;

  if (std::abs(fwd) < 0.1)
  {
    fwd=0;
  }
  if (std::abs(rot) < 0.1)
  {
    rot=0;
  }
  
  FRD.SetControl(ctre::phoenix6::controls::DutyCycleOut{fwd});
  FLD.SetControl(DutyCycle);
  BLD.SetControl(DutyCycle);
  BRD.SetControl(DutyCycle);
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif