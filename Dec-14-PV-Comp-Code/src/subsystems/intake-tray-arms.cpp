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