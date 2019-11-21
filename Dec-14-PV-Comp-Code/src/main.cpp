#include "main.h"

int autonCount = 0;

void disabled() {



}

void initialize() {

    leftBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);
    leftBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);
    rightBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);
    rightBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);
    intake1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    intake2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    tray.set_brake_mode(E_MOTOR_BRAKE_COAST);
    arms.set_brake_mode(E_MOTOR_BRAKE_COAST);

}

void competition_initialize() {



}

void autonomous() {



}

void opcontrol() {

	std::uint_least32_t now = millis();

    while(true) {

        runLeftBase(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) * 100 / 127);
        runRightBase(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) * 100 / 127);

        Task::delay_until(&now, 1);

    }

}
