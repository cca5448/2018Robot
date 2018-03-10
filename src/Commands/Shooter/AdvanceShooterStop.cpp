#include "Commands/Shooter/AdvanceShooterStop.h"
#include "Robot.h"

AdvanceShooterStop::AdvanceShooterStop()
{
	//Requires(Robot::shooter); //requires the shooter subsystem
	Requires(Robot::intake); //requires the intake subsystem
}

void AdvanceShooterStop::Initialize()
{
	//SmartDashboard::PutString("Shooter Running","inittrue");
}

void AdvanceShooterStop::Execute()
{
	Robot::intake->LoadBeltStop();
	//SmartDashboard::PutString("Shooter Running","true");
	//frc::Wait(1);
}

bool AdvanceShooterStop::IsFinished()
{
	return true;
}

void AdvanceShooterStop::End()
{
}

void AdvanceShooterStop::Interrupted()
{
	End();
}
