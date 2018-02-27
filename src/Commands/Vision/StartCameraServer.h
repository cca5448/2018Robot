#ifndef CMD_STARTCAMERASERVER_H_
#define CMD_STARTCAMERASERVER_H_

#include "Commands/Command.h"
#include "WPILib.h"

class StartCameraServer: public Command
{
	public:
		StartCameraServer();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
