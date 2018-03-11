#ifndef CMD_AUTOSTOPSHOOTER_H_
#define CMD_AUTOSTOPSHOOTER_H_

#include "Commands/Command.h"
#include "WPILib.h"

class AutoStopShooter: public Command
{
	public:
		AutoStopShooter();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
