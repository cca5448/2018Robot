#ifndef CMD_STOPSHOOTER_H_
#define CMD_STOPSHOOTER_H_

#include "Commands/Command.h"
#include "WPILib.h"

class StopShooter: public Command
{
	public:
		StopShooter();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
