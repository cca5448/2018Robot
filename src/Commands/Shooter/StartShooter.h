#ifndef CMD_STARTSHOOTER_H_
#define CMD_STARTSHOOTER_H_

#include "Commands/Command.h"
#include "WPILib.h"

class StartShooter: public Command
{
	public:
		StartShooter();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
