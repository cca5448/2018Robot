#include "Autonomous.h"
#include "Robot.h"
//#include "CommandGroups/SimpleAuto.h"

#include "CommandGroups/SingleCommands/Drive/AutoDriveBackward.h"
#include "CommandGroups/SingleCommands/Drive/AutoDriveForward.h"
#include "CommandGroups/SingleCommands/Drive/AutoDriveTurnLeft.h"
#include "CommandGroups/SingleCommands/Drive/AutoDriveTurnRight.h"
#include "CommandGroups/SingleCommands/Drive/AutoResetEncoder.h"
//#include "CommandGroups/Turn.h"
//#include "CommandGroups/StartShooter.h"
//#include "CommandGroups/Aim.h"
//#include "CommandGroups/FeedFuel.h"

#include "CommandGroups/FinishAuto.h"

//#include "CommandGroups/DriveToGear.h"

Autonomous::Autonomous(int mode)
{
	Requires(Robot::drivebase);
	m_AUTON_MODE = mode;
	SmartDashboard::PutNumber("Auton Mode",m_AUTON_MODE);

	bool GameSpecificAuton = false;
	std::string FMSGameData;
	FMSGameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	bool mySwitchLeft = false;
	bool scaleLeft = false;
	bool farSwitchLeft = false;
	bool deliverCube = false; //SmartDashboard::GetBoolean("DB/3");

	if (FMSGameData.length > 0) {
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
			printf("CLU: Flynn told me to do nothing.");
			break;
		case 1: //drive forward to baseline
			SmartDashboard::PutString("Auton","Drive Forward To Baseline");
			printf("CLU: Driving forward to baseline!");
			AddSequential(new AutoDriveForward(65));
			break;
		case 2: //left start, drive forward to baseline, turn right
			SmartDashboard::PutString("Auton","Left Start, Drive Fwd, Turn and deliver cube if needed");
			AddSequential(new AutoDriveForward(90));
			if (mySwitchLeft) { //if the Switch is on this side, turn and deliver a cube
				printf("CLU: Turning right to goto switch.")
				AddSequential(new AutoDriveTurnRight(90));
				AddSequential(new AutoResetEncoder());
				AddSequential(new AutoDriveForward(24));  //could use ultrasonic sensor here!
			} else {
				printf("CLU: The switch is too far away for me to reach!");
			}
			if (deliverCube) {
				printf("CLU: Delivering a cube!\n");
				//AddSequential(new AutoShooterStart());
				//AddSequential(new AutoShooterAdvance());
			}
			break;
		case 3: //center start, drive forward to proper side, deliver cube
			SmartDashboard::PutString("Auton","Center Start, Drive Fwd, Turn to correct switch, deliver cube");
			AddSequential(new AutoDriveForward(10)); //drive part way to switch
			if (mySwitchLeft) { //if the switch is on the left, turn left then right
				printf("CLU: going to left side of switch\n");
				AddSequential(new AutoDriveTurnLeft(45)); //turn left
				AddSequential(new AutoDriveForward(72)); //drive forward to be in front of the switch
				AddSequential(new AutoDriveTurnRight(45)); //turn towards the switch
				AddSequential(new AutoDriveForward(20)); //drive forward to fenc. could use ultrasonic sensor here!
			} else { //switch is on the right, turn right then left
				printf("CLU: going to right side of switch\n");
				AddSequential(new AutoDriveTurnRight(45)); //turn right
				AddSequential(new AutoDriveForward(72)); //drive forward to be in front of the switch
				AddSequential(new AutoDriveTurnLeft(45)); //turn towards the switch
				AddSequential(new AutoDriveForward(20)); //drive forward to fence. could use ultrasonic sensor here!
			}
			if (deliverCube) {
				printf("CLU: Delivering a Cube!\n");
				//AddSequential(new AutoShooterStart());
				//AddSequential(new AutoShooterAdvance());
			}
			break;
		case 4: //right start, drive forward to baseline, turn left
			SmartDashboard::PutString("Auton","Right Start, Drive Fwd, Turn and deliver cube if needed");
			AddSequential(new AutoDriveForward(90));
			if (mySwitchLeft) { //if the Switch is on this side, turn and deliver a cube
				printf("CLU: Turning left to goto switch.")
				AddSequential(new AutoDriveTurnLeft(90));
				AddSequential(new AutoResetEncoder());
				AddSequential(new AutoDriveForward(24)); //could use ultrasonic sensor here!
			} else {
				printf("CLU: The switch is too far away for me to reach!");
			}
			if (deliverCube) {
				printf("CLU: Delivering a cube!\n");
				//AddSequential(new AutoShooterStart());
				//AddSequential(new AutoShooterAdvance());
			}
			break;
		case 5: //drive forward to baseline
			SmartDashboard::PutString("Auton","Drive forwards to Baseline");
			AddSequential(new AutoDriveForward(65));
			break;
		default: //do nothing
			SmartDashboard::PutString("Auton","Do Nothing (default)");
			printf("CLU: I am unsure what to do!");
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
