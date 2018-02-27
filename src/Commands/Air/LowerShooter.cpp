#include "Commands/Air/LowerShooter.h"
#include "Robot.h"

LowerShooter::LowerShooter()
{
	Requires(Robot::air);
}

void LowerShooter::Initialize()
{
//	SmartDashboard::PutString("Shooter Up","true");
}

void LowerShooter::Execute()
{
	Robot::air->ShooterUp(false);
}

bool LowerShooter::IsFinished()
{
	return true;
}

void LowerShooter::End()
{
}

void LowerShooter::Interrupted()
{
	End();
}
