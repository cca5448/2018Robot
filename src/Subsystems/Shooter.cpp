#include "WPILib.h"
#include <ctre/Phoenix.h>
//#include "Commands/Shooter/StartShooter.h"
#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() : Subsystem("Shooter")
{
	//SmartDashboard::PutString("Shooter Speed",std::to_string(Robot::setup->SDB_ReturnShooterSpeed()));
	shooter_motor_left = new TalonSRX(MOT_SHOOTER_L);
	shooter_motor_right = new TalonSRX(MOT_SHOOTER_R);
	shooter_up = true;
}

void Shooter::InitDefaultCommand()
{
	//SetDefaultCommand();
}

bool Shooter::StartShooter(float speed)
{
	float left = speed;
	float right = speed;
	left = Ceiling(left, 1.0);
	right = Ceiling(right, 1.0);

	shooter_motor_left->Set(ControlMode::PercentOutput, left);
	shooter_motor_right->Set(ControlMode::PercentOutput, -1. * right);

	//setFeedbackDevice(FeedbackDevice.QuadEncoder); //Set the feedback device that is hooked up to the talon
	//talon.setPID(0.5, 0.001, 0.0); //Set the PID constants (p, i, d)
	//talon.enableControl(); //Enable PID control on the talon

	//shooter_motor->Set(speed);
	//SmartDashboard::PutBoolean(SDB_SHOOTER_LED_ID,true);
	//shooter_motor->Set(Robot::setup->SDB_ReturnShooterSpeed());
	//shooter_motor->Set(MOT_SHOOTER_SPEED_DEF);
	return true;  //return true when shooter has started
}

void Shooter::StartShooterHigh()
{
	float left = MOT_SHOOTER_SPEED_HIGH_DEF;
	float right = MOT_SHOOTER_SPEED_HIGH_DEF;
	left = Ceiling(left, 1.0);
	right = Ceiling(right, 1.0);

	printf("Shooter is high, start at speed %f\n", MOT_SHOOTER_SPEED_HIGH_DEF);
	//shooter_motor_left->Set(ControlMode::PercentOutput, left);
	//shooter_motor_right->Set(ControlMode::PercentOutput, -1. * right);
}

void Shooter::StartShooterLow()
{
	float left = MOT_SHOOTER_SPEED_LOW_DEF;
	float right = MOT_SHOOTER_SPEED_LOW_DEF;
	left = Ceiling(left, 1.0);
	right = Ceiling(right, 1.0);

	printf("Shooter is low, start at speed %f\n", MOT_SHOOTER_SPEED_LOW_DEF);
	//shooter_motor_left->Set(ControlMode::PercentOutput, left);
	//shooter_motor_right->Set(ControlMode::PercentOutput, -1. * right);
}

void Shooter::StopShooter()
{
	printf("Shooter stop\n");
	//shooter_motor_left->Set(ControlMode::PercentOutput, 0);
	//shooter_motor_right->Set(ControlMode::PercentOutput, 0);
}

float Shooter::GetShooterSpeed()
{
	//This just gets the value we set the controller to, no encoders.
	//return shooter_motor_left->Get();
	return 0.0;
}



bool Shooter::IsShooterRunning()
{
	//if (shooter_motor_left->Get() > 0 ) return true;
	return false;
}

double Shooter::Average(double val1, double val2)
{
	return ( val1+ val2 / 2);
}

double Shooter::Ceiling(double value, double peak)
{
	if (value < -peak)
		return -peak;
	if (value > +peak)
		return +peak;
	return value;
}

bool Shooter::IsShooterUp()
{
	if (Shooter::shooter_up == true) return true;
	return false;
}
