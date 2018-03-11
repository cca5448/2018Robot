#ifndef MAIN_ROBOT_H_
#define MAIN_ROBOT_H_

#include "WPILib.h"
#include <SmartDashboard/SendableChooser.h>
#include <ctre/Phoenix.h>
#include "VictorSP.h"

#include "OI.h"
//#include "Subsystems/Aimer.h"
#include "Subsystems/Climber.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/Vision.h"
#include "Subsystems/Air.h"
#include "Subsystems/Setup.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Intake.h"

class Robot: public IterativeRobot
{
	public:
		//create static objects of the subsystems
		static OI * oi;
		static Climber * climber;
		static DriveBase * drivebase;
		static Vision * vision;
		static Air * air;
		static Setup * setup;
		static Shooter * shooter;
		static Intake * intake;

	private:
		Command * autoncommand;
		void RobotInit();
		void AutonomousInit();
		void AutonomousPeriodic();
		void TeleopInit();
		void TeleopPeriodic();
		void TestPeriodic();
		void DisabledPeriodic();
};

#endif
