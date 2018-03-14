#ifndef MAIN_OI_H_
#define MAIN_OI_H_

#include "WPILib.h"

class OI
{
	public:
		OI();
		double GetThrottleAxis(); //returns the axis to drive the robot
		double GetSteerAxis(); //returns the axis to steer the robot
	private:
		//create joystick objects
		Joystick * driver_stick_throttle; //driver joystick left
		Joystick * driver_stick_steer; //driver joystick right
		Joystick * l_buttons; //left set of buttons
		Joystick * r_buttons; //right set of buttons

		//create buttons for control
		JoystickButton * intake_in_btn; //retract climber
		JoystickButton * intake_out_btn; //extend climber
		JoystickButton * intake_stop_btn; //stop climber
		//climber
		//JoystickButton * climber_up; //retract climber
		//JoystickButton * climber_down; //extend climber
		//JoystickButton * climber_stop; //stop climber
		//JoystickButton * camera_toggle; //switch camera view
		JoystickButton * auton_next; //switch to next auton
		JoystickButton * auton_prev; //switch to prev auton

		JoystickButton * shooter_toggle_btn; //raise or lower shooter
		JoystickButton * shooter_stop_btn; //stop shooter
		JoystickButton * shooter_start_btn; //start shooter
		JoystickButton * shooter_adv_btn; //advance shooter
};

#endif
