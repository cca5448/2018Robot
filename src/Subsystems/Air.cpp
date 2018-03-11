#include "WPILib.h"
#include "Commands/Air/LowerShooter.h"
#include "Commands/Air/RaiseShooter.h"
#include "Air.h"
#include "../RobotMap.h"

Air::Air() : Subsystem("Air")
{
	Compy = new Compressor(0);
	Compy->SetClosedLoopControl(true);
	//Compy->SetClosedLoopControl(false);

	//Start();
}

void Air::InitDefaultCommand()
{
	//SetDefaultCommand(new DoSomething());
}

void Air::Start()
{
	Compy->Start();
}

bool Air::IsCutoffPressure()
{
	bool pressureSwitch = Compy->GetPressureSwitchValue();
	return pressureSwitch;
}

bool Air::IsEnabled()
{
	bool enabled = Compy->Enabled();
	return enabled;
}

double Air::GetCompressorCurrent()
{
	double current = Compy->GetCompressorCurrent();
	return current;
}

void Air::ShooterUp(bool IsUp)
{
	Solenoid shooterSolenoid {SOL_SHOOTER_UP};
	shooterSolenoid.Set(!IsUp);
}

bool Air::IsShooterUp()
{
	Solenoid shooterSolenoid {SOL_SHOOTER_UP};
	bool up = !shooterSolenoid.Get();
	return up;
}
