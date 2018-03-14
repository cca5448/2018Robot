#include <Commands/Autonomous/CommandGroups/SingleCommands/Common/AutoWait.h>
#include "Robot.h"
#include "RobotMap.h"

AutoWait::AutoWait(double seconds)
{
	m_Seconds = seconds;
	m_Complete = false;
}

void AutoWait::Initialize()
{
}

void AutoWait::Execute()
{
	frc::Wait(m_Seconds);
	m_Complete = true;
}

bool AutoWait::IsFinished()
{
	if (m_Complete) return true;
	return false;
}

void AutoWait::End()
{
}

void AutoWait::Interrupted()
{
	End();
}
