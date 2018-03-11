#include "AutoAdvanceShooterStop.h"
#include "Robot.h"

AutoAdvanceShooterStop::AutoAdvanceShooterStop()
{
	//Requires(Robot::shooter); //requires the shooter subsystem
	Requires(Robot::intake); //requires the intake subsystem
}

void AutoAdvanceShooterStop::Initialize()
{
	//SmartDashboard::PutString("Shooter Running","inittrue");
}

void AutoAdvanceShooterStop::Execute()
{
	Robot::intake->LoadBeltStop();
	//SmartDashboard::PutString("Shooter Running","true");
	//frc::Wait(1);
}

bool AutoAdvanceShooterStop::IsFinished()
{
	return true;
}

void AutoAdvanceShooterStop::End()
{
}

void AutoAdvanceShooterStop::Interrupted()
{
	End();
}
