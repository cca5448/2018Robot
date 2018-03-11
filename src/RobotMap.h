/*
* RobotMap defines motor and sensor ports and buttons/axis for the robot.
* This is for ease of use and to abstract the functions from the io names
*/

#ifndef ROBOTMAP_H_
#define ROBOTMAP_H_

//Robot Constants for decision making
static const float GYRO_KP = 0.03;
const unsigned short AUTON_MODE_MAX = 3;
const float AUTON_DRIVE_SPEED = 0.25; //speed to drive in auton mode
const float AUTON_TURN_SPEED = 0.25;
const float JOYSTICK_DEADZONE = 0.25; //dead zone
const float JOYSTICK_RAMP_POWER = 1.1; //speed ramp power - this is for proportionalAxis

//CAN IDs - DriveBase
const unsigned short MOT_DRV_LF			= 1; //Speed Controller 1 is Left Front
const unsigned short MOT_DRV_LR			= 2; //Speed Controller 2 is Left Rear
const unsigned short MOT_DRV_RF			= 3; //Speed Controller 3 is Right Front
const unsigned short MOT_DRV_RR			= 4; //Speed Controller 4 is Right Rear
//CAN IDs - Pigeon IMU
const unsigned short IMU_CAN_ID			= 60; //Which CAN ID is the IMU at (or which controller CAN ID)
//CAN IDs - Shooter
const unsigned short MOT_SHOOTER_L		= 6;
const unsigned short MOT_SHOOTER_R		= 7;

//PWM IDs
const unsigned short MOT_INTAKE_LOAD	= 9; //Load belts
const unsigned short MOT_INTAKE_L		= 1; //Left Intake
const unsigned short MOT_INTAKE_R		= 2; //Right Intake
const unsigned short MOT_CLIMB			= 4; //PWM Pin for Climber

//default motor speeds
const float MOT_INTAKE_SPEED_DEF		= 0.5; //Speed of Intake motors
const float MOT_LOAD_BELT_SPEED_DEF		= 1.0; //Speed of load belt
const float MOT_SHOOTER_SPEED_HIGH_DEF	= 1.0; //Speed of shooter in high
const float MOT_SHOOTER_SPEED_LOW_DEF	= 0.65; //Speed of shooter in low
const float MOT_CLIMB_SPEED_DEF			= 1.0; //Speed of Climber

//Joysticks
const unsigned short JOY_DRIVE_THROT	= 0; //USB Port Driver Joystick left (throttle)
const unsigned short JOY_DRIVE_STEER	= 1; //USB Port Driver Joystick right (steering)
const unsigned short JOY_OPER			= JOY_DRIVE_STEER; //Which stick has the right buttons
const unsigned short JOY_OTHER			= JOY_DRIVE_THROT; //Which stick has the left buttons

//Driver Stick
const unsigned short JOY_DRV_AXIS_THROT	= 1; //Axis for Throttle
const unsigned short JOY_DRV_AXIS_STEER	= 0; //Axis for Steering

//Left set of buttons (Throttle Stick)
const unsigned short BTN_INTAKE_IN = 3; //forward intake
const unsigned short BTN_INTAKE_STOP = 4; //stop intake
const unsigned short BTN_INTAKE_OUT = 5; //reverse intake
const unsigned short BTN_AUTON_PREV	= 7; //previous auton
const unsigned short BTN_AUTON_NEXT	= 8; //next auton

//Right set of buttons (Steer Stick)
const unsigned short BTN_CLIMB_DOWN		= 14; //forward climber
const unsigned short BTN_CLIMB_UP		= 15; //reverse climber
const unsigned short BTN_CLIMB_STOP		= 8; //stop climber
const unsigned short BTN_CAM_TOGGLE		= 5; //toggle camera
const unsigned short BTN_SHOOTER_ADV	= 1; //shooter advance (intake lift)
const unsigned short BTN_SHOOTER_START	= 2; //shooter start
const unsigned short BTN_SHOOTER_STOP	= 3; //shooter stop
const unsigned short BTN_SHOOTER_UP		= 4; //shooter lift toggle

//Solonoids for pneumatics
const unsigned short SOL_SHOOTER_UP		= 0; //Shooter Up/Down
const unsigned short SOL_INTAKE_IN		= 3; //Intake arms together
#endif
