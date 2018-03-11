#include "AutoStartShooter.h"
#include "Robot.h"

AutoStartShooter::AutoStartShooter()
{
	Requires(Robot::shooter); //requires the shooter subsystem
	Requires(Robot::air); //requires the air subsystem
}

void AutoStartShooter::Initialize()
{
	//SmartDashboard::PutString("Shooter Running","inittrue");
}

void AutoStartShooter::Execute()
{
	if (Robot::air->IsShooterUp())
	{
		Robot::shooter->StartShooterHigh();
	} else {
		Robot::shooter->StartShooterLow();
	}
	frc::Wait(1);
}

bool AutoStartShooter::IsFinished()
{
	return true;
}

void AutoStartShooter::End()
{
}

void AutoStartShooter::Interrupted()
{
	End();
}
