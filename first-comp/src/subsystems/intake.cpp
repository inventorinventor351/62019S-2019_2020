#include "main.h"

void runIntake(double percVolt) {

    intake.move_voltage((percVolt / 100) * 12000);

}

void runHoarder(double percVolt) {

    hoarder.move_voltage((percVolt / 100) * 12000);

}