#ifndef CMD_ADVANCESHOOTERSTOP_H_
#define CMD_ADVANCESHOOTERSTOP_H_

#include "Commands/Command.h"
#include "WPILib.h"

class AdvanceShooterStop: public Command
{
	public:
		AdvanceShooterStop();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
