#include "Commands/Shooter/AdvanceShooter.h"
#include "Robot.h"

AdvanceShooter::AdvanceShooter()
{
	//Requires(Robot::shooter); //requires the shooter subsystem
	Requires(Robot::intake); //requires the intake subsystem
}

void AdvanceShooter::Initialize()
{
	//SmartDashboard::PutString("Shooter Running","inittrue");
}

void AdvanceShooter::Execute()
{
	Robot::intake->LoadBeltIn();
	//SmartDashboard::PutString("Shooter Running","true");
	//frc::Wait(1);
}

bool AdvanceShooter::IsFinished()
{
	return true;
}

void AdvanceShooter::End()
{
}

void AdvanceShooter::Interrupted()
{
	End();
}
