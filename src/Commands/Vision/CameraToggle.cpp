#include "Commands/Vision/CameraToggle.h"
#include "Robot.h"

CameraToggle::CameraToggle()
{
	Requires(Robot::vision);
}

void CameraToggle::Initialize()
{
}

void CameraToggle::Execute()
{
	Robot::vision->ToggleCamera();
	printf("switching camera\n");
}

bool CameraToggle::IsFinished()
{
	return true;
}

void CameraToggle::End()
{
}

void CameraToggle::Interrupted()
{
	End();
}
