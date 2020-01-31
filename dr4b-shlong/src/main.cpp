#include "main.h"

double sgn(double x) { //returns sign (-1 or 1) of a number, and 0 for 0

	return (x > 0) - (x < 0); //really cool way of finding sign of a number

}

void betterDelay(int ms) { //delays for a certain number for milliseconds

	std::uint_least32_t now = millis();

    for(int i = 0; i < ms; i++) { //loop for how many milliseconds passed through

       Task::delay_until(&now, 1); //iterate 1000 times per second

    }

}

void disabled() { //disable all subsystems



}

void initialize() { //set motor break modes and start subsystem tasks
	
	leftBase1.set_brake_mode(E_MOTOR_BRAKE_COAST); //set break mode to coast, a.k.a. no background motor control
	leftBase2.set_brake_mode(E_MOTOR_BRAKE_COAST); //set break mode to coast, a.k.a. no background motor control
	rightBase1.set_brake_mode(E_MOTOR_BRAKE_COAST); //set break mode to coast, a.k.a. no background motor control
	rightBase2.set_brake_mode(E_MOTOR_BRAKE_COAST); //set break mode to coast, a.k.a. no background motor control
	leftRoller.set_brake_mode(E_MOTOR_BRAKE_HOLD); //set break mode to hold, a.k.a. background motor control holds motor's current position
	rightRoller.set_brake_mode(E_MOTOR_BRAKE_HOLD); //set break mode to hold, a.k.a. background motor control holds motor's current position
	liftMtr.set_brake_mode(E_MOTOR_BRAKE_COAST); //set break mode to coast, a.k.a. no background motor control
	trayMtr.set_brake_mode(E_MOTOR_BRAKE_COAST); //set break mode to coast, a.k.a. no background motor control

	//Task baseControl (baseVelControl, (void*)"PROS", "FPID Controlled Base"); //allocate memory to run base FPID control in background
	Task trayControl (trayTask, (void*)"PROS", "PID Controlled Tray"); //allocate memory to run tray PID control in background
    Task liftControl (liftTask, (void*)"PROS", "PID Controlled Lift"); //allocate memory to run lift PID control in background

}

void competition_initialize() { //display auton selector

	

}

void autonomous() { //run auton that was selector from auton selector



}


void opcontrol() { //run driver controls

	std::uint_least32_t now = millis();

	while (true) { //loop indefinitely

		pwrLeftBase(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) * 100 / 127);
		pwrRightBase(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) * 100 / 127);

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
			pwrRollers(100);

		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
			pwrRollers(-100);

		else
			pwrRollers(0);

		if(master.get_digital(E_CONTROLLER_DIGITAL_L1))
			pwrTray(100);

		else if(master.get_digital(E_CONTROLLER_DIGITAL_L2))
			pwrTray(-100);

		else
			pwrTray(0);

		if(master.get_digital(E_CONTROLLER_DIGITAL_UP))
			pwrLift(100);

		else if(master.get_digital(E_CONTROLLER_DIGITAL_DOWN))
			pwrLift(-100);

		else
			pwrLift(0);

		Task::delay_until(&now, 100); //iterate 10 times per second
		
	}

}
