#include "SimpleDrive.h"
#include "../SingleCommands/Drive/AutoDriveForward.h"
#include "../SingleCommands/Drive/AutoDriveBackward.h"

SimpleDrive::SimpleDrive()
{
	AddSequential(new AutoDriveBackward(93));
}
