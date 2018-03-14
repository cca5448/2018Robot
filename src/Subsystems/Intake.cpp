#include <WPILib.h>
#include <ctre/Phoenix.h>
#include "Intake.h"
#include "Commands/DriveBase/TeleopTankDrive.h"
#include "../RobotMap.h"

Intake::Intake() : Subsystem("Intake")
{
	intake_motor_left = new VictorSP(MOT_INTAKE_L);
	intake_motor_right = new VictorSP(MOT_INTAKE_R);
	load_belt_motor = new VictorSP(MOT_INTAKE_LOAD);
}

void Intake::InitDefaultCommand()
{
	//SetDefaultCommand(new StartCollector()); //default command starts collector
}

void Intake::IntakeIn()
{
	intake_motor_left->Set(MOT_INTAKE_SPEED_DEF);
	intake_motor_right->Set(-MOT_INTAKE_SPEED_DEF);
}

void Intake::IntakeOut()
{
	intake_motor_left->Set(MOT_INTAKE_SPEED_DEF);
	intake_motor_right->Set(-MOT_INTAKE_SPEED_DEF);
}

void Intake::IntakeStop()
{
	intake_motor_left->Set(0.0);
	intake_motor_right->Set(0.0);
}

void Intake::LoadBeltIn()
{
	load_belt_motor->Set(-MOT_LOAD_BELT_SPEED_DEF);
}

void Intake::LoadBeltOut()
{
	load_belt_motor->Set(MOT_LOAD_BELT_SPEED_DEF);
}

void Intake::LoadBeltStop()
{
	load_belt_motor->Set(0.0);
}

bool Intake::IsIntakeRunning()
{
	if (intake_motor_left->Get() > 0 or intake_motor_left->Get() < 0) return true;
	return false;
}

bool Intake::IsIntakeFwd()
{
	if (intake_motor_left->Get() > 0) return true;
	return false;
}

bool Intake::IsLoadBeltRunning()
{
	if (load_belt_motor->Get() > 0 or load_belt_motor->Get() < 0) return true;
	return false;
}

bool Intake::IsLoadBeltFwd()
{
	if (load_belt_motor->Get() > 0) return true;
	return false;
}
