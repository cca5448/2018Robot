#ifndef CMD_TOGGLESHOOTER_H_
#define CMD_TOGGLESHOOTER_H_

#include "Commands/Command.h"
#include "WPILib.h"

class ToggleShooter: public Command
{
	public:
		ToggleShooter();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
