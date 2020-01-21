#include "main.h"

void pwrTray(double voltPerc) {

    trayMtr.move_voltage(voltPerc * 12000 / 100); //divided percentage by 100 to get ratio and multiply ratio with 12000

}