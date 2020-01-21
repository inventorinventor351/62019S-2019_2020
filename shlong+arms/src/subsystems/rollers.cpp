#include "main.h"

void pwrRollers(double voltPerc) {

    leftRoller.move_voltage(voltPerc * 12000 / 100); //divided percentage by 100 to get ratio and multiply ratio with 12000
    rightRoller.move_voltage(voltPerc * 12000 / 100);

}