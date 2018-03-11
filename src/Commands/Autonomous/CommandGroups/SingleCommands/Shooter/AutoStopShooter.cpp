#include "AutoStopShooter.h"
#include "Robot.h"

AutoStopShooter::AutoStopShooter()
{
	Requires(Robot::shooter); //requires the shooter subsystem
}

void AutoStopShooter::Initialize()
{
	SmartDashboard::PutString("Shooter Running","initfalse");
}

void AutoStopShooter::Execute()
{
	Robot::shooter->StopShooter();
	SmartDashboard::PutString("Shooter Running","false");
}

bool AutoStopShooter::IsFinished()
{
	return true;
}

void AutoStopShooter::End()
{
}

void AutoStopShooter::Interrupted()
{
	End();
}
