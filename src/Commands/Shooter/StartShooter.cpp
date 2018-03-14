#include "Commands/Shooter/StartShooter.h"
#include "Robot.h"

StartShooter::StartShooter()
{
	Requires(Robot::shooter); //requires the shooter subsystem
	Requires(Robot::air); //requires the air subsystem
}

void StartShooter::Initialize()
{
	//SmartDashboard::PutString("Shooter Running","inittrue");
}

void StartShooter::Execute()
{
	if (Robot::air->IsShooterUp())
	{
		Robot::shooter->StartShooterHigh();
	} else {
		Robot::shooter->StartShooterLow();
	}
	frc::Wait(1);
}

bool StartShooter::IsFinished()
{
	return true;
}

void StartShooter::End()
{
}

void StartShooter::Interrupted()
{
	End();
}
