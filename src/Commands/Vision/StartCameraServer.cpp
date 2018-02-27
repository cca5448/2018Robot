#include <Commands/Vision/StartCameraServer.h>
#include "Robot.h"

StartCameraServer::StartCameraServer()
{
	Requires(Robot::vision);
}

void StartCameraServer::Initialize()
{
}

void StartCameraServer::Execute()
{
//	std::thread visionThread(std::bind(&Robot::vision->MultiVisionThread(),v));
//	visionThread.detach();
	Robot::vision->MultiCamServer();
}

bool StartCameraServer::IsFinished()
{
	return false;
}

void StartCameraServer::End()
{
}

void StartCameraServer::Interrupted()
{
	End();
}

