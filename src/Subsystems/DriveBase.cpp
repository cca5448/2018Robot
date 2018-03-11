#include <WPILib.h>
#include <ctre/Phoenix.h>
#include "DriveBase.h"
#include "Commands/DriveBase/TeleopTankDrive.h"
#include "../RobotMap.h"


DriveBase::DriveBase() : Subsystem("DriveBase")
{
	lf_motor = new TalonSRX(MOT_DRV_LF);
	lr_motor = new TalonSRX(MOT_DRV_LR);
	rf_motor = new TalonSRX(MOT_DRV_RF);
	rr_motor = new TalonSRX(MOT_DRV_RR);
	pidgey = new PigeonIMU(IMU_CAN_ID);
}



void DriveBase::InitDefaultCommand()
{
	SetDefaultCommand(new TeleopTankDrive());
}

void DriveBase::DriveTank(double throttle, double steer)
{
	float left = throttle - steer;
	float right = throttle + steer;
	left = Ceiling(left, 1.0);
	right = Ceiling(right, 1.0);

	if (++debugPrintLoops > 50 && throttle != 0.0 && steer != 0.0) { //only print output if its not idle
		debugPrintLoops = 0;
		//printf("------------------------------\n", throttle);
		printf("throttle: %f / steer: %f / left: %f / right: %f\n", throttle, steer, left, right);
	}

	/* right side motors need to drive negative to move robot forward */
	lf_motor->Set(ControlMode::PercentOutput, left);
	lr_motor->Set(ControlMode::PercentOutput, left);
	rf_motor->Set(ControlMode::PercentOutput, -1. * right);
	rr_motor->Set(ControlMode::PercentOutput, -1. * right);

}

void DriveBase::DriveTankGyro(double throttle, double steer)
{
	//Get data from pigeon IMU, from PigeonStraight sample code
	PigeonIMU::GeneralStatus genStatus;
	double xyz_dps[3];
	pidgey->GetGeneralStatus(genStatus);
	pidgey->GetRawGyro(xyz_dps);
	PigeonIMU::FusionStatus *stat = new PigeonIMU::FusionStatus();
	pidgey->GetFusedHeading(*stat);
	double currentAngle = stat->heading;
	bool angleIsGood = (pidgey->GetState() == PigeonIMU::Ready) ? true : false;
	double currentAngularRate = xyz_dps[2];

	switch (driveStraight)
	{
		case gyroCorrectIMU:
			if (angleIsGood == false) { //Pigeon isnt connected or responding
				driveStraight = gyroCorrectThrottle;
			} else {
				driveStraight = gyroCorrectIMU;
				driveTargetAngle = currentAngle; //what heading do we want
			}
			break;
		case gyroCorrectThrottle:
			driveStraight = gyroCorrectThrottle;
			break;
	}

	if (steer == 0.0 && driveStraight == gyroCorrectIMU) { //lets use the IMU to drive strait if no steering requested
		steer = (driveTargetAngle - currentAngle) * kPgain - (currentAngularRate) * kDgain;
		double maxThrot = MaxCorrection(throttle, kMaxCorrectionRatio);
		steer = Ceiling(steer, maxThrot);
	} else if (driveStraight == gyroCorrectThrottle) { //just use the throttle like normal
		// do nothing to steering
	}

	float left = throttle - steer;
	float right = throttle + steer;
	left = Ceiling(left, 1.0);
	right = Ceiling(right, 1.0);

	if (++debugPrintLoops > 50 && throttle != 0.0 && steer != 0.0) { //only print output if its not idle
		debugPrintLoops = 0;
		//printf("------------------------------\n", throttle);
		printf("throttle: %f / steer: %f / left: %f / right: %f\n", throttle, steer, left, right);
	}

	/* right side motors need to drive negative to move robot forward */
	lf_motor->Set(ControlMode::PercentOutput, left);
	lr_motor->Set(ControlMode::PercentOutput, left);
	rf_motor->Set(ControlMode::PercentOutput, -1. * right);
	rr_motor->Set(ControlMode::PercentOutput, -1. * right);

}

double DriveBase::Ceiling(double value, double peak)
{
	if (value < -peak)
		return -peak;
	if (value > +peak)
		return +peak;
	return value;
}

float DriveBase::ReturnEncoderDistance(float e1, float e2, float distance)
{
	//lf_motor->SetFeedbackDevice(TalonSRX::QuadEncoder); //tells left talon it has encoder
	//rf_motor->SetFeedbackDevice(TalonSRX::QuadEncoder); //tells right talon it has encoder

	////lf_motor->SetSensorDirection(true);
	////rf_motor->SetSensorDirection(true); See Talon SRX Software Reference section 7.4

	//e1 = lf_motor->GetEncPosition() * -1; //sets e1 to left value
	//e2 = rf_motor->GetEncPosition() * 1; //sets e2 to right value
	//distance = e1;  //set distance to e1
	//distance += e2; //add e2 encoder value
	//distance /= 2; //divide by 2 to get the average
	//SmartDashboard::PutNumber("Encoder Left",e1);
	//SmartDashboard::PutNumber("Encoder Right",e2);
	//SmartDashboard::PutNumber("Encoder Average",distance);
	//SmartDashboard::PutNumber("Encoder Inches",ConvertEncoderToInches(distance));
	//return distance;
	return 0;
}

float DriveBase::ConvertInchesToEncoder(float inches)
{
	inches /= 0.00525;
	return inches;
}

float DriveBase::ConvertEncoderToInches(float encUnits)
{
	encUnits *= 0.00525;
	return encUnits;
}

void DriveBase::ResetEncoderPosition()
{
	//lf_motor->SetPosition(0); //set left to 0
	//rf_motor->SetPosition(0); //set right to 0
}

float DriveBase::ReturnGyroAngle()
{
	//SmartDashboard::PutNumber("Gyro Angle", drive_gyro->GetAngle());
	//return drive_gyro->GetAngle(); //0 to 1.1?
	return 0.0;
}

void DriveBase::ResetGyro()
{
	pidgey->SetFusedHeading(0.0, 10); /* reset heading, angle measurement wraps at plus/minus 23,040 degrees (64 rotations) */
	driveStraight = gyroCorrectIMU;

	printf("Gyro has been reset\n");
	//SmartDashboard::PutNumber("Gyro Resets", rval);
}

void DriveBase::DisplayGyro()
{
	double heading = pidgey->GetFusedHeading();
	SmartDashboard::PutNumber("hdng", heading);  //put the heading into the gyro item
}

void DriveBase::CalibrateGyro()
{
	//int cval;
	//drive_gyro->Calibrate();
	////increment gyro calibrations counter and display it in the dashboard
	//cval = SmartDashboard::GetNumber("Gyro Calibrations",0);
	//cval++;
	//SmartDashboard::PutNumber("Gyro Calibrations", cval);
	//DriveBase::ResetGyro();
}

double DriveBase::MaxCorrection(double forwardThrot, double scalor) {
	/* make it positive */
	if (forwardThrot < 0) {
		forwardThrot = -forwardThrot;
	}
	/* max correction is the current forward throttle scaled down */
	forwardThrot *= scalor;
	/* ensure caller is allowed at least 10% throttle,
	 * regardless of forward throttle */
	if (forwardThrot < 0.10)
		return 0.10;
	return forwardThrot;
}
