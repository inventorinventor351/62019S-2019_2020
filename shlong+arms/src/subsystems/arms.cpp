#include "main.h"

void pwrArms(double voltPerc) {

    armsMtr.move_voltage(voltPerc * 12000 / 100); //divided percentage by 100 to get ratio and multiply ratio with 12000

}