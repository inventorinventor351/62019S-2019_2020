#include "main.h"

void blueSmallZone5Pt() {

    deploy();
    pwrRollers(100);
    driveStraight(3100, 4000, 35);
    pwrRollers(0);
    driveStraight(-1500, 1000, 90);
    basePivot(-1150, 1300, 75);
    driveStraight(1475, 1500, 75);
    armsTaskActive = false;
    trayTarget = TRAY_FULLY_OUT;
    betterDelay(2000);
    pwrLeftBase(23.75);
    pwrRightBase(23.75);
    betterDelay(1250);
    pwrLeftBase(-100);
    pwrRightBase(-100);
    betterDelay(100);
    trayTarget = TRAY_FULLY_IN;
    armsTaskActive = true;
    betterDelay(800);
    pwrLeftBase(0);
    pwrRightBase(0);

}