#include "WPILib.h"
#include "VictorSP.h"
//#include "Commands/Intake/StartCollector.h"
//#include "Commands/Intake/StopCollector.h"
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

void Intake::IntakeFwd()
{
	intake_motor_left->Set(MOT_INTAKE_SPEED_DEF);
	intake_motor_right->Set(-MOT_INTAKE_SPEED_DEF);
}

void Intake::IntakeRev()
{
	intake_motor_left->Set(MOT_INTAKE_SPEED_DEF);
	intake_motor_right->Set(-MOT_INTAKE_SPEED_DEF);
}

void Intake::IntakeStop()
{
	intake_motor_left->Set(0.0);
	intake_motor_right->Set(0.0);
}

bool Intake::IsIntakeRunning()
{
	//if (collector_motor->Get() > 0) return true;
	return false;
}
