#include "main.h"

void disabled() {



}

void initialize() {
	
	leftBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);
	leftBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);
	rightBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);
	rightBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);
	intake1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	intake2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	tray.set_brake_mode(E_MOTOR_BRAKE_HOLD);

}

void competition_initialize() {



}


void autonomous() {

	resetLeftBase();
	resetRightBase();

	blueBigZone();

}

void opcontrol() {

	while (true) {

		runLeftBase(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) * 100 / 127);
		runRightBase(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) * 100 / 127);

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
			runIntk(85);

		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
			runIntk(-50);

		else
			runIntk(0);

		if(master.get_digital(E_CONTROLLER_DIGITAL_L1))
			runTray(-50);

		else if(master.get_digital(E_CONTROLLER_DIGITAL_L2))
			runTray(75);

		else
			runTray(0);

	}

}