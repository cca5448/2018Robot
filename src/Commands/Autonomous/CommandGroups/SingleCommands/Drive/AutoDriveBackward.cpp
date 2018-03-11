#include <Commands/Autonomous/CommandGroups/SingleCommands/Drive/AutoDriveBackward.h>
#include "Robot.h"
#include "RobotMap.h"

AutoDriveBackward::AutoDriveBackward(int distance)
{
	Requires(Robot::drivebase);
	m_TARGET_DISTANCE = Robot::drivebase->ConvertInchesToEncoder(distance);
	SmartDashboard::PutString("ADR",std::to_string(m_TARGET_DISTANCE));
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
	return (Robot::drivebase->ReturnEncoderDistance(0,0,0) <= -m_TARGET_DISTANCE);
}

void AutoDriveBackward::End()
{
	Robot::drivebase->DriveTank(0,0); //Stop
}

void AutoDriveBackward::Interrupted()
{
	End();
}
