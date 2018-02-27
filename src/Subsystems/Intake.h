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
		void IntakeFwd(); //run intake forward
		void IntakeRev(); //run intake reverse
		void IntakeStop(); //stop intake
		bool IsIntakeRunning(); //check if intake is running
		bool IsIntakeFwd(); //true if intake is forward direction

};

#endif
