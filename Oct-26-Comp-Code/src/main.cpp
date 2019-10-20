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
	tray1.set_brake_mode(E_MOTOR_BRAKE_COAST);
	tray2.set_brake_mode(E_MOTOR_BRAKE_COAST);

}

int autonCount = 0;



void autonomous() {

    if(autonCount == 0)
        blueBigZone();

    if(autonCount == 1)
        blueSmallZone();
    
    if(autonCount == 2)
        redBigZone();

    if(autonCount == 3)
        redSmallZone();

}

void opcontrol() {

	leftBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);
	leftBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);
	rightBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);
	rightBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);
	intake1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	intake2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	tray1.set_brake_mode(E_MOTOR_BRAKE_COAST);
	tray2.set_brake_mode(E_MOTOR_BRAKE_COAST);

	PID tray(0.25, 0, 0);
	tray.maxSpeed = 60;

	while (true) {

		runLeftBase(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) * 100 / 127);
		runRightBase(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) * 100 / 127);

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
			runIntk(85);

		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
			runIntk(-50);

		else
			runIntk(0);

		if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {

			tray.setError(trayPot.get_value() - 3990);
			runTray(tray.runPID());

		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)) {

			tray.setError(trayPot.get_value() - 1730);
			runTray(tray.runPID());

		}

		else {

			tray.setError(0);
			runTray(tray.runPID());

		}

	}

}