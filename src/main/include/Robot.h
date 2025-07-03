// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/CANcoder.hpp>

class Robot : public frc::TimedRobot {
 private:
  ctre::phoenix6::CANBus kCANBus{"rio"};

  //Define Front Right Motors
  ctre::phoenix6::hardware::TalonFX FRD{0, kCANBus};
  ctre::phoenix6::hardware::TalonFX FRR{1, kCANBus};

  //Define Front Left Motors
  ctre::phoenix6::hardware::TalonFX FLD{2, kCANBus};
  ctre::phoenix6::hardware::TalonFX FLR{3, kCANBus};

  //Define Back Left Motors
  ctre::phoenix6::hardware::TalonFX BLD{4, kCANBus};
  ctre::phoenix6::hardware::TalonFX BLR{5, kCANBus};

  //Define Back Right Motors
  ctre::phoenix6::hardware::TalonFX BRD{6, kCANBus};
  ctre::phoenix6::hardware::TalonFX BRR{7, kCANBus};

  //Define Encoders in Order: FR, FL, BL, BR
  ctre::phoenix6::hardware::CANcoder FR{0, kCANBus};
  ctre::phoenix6::hardware::CANcoder FL{1, kCANBus};
  ctre::phoenix6::hardware::CANcoder BL{2, kCANBus};
  ctre::phoenix6::hardware::CANcoder BR{3, kCANBus};

  ctre::phoenix6::controls::DutyCycleOut DutyCycle{0}; // Initialize output to 0%

  frc::XboxController joystick{0};

  int printCount{};

 public:
  Robot();
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  void SimulationInit() override;
  void SimulationPeriodic() override;
};