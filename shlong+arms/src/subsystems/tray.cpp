#include "main.h"

void pwrTray(double voltPerc) {

    trayMtr.move_voltage(voltPerc * 12000 / 100); //divided percentage by 100 to get ratio and multiply ratio with 12000

}

double trayTarget = TRAY_FULLY_IN; //tray stays in by default
bool trayTaskActive = true; //tray task active by default

void trayTask(void* param) {

    std::uint_least32_t now = millis();

    PID trayPID (0.1, 0.00004, 0);
    trayPID.setOutputBounds(0, 100);

    while(true) {

        if(trayTaskActive) {

        trayPID.setSetPoint(trayTarget);
        trayPID.setSystemVar(trayPot.get_value());

        pwrTray(trayPID.run());

        }

        Task::delay_until(&now, 10); //iterate 100 times a second

    }

}