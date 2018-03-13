#ifndef MAIN_ROBOT_H_
#define MAIN_ROBOT_H_

#include "WPILib.h"
#include <ctre/Phoenix.h>

#include "OI.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/Vision.h"
#include "Subsystems/Air.h"

class Robot: public IterativeRobot
{
	public:
		//create static objects of the subsystems
		static OI * oi;
		static DriveBase * drivebase;
		static Vision * vision;
		static Air * air;

	private:
		//LiveWindow * lw;
		Command *  autoncommand;
		Compressor * Compy;
		void RobotInit();
		void AutonomousInit();
		void AutonomousPeriodic();
		void TeleopInit();
		void TeleopPeriodic();
		void TestPeriodic();
		void DisabledPeriodic();
};

#endif
