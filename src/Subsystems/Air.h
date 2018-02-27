#ifndef SUBS_AIR_H_
#define SUBS_AIR_H_

#include "WPILib.h"

class Air: public Subsystem
{
	private:
		Compressor * Compy;
	public:
		Air();
		void InitDefaultCommand();
		void Start();
		bool IsCutoffPressure();
		bool IsEnabled();
		double GetCompressorCurrent();
		void ShooterUp(bool IsUp);
		bool IsShooterUp();
};

#endif
