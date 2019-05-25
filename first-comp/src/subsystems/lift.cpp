#include "main.h"

void runLift(double percVolt) {

    leftLift.move_voltage((percVolt / 100) * 12000);
    rightLift.move_voltage((percVolt / 100) * 12000);

}