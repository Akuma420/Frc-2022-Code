// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include "ctre/Phoenix.h"

/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with tank steering.
 */

class Robot : public frc::TimedRobot {
  
	WPI_TalonSRX m_FLMotor{21};
	WPI_TalonSRX m_FRMotor{24};
	WPI_TalonSRX m_BLMotor{23};
	WPI_TalonSRX m_BRMotor{22};
	int autoLoopCounter;
   frc::SpeedControllerGroup m_right{m_FRMotor, m_BRMotor};
	 frc::SpeedControllerGroup m_left{m_FLMotor, m_BLMotor};

  frc::DifferentialDrive m_robotDrive{m_left, m_right};
  frc::Joystick m_Stick1{0};
  frc::Joystick m_Stick2{1};

 public:
 
  void RobotInit() override {
    // We need to invert one side of the drivetrain so that positive voltages
    // result in both sides moving forward. Depending on how your robot's
    // gearbox is constructed, you might have to invert the left side instead.
    m_right.SetInverted(true);
   // m_FRMotor.SetInverted(true);
   // m_FLMotor.SetInverted(true);
    //m_BRMotor.SetInverted(true);
  //  m_BLMotor.SetInverted(true);


  }

  void TeleopPeriodic() override {
    // Drive with tank style
		m_robotDrive.ArcadeDrive(m_Stick1.GetY()*-1, m_Stick2.GetX());
  }
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
