#ifndef CMD_CAMERATOGGLE_H_
#define CMD_CAMERATOGGLE_H_

#include "Commands/Command.h"
#include "WPILib.h"

class CameraToggle: public Command
{
	public:
		CameraToggle();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
