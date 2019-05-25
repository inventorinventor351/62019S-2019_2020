#include "main.h"

void runLeftBase(double percVolt) {

    leftBase1.move_voltage((percVolt / 100) * 12000);
    leftBase2.move_voltage((percVolt / 100) * 12000);

}

void runLeftBase(double percVolt) {

    rightBase1.move_voltage((percVolt / 100) * 12000);
    rightBase2.move_voltage((percVolt / 100) * 12000);

}