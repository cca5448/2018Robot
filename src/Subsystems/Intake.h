#ifndef SUBS_INTAKE_H_
#define SUBS_INTAKE_H_

#include "WPILib.h"
#include <ctre/Phoenix.h>

class Intake: public Subsystem
{
	private:
		VictorSP * intake_motor_left; //left intake motor
		VictorSP * intake_motor_right; //right intake motor
		VictorSP * load_belt_motor; //load belt motor
	public:
		Intake();
		void InitDefaultCommand();
		void IntakeIn(); //run intake forward
		void IntakeOut(); //run intake reverse
		void IntakeStop(); //stop intake
		void LoadBeltIn(); //run load belt forward
		void LoadBeltOut(); //run load belt reverse
		void LoadBeltStop(); //stop load belt
		bool IsIntakeRunning(); //check if intake is running
		bool IsIntakeFwd(); //true if intake is forward direction
		bool IsLoadBeltRunning(); //check if load belt is running
		bool IsLoadBeltFwd(); //true if load belt is forward direction
};

#endif
