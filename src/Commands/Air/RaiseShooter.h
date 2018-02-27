#ifndef CMD_RAISESHOOTER_H_
#define CMD_RAISESHOOTER_H_

#include "Commands/Command.h"
#include "WPILib.h"

class RaiseShooter: public Command
{
	public:
		RaiseShooter();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
