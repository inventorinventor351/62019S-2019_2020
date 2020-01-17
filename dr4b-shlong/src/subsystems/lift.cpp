#include "main.h"

void pwrLift(double voltPerc) {

    liftMtr.move_voltage(voltPerc * 12000 / 100); //divided percentage by 100 to get ratio and multiply ratio with 12000

}