#ifndef CMD_AUTOADVANCESHOOTERSTOP_H_
#define CMD_AUTOADVANCESHOOTERSTOP_H_

#include "Commands/Command.h"
#include "WPILib.h"

class AutoAdvanceShooterStop: public Command
{
	public:
		AutoAdvanceShooterStop();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
