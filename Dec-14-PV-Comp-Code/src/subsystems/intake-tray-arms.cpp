#include "main.h"

void runIntake(double percVolt) {

    intake1.move_voltage(percVolt * 12000 / 100);
    intake2.move_voltage(percVolt * 12000 / 100);

}

void runTray(double percVolt) {

    tray.move_voltage(percVolt * 12000 / 100);

}

void runArms(double percVolt) {

    arms.move_voltage(percVolt * 12000 / 100);

}

double trayTarget = 0;

void trayTask(void* param) {

    std::uint_least32_t now = millis();

    PID trayPID (0, 0, 0);
    trayPID.setMaxOutput(100);

    while(true) {

        trayPID.setError(trayTarget - trayPot.get_value());
        trayPID.setSystemVar(trayPot.get_value());

        runTray(trayPID.runPID());

        Task::delay_until(&now, 1);

    }

}

double armsTarget = 0;

void armsTask(void* param) {

    std::uint_least32_t now = millis();

    PID armsPID (0, 0, 0);
    armsPID.setMaxOutput(100);

    while(true) {

        armsPID.setError(armsTarget - armPot.get_value());
        armsPID.setSystemVar(armPot.get_value());

        runTray(armsPID.runPID());

        Task::delay_until(&now, 1);

    }
    
}