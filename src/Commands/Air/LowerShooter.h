#ifndef CMD_LOWERSHOOTER_H_
#define CMD_LOWERSHOOTER_H_

#include "Commands/Command.h"
#include "WPILib.h"

class LowerShooter: public Command
{
	public:
		LowerShooter();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
