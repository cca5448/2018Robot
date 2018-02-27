#ifndef SUBS_SHOOTER_H_
#define SUBS_SHOOTER_H_

#include "WPILib.h"
#include <ctre/Phoenix.h>

class Shooter: public Subsystem
{
	private:
		TalonSRX * shooter_motor_left; //shooter left
		TalonSRX * shooter_motor_right; //shooter right
	public:
		Shooter();
		void InitDefaultCommand();
		bool StartShooter(float speed); //turn on the shooter and return true after delay
		void StopShooter(); //turn off the shooter
		float GetShooterSpeed(); //get the shooter wheel speed
		bool IsShooterRunning(); //check if shooter is running
		double Ceiling(double value, double peak); //Returns the peak value if value is higher
		double Average(double val1, double val2); //Returns the avg of the 2 values
};

#endif
