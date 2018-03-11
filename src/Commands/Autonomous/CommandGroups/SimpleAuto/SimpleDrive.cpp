#include <Commands/Autonomous/CommandGroups/SingleCommands/Drive/AutoDriveBackward.h>
#include "SimpleDrive.h"
#include "../SingleCommands/Drive/AutoDriveForward.h"

SimpleDrive::SimpleDrive()
{
	AddSequential(new AutoDriveBackward(93));
}
