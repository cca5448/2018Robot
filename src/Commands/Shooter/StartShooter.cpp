#include "Commands/Shooter/StartShooter.h"
#include "Robot.h"

StartShooter::StartShooter()
{
	Requires(Robot::shooter); //requires the shooter subsystem
}

void StartShooter::Initialize()
{
	SmartDashboard::PutString("Shooter Running","inittrue");
}

void StartShooter::Execute()
{
	Robot::shooter->StartShooter(.5);
	SmartDashboard::PutString("Shooter Running","true");
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
