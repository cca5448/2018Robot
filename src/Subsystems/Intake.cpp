#include <WPILib.h>
#include <ctre/Phoenix.h>
#include "Intake.h"
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


void Intake::LoadBeltIn()
{
	printf("Load Belt In\n");
	//load_belt_motor->Set(-MOT_LOAD_BELT_SPEED_DEF);
}

void Intake::LoadBeltOut()
{
	printf("Load Belt Out\n");
	//load_belt_motor->Set(MOT_LOAD_BELT_SPEED_DEF);
}

void Intake::LoadBeltStop()
{
	printf("Load Belt Stop\n");
	//load_belt_motor->Set(0.0);
}

bool Intake::IsLoadBeltRunning()
{
//	if (load_belt_motor->Get() > 0 or load_belt_motor->Get() < 0) return true;
	return false;
}

void Intake::IntakeIn()
{
	printf("Intake In\n");
//	intake_motor_left->Set(MOT_INTAKE_SPEED_DEF);
//	intake_motor_right->Set(-MOT_INTAKE_SPEED_DEF);
}

void Intake::IntakeOut()
{
	printf("Intake Out\n");
//	intake_motor_left->Set(MOT_INTAKE_SPEED_DEF);
//	intake_motor_right->Set(-MOT_INTAKE_SPEED_DEF);
}

void Intake::IntakeStop()
{
	printf("Intake Stop\n");
//	intake_motor_left->Set(0.0);
//	intake_motor_right->Set(0.0);
}
