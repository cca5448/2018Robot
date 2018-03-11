#include "AutoDriveForward.h"
#include "Robot.h"
#include "RobotMap.h"

AutoDriveForward::AutoDriveForward(int distance)
{
	Requires(Robot::drivebase);
	printf("Auto Drive Forward - %f inches\n", distance);
	m_TARGET_DISTANCE = Robot::drivebase->ConvertInchesToEncoder(distance);
}

void AutoDriveForward::Initialize(){
	Robot::drivebase->ResetEncoderPosition();
}

void AutoDriveForward::Execute(){
	Robot::drivebase->DriveTankGyro(AUTON_DRIVE_SPEED,0); //use Gyro Corrected DriveTank
	//Robot::drivebase->DriveTank(AUTON_DRIVE_SPEED,0); //use old DriveTank
}

bool AutoDriveForward::IsFinished(){
	return (Robot::drivebase->ReturnEncoderDistance(0,0,0) >= m_TARGET_DISTANCE);
}

void AutoDriveForward::End(){
	Robot::drivebase->DriveTank(0,0); //Stop
}

void AutoDriveForward::Interrupted(){
	End();
}
