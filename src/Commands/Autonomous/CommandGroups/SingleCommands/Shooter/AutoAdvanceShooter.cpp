#include "AutoAdvanceShooter.h"
#include "Robot.h"

AutoAdvanceShooter::AutoAdvanceShooter()
{
	Requires(Robot::shooter); //requires the shooter subsystem
	Requires(Robot::intake); //requires the intake subsystem
}

void AutoAdvanceShooter::Initialize()
{
	//SmartDashboard::PutString("Shooter Running","inittrue");
}

void AutoAdvanceShooter::Execute()
{
	Robot::intake->LoadBeltIn();
	//SmartDashboard::PutString("Shooter Running","true");
	//frc::Wait(1);
}

bool AutoAdvanceShooter::IsFinished()
{
	return true;
}

void AutoAdvanceShooter::End()
{
}

void AutoAdvanceShooter::Interrupted()
{
	End();
}
