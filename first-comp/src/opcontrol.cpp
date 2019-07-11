#include "main.h"

void opcontrol() {

	

	while (true) {

		leftBase1.move_velocity(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) * 200 / 127);
		leftBase2.move_velocity(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) * 200 / 127);
		rightBase1.move_velocity(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) * 200 / 127);
		rightBase2.move_velocity(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) * 200 / 127);

		if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {

			runLift(100);

		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {

			runLift(-100);

		}

		else {

			runLift(0);

		}

	}

}
