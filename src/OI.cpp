#include <math.h>
#include "OI.h"
#include "RobotMap.h"
//#include "Commands/Climber/StartClimberUp.h"
//#include "Commands/Climber/StartClimberDown.h"
//#include "Commands/Climber/StopClimber.h"
//#include "Commands/Vision/CameraToggle.h"
//#include "Commands/Air/LowerShooter.h"
//#include "Commands/Air/RaiseShooter.h"
#include "Commands/Air/ToggleShooter.h"
#include "Commands/Shooter/StartShooter.h"
#include "Commands/Shooter/StopShooter.h"
#include "Commands/Shooter/AdvanceShooter.h"
#include "Commands/Shooter/AdvanceShooterStop.h"

float DeadZone(float axisVal)
{
	//if the axisVal is in the deadzone defined in robotmap.h, return 0.0 instead
	if (axisVal >= -JOYSTICK_DEADZONE && axisVal <= JOYSTICK_DEADZONE) {
		return 0.0;
	}
	return axisVal;
}

float SteeringDeadZone(float uval)
{
	float f_absval, f_offset, f_uval, f_pow;
    //if we are less than 0, then save an inversion for the end
	float invert = 1.0;
	if (uval < 0) invert = -1.0;
	//get the abs of the value for maths
	f_absval = fabs(uval);

	f_offset = 1-JOYSTICK_DEADZONE;
	f_uval = f_absval-1;
	//divide by the offset (1-deadzone)
	f_uval /= f_offset;
	//add 1
	f_uval += 1.0;

	//now make it either positive or negative depending on what came in
	f_uval *= invert;
	return f_uval;
}

float RampingDeadZone(float uval)
{
	//This uses math to ramp the throttle starting at the deadzone edge, rather than
	//just starting at the value of the end of the deadzone
	float f_absval, f_offset, f_uval, f_pow;
	float invert = 1.0;
	if (uval < 0) invert = -1.0;
	f_absval = fabs(uval);
	//SmartDashboard::PutNumber("f_absval",f_absval);
	f_offset = 1+JOYSTICK_DEADZONE;
	//SmartDashboard::PutNumber("f_offset",f_offset);
	f_uval = f_absval;
	f_uval *= f_offset;
	//SmartDashboard::PutNumber("f_uval1",f_uval);
	f_uval -= JOYSTICK_DEADZONE;
	//SmartDashboard::PutNumber("f_uval2",f_uval);
	f_pow = f_offset * JOYSTICK_RAMP_POWER;
	//SmartDashboard::PutNumber("f_pow",f_pow);
	f_uval = pow(f_uval,f_pow);
	//SmartDashboard::PutNumber("f_uval3",f_uval);
	f_uval *= invert;
	//SmartDashboard::PutNumber("uval",f_uval);
	return f_uval;

	/*
	 * https://www.desmos.com/calculator
	 * y=(xn-a)^mn //formula for speed ramp
	 * m=1.5 //ramp power of 1.5 (normal 1.1-1.8)
	 * a=0.3 //deadzone of 0.3
	 * n=1+a (multiplier to account for dead zone)
	 */
}

float InputShape(float userValue)
{
	double iUserValue;
	iUserValue = (double)userValue * 127;
	iUserValue += 127;
	//iUserValue = inputShape[iUserValue];
	//SmartDashboard::PutNumber("iUserValue",iUserValue);
	userValue = iUserValue - 127;
	userValue /= 127;
	return userValue;
}

OI::OI()
{
	//constants are from RobotMap.h
	//joysticks
	driver_stick_throttle = new Joystick(JOY_DRIVE_THROT);
	driver_stick_steer = new Joystick(JOY_DRIVE_STEER);
	r_buttons = new Joystick(JOY_OPER);
	l_buttons = new Joystick(JOY_OTHER);

	//left button definitions
	//intake_in_btn = new JoystickButton(l_buttons,BTN_INTAKE_IN);
	//intake_stop_btn = new JoystickButton(l_buttons,BTN_INTAKE_STOP);
	//intake_out_btn = new JoystickButton(l_buttons,BTN_INTAKE_OUT);
	auton_next = new JoystickButton(l_buttons,BTN_AUTON_NEXT);
	auton_prev = new JoystickButton(l_buttons,BTN_AUTON_PREV);

	//right button definitions
	climber_up = new JoystickButton(r_buttons,BTN_CLIMB_UP);
	climber_down = new JoystickButton(r_buttons,BTN_CLIMB_DOWN);
	climber_stop = new JoystickButton(r_buttons,BTN_CLIMB_STOP);
	//camera_toggle = new JoystickButton(r_buttons,BTN_CAM_TOGGLE);
	shooter_toggle_btn = new JoystickButton(r_buttons,BTN_SHOOTER_UP);
	shooter_stop_btn = new JoystickButton(r_buttons,BTN_SHOOTER_STOP);
	shooter_start_btn = new JoystickButton(r_buttons,BTN_SHOOTER_START);
	shooter_adv_btn = new JoystickButton(r_buttons,BTN_SHOOTER_ADV);


	//auton_next->ToggleWhenPressed(new NextAuton()); //Next Auton Mode
	//auton_prev->ToggleWhenPressed(new PrevAuton()); //Prev Auton Mode
	//camera_toggle->ToggleWhenPressed(new CameraToggle());

	//climber buttons
	//climber_up->ToggleWhenPressed(new StartClimberUp());
	//climber_down->ToggleWhenPressed(new StartClimberDown());
	//climber_stop->ToggleWhenPressed(new StopClimber());

	//shooter button actions
	shooter_toggle_btn->WhenPressed(new ToggleShooter());
	shooter_stop_btn->WhenPressed(new StopShooter());
	shooter_start_btn->WhenPressed(new StartShooter());
	shooter_adv_btn->WhenPressed(new AdvanceShooter());
	shooter_adv_btn->WhenReleased(new AdvanceShooterStop());
}

//method will return the drive throttle axis
double OI::GetThrottleAxis(){
	//float m_throttle = DeadZone(driver_stick_throttle->GetRawAxis(JOY_DRV_AXIS_THROT));
	//SmartDashboard::PutNumber("Throttle",m_throttle);
	return -(InputShape(DeadZone(driver_stick_throttle->GetRawAxis(JOY_DRV_AXIS_THROT))));
}
//method will return the drive steer axis
double OI::GetSteerAxis(){
	//float m_steer = SteeringDeadZone(driver_stick_steer->GetRawAxis(JOY_DRV_AXIS_STEER));
	//SmartDashboard::PutNumber("Steer",m_steer);
	return -(InputShape(DeadZone(driver_stick_steer->GetRawAxis(JOY_DRV_AXIS_STEER))));
}

