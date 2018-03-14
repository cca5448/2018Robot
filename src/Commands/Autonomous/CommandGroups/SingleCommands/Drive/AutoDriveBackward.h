#ifndef CMDGRP_S_AUTODRIVEBACKWARD_H_
#define CMDGRP_S_AUTODRIVEBACKWARD_H_

#include "Commands/Command.h"
#include "WPILib.h"

class AutoDriveBackward: public Command
{
	private:
		int m_TARGET_DISTANCE;
	public:
		AutoDriveBackward(int distance);
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
