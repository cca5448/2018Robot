#include "Commands/Air/RaiseShooter.h"
#include "Robot.h"

RaiseShooter::RaiseShooter()
{
	Requires(Robot::air);
}

void RaiseShooter::Initialize()
{
//	SmartDashboard::PutString("Shooter Up","true");
}

void RaiseShooter::Execute()
{
	Robot::air->ShooterUp(true);
}

bool RaiseShooter::IsFinished()
{
	return true;
}

void RaiseShooter::End()
{
}

void RaiseShooter::Interrupted()
{
	End();
}
