#ifndef CMD_AUTOADVANCESHOOTER_H_
#define CMD_AUTOADVANCESHOOTER_H_

#include "Commands/Command.h"
#include "WPILib.h"

class AutoAdvanceShooter: public Command
{
	public:
		AutoAdvanceShooter();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
