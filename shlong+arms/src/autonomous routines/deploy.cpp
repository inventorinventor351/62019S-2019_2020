#include "main.h"

void deploy() {

    armsTaskActive = false;
    trayTarget = TRAY_OUT_OF_THE_WAY;
    driveStraight(800, 500, 100);
    pwrRollers(-100);
    pwrArms(100);
    betterDelay(500);
    armsTaskActive = true;
    armsTarget = ARMS_FULLY_DOWN;
    trayTarget = TRAY_FULLY_IN;
    betterDelay(150);

}