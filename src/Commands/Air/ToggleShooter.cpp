#include "Commands/Air/ToggleShooter.h"
#include "Robot.h"

ToggleShooter::ToggleShooter()
{
	Requires(Robot::air);
}

void ToggleShooter::Initialize()
{
//	SmartDashboard::PutString("Shooter Up","true");
}

void ToggleShooter::Execute()
{
	if(Robot::air->IsShooterUp())
	{
		printf("Shooter Down\n");
		Robot::air->ShooterUp(false);
	} else {
		printf("Shooter Up\n");
		Robot::air->ShooterUp(true);
	}
}

bool ToggleShooter::IsFinished()
{
	return true;
}

void ToggleShooter::End()
{
}

void ToggleShooter::Interrupted()
{
	End();
}
