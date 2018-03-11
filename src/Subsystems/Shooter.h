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
		bool shooter_up = false; //shooter position variable
		Shooter();
		void InitDefaultCommand();
		bool StartShooter(float speed); //turn on the shooter and return true after delay
		void StartShooterHigh(); //turn the shooter on the high position
		void StartShooterLow(); //turn the shooter on the low position
		void StopShooter(); //turn off the shooter
		void AdvanceShooter(); //run the lift belts to advance the cube into the shooter
		float GetShooterSpeed(); //get the shooter wheel speed
		bool IsShooterRunning(); //check if shooter is running
		bool IsShooterUp(); //check if shooter is in up position
		double Ceiling(double value, double peak); //Returns the peak value if value is higher
		double Average(double val1, double val2); //Returns the avg of the 2 values
};

#endif
