#include "Commands/DriveBase/TeleopTankDrive.h"
#include "Robot.h"

TeleopTankDrive::TeleopTankDrive()
{
	Requires(Robot::drivebase); //requires the drivebase subsystem
}

void TeleopTankDrive::Initialize()
{
	//Robot::drivebase->ResetGyro();
}

void TeleopTankDrive::Execute()
{
	Robot::drivebase->DriveTankGyro(Robot::oi->GetThrottleAxis(), Robot::oi->GetSteerAxis());  //This uses the new IMU Gyro Correction
	//Robot::drivebase->DriveTank(Robot::oi->GetThrottleAxis(), Robot::oi->GetSteerAxis());  //This is the old drivetank code
	//Robot::drivebase->ReturnEncoderDistance(0,0,0);
}

bool TeleopTankDrive::IsFinished()
{
	return false;
}

void TeleopTankDrive::End()
{
	Robot::drivebase->DriveTank(0,0); //sets the speed to 0 so doesnt drive or continue driving
}

void TeleopTankDrive::Interrupted()
{
	End();
}

