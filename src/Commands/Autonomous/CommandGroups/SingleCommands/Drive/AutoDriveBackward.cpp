#include "AutoDriveBackward.h"
#include "Robot.h"
#include "RobotMap.h"

AutoDriveBackward::AutoDriveBackward(int distance)
{
	Requires(Robot::drivebase);
	printf("Auto Drive Backward - %d inches\n", distance);
	m_TARGET_DISTANCE = Robot::drivebase->ConvertInchesToEncoder(distance);
}

void AutoDriveBackward::Initialize()
{
	Robot::drivebase->ResetEncoderPosition();
}

void AutoDriveBackward::Execute()
{
	Robot::drivebase->DriveTankGyro(-AUTON_DRIVE_SPEED,0); //use Gyro Corrected DriveTank
	//Robot::drivebase->DriveTank(-AUTON_DRIVE_SPEED,0); //use old DriveTank
}

bool AutoDriveBackward::IsFinished()
{
	float distanceTraveled = Robot::drivebase->ReturnEncoderDistance();
	//printf("distance: %f\n", distanceTraveled);
	if (distanceTraveled <= -m_TARGET_DISTANCE) { //going negative
		return true;
	} else if (distanceTraveled >= m_TARGET_DISTANCE) { //going positive
		return true;
	}
	return false;
}

void AutoDriveBackward::End()
{
	Robot::drivebase->DriveTank(0,0); //Stop
}

void AutoDriveBackward::Interrupted()
{
	End();
}
