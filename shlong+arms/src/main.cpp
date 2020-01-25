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
	
	leftBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);
    leftBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);
    rightBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);
    rightBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);
    leftRoller.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    rightRoller.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    trayMtr.set_brake_mode(E_MOTOR_BRAKE_COAST);
    armsMtr.set_brake_mode(E_MOTOR_BRAKE_COAST);

    Task trayControl (trayTask, (void*)"PROS", "PID Controlled Tray");
    Task armsControl (armsTask, (void*)"PROS", "PID Controlled Arms");

}

void competition_initialize() { //display auton selector



}

void autonomous() { //run auton that was selector from auton selector

	redSmallZone();

}


void opcontrol() { //run driver controls

	std::uint_least32_t now = millis();

	int lastArmsPot = armsPot.get_value();

	while (true) { //loop indefinitely

		pwrLeftBase(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) * 100 / 127);
		pwrRightBase(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) * 100 / 127);

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
			pwrRollers(100);

		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
			pwrRollers(-100);

		else
			pwrRollers(0);

		if(master.get_digital(E_CONTROLLER_DIGITAL_L1) && !master.get_digital(E_CONTROLLER_DIGITAL_DOWN)) {

            armsTaskActive = false;
			pwrArms(0);
			trayTaskActive = true;
			trayTarget = TRAY_FULLY_OUT;

		}

        else if(master.get_digital(E_CONTROLLER_DIGITAL_L2) && !master.get_digital(E_CONTROLLER_DIGITAL_DOWN)) {

            armsTaskActive = true;
			armsTarget = ARMS_FULLY_DOWN;
			trayTaskActive = true;
			trayTarget = TRAY_FULLY_IN;

		}

		else
			trayTaskActive = true;

		if(master.get_digital(E_CONTROLLER_DIGITAL_DOWN) && trayPot.get_value() < 700) {

			trayTaskActive = false;
			pwrTray(100);
			lastArmsPot = armsPot.get_value();

		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_DOWN)) {

			trayTaskActive = true;
			trayTarget = TRAY_OUT_OF_THE_WAY;
			lastArmsPot = armsPot.get_value();
			armsTaskActive = true;
			armsTarget = ARMS_FULLY_UP;

		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_B)) {

			if(armsPot.get_value() >= 1270)
				trayTarget = TRAY_OUT_OF_THE_WAY;

			else if(armsPot.get_value() < 1270)
				trayTarget = TRAY_FULLY_IN;
			
			lastArmsPot = armsPot.get_value();
			armsTaskActive = true;
			armsTarget = ARMS_FULLY_DOWN;

		}

		else if(armsPot.get_value() < 1205) {

			armsTarget = ARMS_FULLY_DOWN;
			armsTaskActive = false;
			pwrArms(0);

		}

		else {

			armsTaskActive = true;
			armsTarget = lastArmsPot;

		}

		Task::delay_until(&now, 20); //iterate 50 times per second
		
	}

}
