#include "WPILib.h"
#include "Robot.h"

#include "Commands/Autonomous/Autonomous.h"

//Set all the subsystems to null
OI * Robot::oi = NULL;
DriveBase * Robot::drivebase = NULL;
Vision * Robot::vision = NULL;
Air * Robot::air = NULL;

void Robot::RobotInit(){

	//Create new objects of subsystems
	oi = new OI();
	drivebase = new DriveBase();
	vision = new Vision();
	air = new Air();

/*
	//setup auton drop downs
	//autonchooser = new SendableChooser();
	autonchooser.AddDefault("Do Nothing",new Autonomous(0));
	autonchooser.AddObject("Drive to Baseline",new Autonomous(1));
	autonchooser.AddObject("Left back turn left gear deliver",new Autonomous(2));
	autonchooser.AddObject("Straight back gear deliver",new Autonomous(3));
	autonchooser.AddObject("Right back turn right gear deliver",new Autonomous(4));
	SmartDashboard::PutData("Auto Selector", &autonchooser);
*/

/*
	Compy = new Compressor(0);
	Compy->SetClosedLoopControl(true);
	Compy->Start();
*/

	//other stuff
//	autoncommand = (Command *) autonchooser->GetSelected();
//	int mode = (int) SmartDashboard::GetNumber("DB/Slider 3",0);
//	autoncommand = new Autonomous(mode);
	//drivebase->ResetGyro();
	drivebase->ResetEncoderPosition();

}

void Robot::AutonomousInit(){
	drivebase->ResetGyro();
	drivebase->ResetEncoderPosition();
	double mode = SmartDashboard::GetNumber("cluMode",0.0);
	bool cube = (bool) SmartDashboard::GetBoolean("cluDeliverCube",false);
	//temp set values
	//mode=6;
	//cube=true;
	//end temp values
	printf("AutonomousInit: mode %f, cube %s\n", mode, cube ? "true":"false");
	autoncommand = new Autonomous(mode, cube);
	autoncommand->Start();
}

void Robot::AutonomousPeriodic(){
	Scheduler::GetInstance()->Run(); //continually run the scheduler during auton
	drivebase->DisplayGyro();
}

void Robot::TeleopInit(){
	//autoncommand->Cancel();
	drivebase->ResetGyro();
}

void Robot::TeleopPeriodic(){
	Scheduler::GetInstance()->Run(); //continually run the scheduler during teleop
	drivebase->DisplayGyro();
}

void Robot::TestPeriodic(){
	//lw->Run(); //runs the livewindow during test
}

void Robot::DisabledPeriodic(){
	Scheduler::GetInstance()->Run(); //continually run the scheduler during disabled
	//lw->Run(); //runs the livewindow during test
}

START_ROBOT_CLASS(Robot);
