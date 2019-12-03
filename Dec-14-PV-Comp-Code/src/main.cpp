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

    Task trayControl (trayTask, (void*)"PROS", "PID Controlled Tray");
    Task armsControl (armsTask, (void*)"PROS", "PID Controlled Arms");

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

        if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
            runRollers(100);

        else if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
            runRollers(-100);

        else
            runRollers(0);

        if(master.get_digital(E_CONTROLLER_DIGITAL_L1))
            trayTarget = TRAY_FULLY_OUT;

        else if(master.get_digital(E_CONTROLLER_DIGITAL_L2))
            trayTarget = TRAY_FULLY_IN;

        else if(armPot.get_value() > 1250 && trayPot.get_value() < 1400)
            trayTarget = TRAY_OUT_OF_THE_WAY;

        if(master.get_digital(E_CONTROLLER_DIGITAL_DOWN))
            armsTarget = ARMS_FULLY_DOWN;
        
        else if(master.get_digital(E_CONTROLLER_DIGITAL_B))
            armsTarget = ARMS_FULLY_UP;

        else
            armsTarget = armPot.get_value();        

        Task::delay_until(&now, 100);

        std::cout << armsTarget - armPot.get_value() << std::endl;

    }

}
