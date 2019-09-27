#include "main.h"

void runLeftBase(double percVolt) {

    leftBase1.move_voltage(percVolt * 12000 / 100);
    leftBase2.move_voltage(percVolt * 12000 / 100);
    
}

void runRightBase(double percVolt) {

    rightBase1.move_voltage(percVolt * 12000 / 100);
    rightBase2.move_voltage(percVolt * 12000 / 100);
    
}