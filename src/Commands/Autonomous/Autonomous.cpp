#include "Autonomous.h"
#include "Robot.h"
//#include "CommandGroups/SimpleAuto.h"

//common
#include "CommandGroups/SingleCommands/Common/AutoWait.h"
//drive
#include "CommandGroups/SingleCommands/Drive/AutoDriveBackward.h"
#include "CommandGroups/SingleCommands/Drive/AutoDriveForward.h"
#include "CommandGroups/SingleCommands/Drive/AutoDriveTurnLeft.h"
#include "CommandGroups/SingleCommands/Drive/AutoDriveTurnRight.h"
#include "CommandGroups/SingleCommands/Drive/AutoResetEncoder.h"
//shooter
//#include "CommandGroups/SingleCommands/Shooter/AutoAdvanceShooter.h"
//#include "CommandGroups/SingleCommands/Shooter/AutoAdvanceShooterStop.h"
//#include "CommandGroups/SingleCommands/Shooter/AutoStartShooter.h"
//#include "CommandGroups/SingleCommands/Shooter/AutoStopShooter.h"
//finish
#include "CommandGroups/FinishAuto.h"

Autonomous::Autonomous(int mode, bool cube)
{
	Requires(Robot::drivebase);
	m_AUTON_MODE = mode;
	m_CUBE = cube;
	SmartDashboard::PutNumber("Auton Mode",m_AUTON_MODE);

	bool GameSpecificAuton = false;
	std::string FMSGameData;
	FMSGameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	bool mySwitchLeft = false;
	bool scaleLeft = false;
	bool farSwitchLeft = false;
	bool deliverCube = cube;

	if ( FMSGameData.length() > 0 ) {
		GameSpecificAuton = true;
		mySwitchLeft = (FMSGameData[0] == 'L') ? true : false;
		scaleLeft = (FMSGameData[1] == 'L') ? true : false;
		farSwitchLeft = (FMSGameData[0] == 'L') ? true : false;
	} else {
		GameSpecificAuton = false;
	}

	switch (m_AUTON_MODE) {
		case 0: //do nothing
			SmartDashboard::PutString("Auton","Do Nothing");
			printf("CLU: Flynn told me to do nothing.\n");
			break;
		case 1: //drive forward to baseline
			SmartDashboard::PutString("Auton","Drive Forward To Baseline");
			printf("CLU: Driving forward to baseline!\n");
			AddSequential(new AutoResetEncoder());
			AddSequential(new AutoDriveForward(125));
			break;
		case 2: //left start, drive forward to baseline, turn right
			SmartDashboard::PutString("Auton","Left Start, Drive Fwd, Turn and deliver cube if needed");
			AddSequential(new AutoResetEncoder());
			AddSequential(new AutoDriveForward(168));
			if (mySwitchLeft) { //if the Switch is on this side, turn and deliver a cube
				printf("CLU: Turning right to goto switch.\n");
				AddSequential(new AutoDriveTurnRight(90));
				AddSequential(new AutoResetEncoder());
				AddSequential(new AutoDriveForward(21));  //could use ultrasonic sensor here!
			} else {
				printf("CLU: The switch is too far away for me to reach!\n");
			}
			if (deliverCube) {
				printf("CLU: Delivering a cube!\n");
				//AddParallel(new AutoStartShooter());
				//AddSequential(new AutoAdvanceShooter());
/*				//Wait 10s and then stop the shooter
				AddSequential(new AutoShooterWait());
				AddParallel(new AutoStopShooter(10));
				AddSequential(new AutoAdvanceShooterStop());
*/
			}
			break;
		case 3: //center start, drive forward to proper side, deliver cube
			SmartDashboard::PutString("Auton","Center Start, Drive Fwd, Turn to correct switch, deliver cube");
			AddSequential(new AutoResetEncoder());
			AddSequential(new AutoDriveForward(15)); //drive part way to switch
			if (mySwitchLeft) { //if the switch is on the left, turn left then right
				printf("CLU: going to left side of switch\n");
				AddSequential(new AutoDriveTurnLeft(-315)); //turn left
				AddSequential(new AutoResetEncoder());
				AddSequential(new AutoDriveForward(74)); //drive forward to be in front of the switch
				AddSequential(new AutoDriveTurnRight(45)); //turn towards the switch
				AddSequential(new AutoResetEncoder());
				AddSequential(new AutoDriveForward(51)); //drive forward to fenc. could use ultrasonic sensor here!
			} else { //switch is on the right, turn right then left
				printf("CLU: going to right side of switch\n");
				AddSequential(new AutoDriveTurnRight(45)); //turn right
				AddSequential(new AutoResetEncoder());
				AddSequential(new AutoDriveForward(74)); //drive forward to be in front of the switch
				AddSequential(new AutoDriveTurnLeft(-315)); //turn towards the switch
				AddSequential(new AutoResetEncoder());
				AddSequential(new AutoDriveForward(51)); //drive forward to fence. could use ultrasonic sensor here!
			}
			if (deliverCube) {
				printf("CLU: Delivering a Cube!\n");
				//AddParallel(new AutoStartShooter());
				//AddSequential(new AutoAdvanceShooter());
/*				//Wait 10s and then stop the shooter
				AddSequential(new AutoShooterWait());
				AddParallel(new AutoStopShooter(10));
				AddSequential(new AutoAdvanceShooterStop());
*/
			}
			break;
		case 4: //right start, drive forward to baseline, turn left
			SmartDashboard::PutString("Auton","Right Start, Drive Fwd, Turn and deliver cube if needed");
			AddSequential(new AutoResetEncoder());
			AddSequential(new AutoDriveForward(168));
			if (mySwitchLeft) { //if the Switch is on this side, turn and deliver a cube
				printf("CLU: Turning left to goto switch.\n");
				AddSequential(new AutoDriveTurnLeft(90));
				AddSequential(new AutoResetEncoder());
				AddSequential(new AutoDriveForward(21)); //could use ultrasonic sensor here!
			} else {
				printf("CLU: The switch is too far away for me to reach!\n");
			}
			if (deliverCube) {
				printf("CLU: Delivering a cube!\n");
				//AddParallel(new AutoStartShooter());
				//AddSequential(new AutoAdvanceShooter());
/*				//Wait 10s and then stop the shooter
				AddSequential(new AutoShooterWait());
				AddParallel(new AutoStopShooter(10));
				AddSequential(new AutoAdvanceShooterStop());
*/

			}
			break;
		case 5: //drive backward to baseline
			SmartDashboard::PutString("Auton","Drive backward to Baseline");
			printf("CLU: Driving backward to baseline!\n");
			AddSequential(new AutoResetEncoder());
			AddSequential(new AutoDriveBackward(125));
			break;
		case 6: //testing
			SmartDashboard::PutString("Auton","Test Auton Mode");
			printf("CLU: Testing Auton!\n");
			AddSequential(new AutoResetEncoder());
			AddSequential(new AutoDriveForward(10));
			if (deliverCube) {
				printf("CLU: Delivering a cube!\n");
				AddSequential(new AutoWait(1));
				AddSequential(new AutoDriveTurnLeft(10));
				AddSequential(new AutoWait(1));
				AddSequential(new AutoResetEncoder());
				AddSequential(new AutoDriveForward(10));
			}
			break;
		default: //do nothing
			SmartDashboard::PutString("Auton","Do Nothing (default)");
			printf("CLU: I am unsure what to do!\n");
			break;
	}

	//Run SimpleAuto sequence
	//AddSequential(new SimpleAuto());

	//Old steamworks stuff for reference
	//Drive to baseline, turn, aim, feed fuel
	//AddSequential(new DriveToBaseline(500));
	//AddSequential(new AutoDriveTurnLeft(75.0));
	//AddParallel(new StartShooter());
	//AddSequential(new Aim());
	//AddSequential(new FeedFuel());

	//Finish Autonomous
	AddSequential(new FinishAuto());
}
