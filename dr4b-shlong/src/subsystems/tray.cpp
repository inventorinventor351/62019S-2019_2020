#include "main.h"

void pwrTray(double voltPerc) {

    trayMtr.move_voltage(voltPerc * 12000 / 100); //divided percentage by 100 to get ratio and multiply ratio with 12000

}

double trayTarget = TRAY_FULLY_DOWN; //tray should stay down at start of program execution
bool trayTaskActive = true; //tray task should be active at start of program execution

void trayTask(void* param) {

    std::uint_least32_t now = millis();

    FPID trayPID (0, 0.125, 0.000075, 1); //kF = 0, kP = 0.125, kI = 0.000075, kD = 1
    trayPID.setOutputBounds(0, 100); //minOutput = 0%, maxOutput = 100%

    while(true) { //loop indefinitely

        if(trayTaskActive) { //if trayTaskActive equals true, then run code inside brackets

            trayPID.setSetPoint(trayTarget); //set setpoint to the tray target specified by user
            trayPID.setSystemVar(trayPot.get_value()); //set system variable to the tray potentiometer
            pwrTray(trayPID.run()); //run FPID algorithm using variables specified above and power the tray motor to the output

            //std::cout << trayPot.get_value() << "  |  " << trayPID.run() << "\n";

        }

        Task::delay_until(&now, 5); //iterate 200 times a second

    }

}