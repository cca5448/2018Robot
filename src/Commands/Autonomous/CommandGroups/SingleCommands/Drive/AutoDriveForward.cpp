#include "AutoDriveForward.h"
#include "Robot.h"
#include "RobotMap.h"

AutoDriveForward::AutoDriveForward(int distance)
{
	Requires(Robot::drivebase);
	printf("Auto Drive Forward - %d inches\n", distance);
	m_TARGET_DISTANCE = Robot::drivebase->ConvertInchesToEncoder(distance);
}

void AutoDriveForward::Initialize(){
	Robot::drivebase->ResetEncoderPosition();
}

void AutoDriveForward::Execute(){
	Robot::drivebase->DriveTankGyro(AUTON_DRIVE_SPEED,0);
}

bool AutoDriveForward::IsFinished(){
	float distanceTraveled = Robot::drivebase->ReturnEncoderDistance();
	//printf("distance: %f\n", distanceTraveled);
	if (distanceTraveled <= -m_TARGET_DISTANCE) { //going negative
		return true;
	} else if (distanceTraveled >= m_TARGET_DISTANCE) { //going positive
		return true;
	}
	return false;
}

void AutoDriveForward::End(){
	Robot::drivebase->DriveTank(0,0);
}

void AutoDriveForward::Interrupted(){
	End();
}
