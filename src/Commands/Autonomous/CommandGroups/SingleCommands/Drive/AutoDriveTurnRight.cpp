#include "AutoDriveTurnRight.h"
#include "Robot.h"
#include "RobotMap.h"

AutoDriveTurnRight::AutoDriveTurnRight(float angle)
{
	Requires(Robot::drivebase);
	printf("Auto Drive Turn Left - to %f degrees\n", angle);
	m_TARGET_ANGLE = angle;
}

void AutoDriveTurnRight::Initialize()
{
	Robot::drivebase->ResetGyro();
}

void AutoDriveTurnRight::Execute()
{
	Robot::drivebase->DriveTank(AUTON_DRIVE_SPEED,-AUTON_DRIVE_SPEED);
}

bool AutoDriveTurnRight::IsFinished()
{
	return (Robot::drivebase->ReturnGyroAngle() >= m_TARGET_ANGLE);
}

void AutoDriveTurnRight::End()
{
	Robot::drivebase->DriveTank(0,0);
}

void AutoDriveTurnRight::Interrupted()
{
	End();
}
