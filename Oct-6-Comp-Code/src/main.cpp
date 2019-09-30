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




int autonCount = 0;

void lcdScroll() {

    if(autonCount < 0) {

        autonCount = 3;

    }

    else if(autonCount > 3) {

        autonCount = 0;

    }

    switch(autonCount) {

            case 0:
                lcd::set_text(1, "BLUE Big Zone");
                break;

            case 1:
                lcd::set_text(1, "BLUE Small Zone");
                break;

            case 2:
                lcd::set_text(1, "RED Big Zone");
                break;

            case 3:
                lcd::set_text(1, "RED Small Zone");
                break;

        }

}

void on_left_pressed() {

    autonCount--;
    lcdScroll();

}

void on_center_pressed() {

    autonCount = autonCount;
    lcd::shutdown();

}

void on_right_pressed() {

    autonCount++;
    lcdScroll();

}





void competition_initialize() {
    
	lcd::initialize();
    lcd::set_text(0, "choose auton");
    lcdScroll();
    lcd::register_btn0_cb(on_left_pressed);
    lcd::register_btn1_cb(on_center_pressed);
    lcd::register_btn2_cb(on_right_pressed);


}


void autonomous() {

	resetLeftBase();
	resetRightBase();
	tray.tare_position();

	blueSmallZone();

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