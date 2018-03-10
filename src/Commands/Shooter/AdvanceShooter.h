#ifndef CMD_ADVANCESHOOTER_H_
#define CMD_ADVANCESHOOTER_H_

#include "Commands/Command.h"
#include "WPILib.h"

class AdvanceShooter: public Command
{
	public:
		AdvanceShooter();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
