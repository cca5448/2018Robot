#include "Commands/Shooter/StopShooter.h"
#include "Robot.h"

StopShooter::StopShooter()
{
	Requires(Robot::shooter); //requires the shooter subsystem
}

void StopShooter::Initialize()
{
	SmartDashboard::PutString("Shooter Running","initfalse");
}

void StopShooter::Execute()
{
	Robot::shooter->StopShooter();
	SmartDashboard::PutString("Shooter Running","false");
}

bool StopShooter::IsFinished()
{
	return true;
}

void StopShooter::End()
{
}

void StopShooter::Interrupted()
{
	End();
}
