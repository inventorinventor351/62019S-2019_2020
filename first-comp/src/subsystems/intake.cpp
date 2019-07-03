#include "main.h"

void runIntake(double percVolt) {

    intake1.move_voltage((percVolt / 100) * 12000);

}