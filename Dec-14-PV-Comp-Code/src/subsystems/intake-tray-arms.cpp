#include "main.h"

void runRollers(double percVolt) {

    intake1.move_voltage(percVolt * 12000 / 100);
    intake2.move_voltage(percVolt * 12000 / 100);

}

void runTray(double percVolt) {

    tray.move_voltage(percVolt * 12000 / 100);

}

void runArms(double percVolt) {

    arms.move_voltage(percVolt * 12000 / 100);

}

double trayTarget = TRAY_FULLY_IN;

void trayTask(void* param) {

    std::uint_least32_t now = millis();

    PID trayPID (0.1, 0.00004, 0);
    trayPID.setMaxOutput(100);

    while(true) {

        trayPID.setError(trayTarget - trayPot.get_value());
        trayPID.setSystemVar(trayPot.get_value());

        runTray(trayPID.runPID());

        Task::delay_until(&now, 10);

    }

}

double armsTarget = ARMS_FULLY_DOWN;
bool armsActive = true;

void armsTask(void* param) {

    std::uint_least32_t now = millis();

    PID armsPID (0.25, 0.0005, 0);
    armsPID.setMaxOutput(100);

    while(true) {

        if(armsActive) {
        
        armsPID.setError(armsTarget - armPot.get_value());
        armsPID.setSystemVar(armPot.get_value());

        runArms(armsPID.runPID());

        }

        Task::delay_until(&now, 10);

    }
    
}