#include "AutoDriveTurnLeft.h"
#include "Robot.h"
#include "RobotMap.h"

AutoDriveTurnLeft::AutoDriveTurnLeft(float angle)
{
	Requires(Robot::drivebase);
	printf("Auto Drive Turn Left - to %f degrees\n", angle);
	m_TARGET_ANGLE = angle;
}

void AutoDriveTurnLeft::Initialize()
{
	Robot::drivebase->ResetGyro();
}

void AutoDriveTurnLeft::Execute()
{
	Robot::drivebase->DriveTank(0,AUTON_TURN_SPEED);
}

bool AutoDriveTurnLeft::IsFinished()
{
	return (Robot::drivebase->ReturnGyroAngle() <= -m_TARGET_ANGLE);
}

void AutoDriveTurnLeft::End()
{
	Robot::drivebase->DriveTank(0,0);
}

void AutoDriveTurnLeft::Interrupted()
{
	End();
}
