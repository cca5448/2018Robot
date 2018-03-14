#ifndef CMDGRP_S_AUTOWAIT_H_
#define CMDGRP_S_AUTOWAIT_H_

#include "Commands/Command.h"
#include "WPILib.h"

class AutoWait: public Command
{
	private:
		double m_Seconds;
		bool m_Complete;
	public:
		AutoWait(double seconds);
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
