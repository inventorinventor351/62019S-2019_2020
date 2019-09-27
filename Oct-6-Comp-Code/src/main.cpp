#include "main.h"

void disabled() {



}

void initialize() {
	


}

void competition_initialize() {



}


void autonomous() {



}

void opcontrol() {

	while (true) {

		runLeftBase(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) * 100 / 127);
		runRightBase(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) * 100 / 127);

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
			runIntk(100);

		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
			runIntk(-100);

		else
			runIntk(0);

		if(master.get_digital(E_CONTROLLER_DIGITAL_L1))
			runTray(100);

		else if(master.get_digital(E_CONTROLLER_DIGITAL_L2))
			runTray(-100);

		else
			runTray(0);

	}

}