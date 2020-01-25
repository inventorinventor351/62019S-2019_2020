#include "main.h"

void redSmallZone() {

    deploy();
    pwrRollers(100);
    driveStraight(2800, 2750, 42.5);
    basePivot(-425, 460, 90);
    pwrRollers(0);
    driveStraight(-3000, 1340, 90);
    basePivot(510, 470, 90);
    pwrRollers(100);
    driveStraight(3885, 3670, 30);
    pwrRollers(40);
    driveStraight(-1500, 940, 90);
    pwrRollers(-15);
    basePivot(1170, 1240, 90);
    pwrRollers(0);
    driveStraight(1425, 890, 90);
    armsTaskActive = false;
    trayTarget = TRAY_FULLY_OUT;
    betterDelay(1875);
    pwrLeftBase(-100);
    pwrRightBase(-100);
    delay(100);
    trayTarget = TRAY_FULLY_IN;
    armsTaskActive = true;

}