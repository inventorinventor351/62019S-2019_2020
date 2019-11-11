#include "main.h"

void disabled() {



}

int autonCount = 0;

void lcdScroll() {

	if(autonCount < 0)
		autonCount = 5;

	else if(autonCount > 5)
		autonCount = 0;

	switch(autonCount) {

		case 0:
			lcd::set_text(1, "blue small zone 6");
			break;

		case 1:
			lcd::set_text(1, "red small zone 6");
			break;

		case 2:
			lcd::set_text(1, "one cube safety");
			break;

		case 3:
			lcd::set_text(1, "blue small zone 5");
			break;

		case 4:
			lcd::set_text(1, "red small zone 5");
			break;

		case 5:
			lcd::set_text(1, "no auton");
			break;

		default:
			lcd::set_text(1, "how did you mess up");
			break;

	}

}

void on_left_pressed() {

	autonCount--;
	lcdScroll();

}

void on_center_pressed() {

	autonCount = autonCount;
	lcd::shutdown();

}

void on_right_pressed() {

	autonCount++;
	lcdScroll();

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

void competition_initialize() {

	lcd::initialize();
	lcd::set_text(0, "Choose auton");
	lcdScroll();
	lcd::register_btn0_cb(on_left_pressed);
	lcd::register_btn1_cb(on_center_pressed);
	lcd::register_btn2_cb(on_right_pressed);

}

void autonomous() {

    if(autonCount == 0)
    	blueSmallZone6();

    else if(autonCount == 1)
    	redSmallZone6();
    
    else if(autonCount == 2)
    	oneCubeSafety();

	else if(autonCount == 3)
    	blueSmallZone5();

    else if(autonCount == 4)
    	redSmallZone5();

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
			runIntk(-70);

		else if(master.get_digital(E_CONTROLLER_DIGITAL_L1) || trayPot.get_value() > 2500)
			runIntk(0);

		else
			runIntk(20);

		if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {

			intake1.set_brake_mode(E_MOTOR_BRAKE_COAST);
			intake2.set_brake_mode(E_MOTOR_BRAKE_COAST);
			tray.setError(trayPot.get_value() - 3930);
			runTray(tray.runPID());

		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)) {

			intake1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
			intake2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
			tray.setError(trayPot.get_value() - 1730);
			runTray(tray.runPID());

		}

		else {

			intake1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
			intake2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
			tray.setError(0);
			runTray(tray.runPID());

		}

	}

}