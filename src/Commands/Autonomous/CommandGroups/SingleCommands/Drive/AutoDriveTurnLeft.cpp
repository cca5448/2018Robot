#include "AutoDriveTurnLeft.h"
#include "Robot.h"
#include "RobotMap.h"

AutoDriveTurnLeft::AutoDriveTurnLeft(float degrees)
{
	Requires(Robot::drivebase);
	printf("Auto Drive Turn Left %f degrees\n", degrees);
	m_TARGET_ANGLE = degrees;
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
	if (!Robot::drivebase->IsGyroGood()) {
		printf("AutoDriveTurnLeft ended early because IsGyroGood == false\n");
		return true;  //if gyro is bad, finish now to prevent spin of death!
	}
	//printf("Gyro: %f\n",Robot::drivebase->ReturnGyroAngle());
	return (Robot::drivebase->ReturnGyroAngle() >= m_TARGET_ANGLE); //until we reach the target angle
}

void AutoDriveTurnLeft::End()
{
	Robot::drivebase->DriveTank(0,0);
}

void AutoDriveTurnLeft::Interrupted()
{
	End();
}
