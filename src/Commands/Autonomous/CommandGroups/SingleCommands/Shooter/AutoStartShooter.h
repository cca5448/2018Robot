#ifndef CMD_AUTOSTARTSHOOTER_H_
#define CMD_AUTOSTARTSHOOTER_H_

#include "Commands/Command.h"
#include "WPILib.h"

class AutoStartShooter: public Command
{
	public:
		AutoStartShooter();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
