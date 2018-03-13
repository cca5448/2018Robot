#ifndef CMD_AUTONOMOUS_H_
#define CMD_AUTONOMOUS_H_

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class Autonomous: public CommandGroup
{
	private:
		int m_AUTON_MODE;
		bool m_CUBE;
	public:
		Autonomous(int mode, bool cube);
};

#endif
