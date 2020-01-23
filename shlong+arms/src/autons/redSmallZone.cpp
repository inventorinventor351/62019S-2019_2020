#include "main.h"

void redSmallZone() {

    deploy();
    pwrRollers(100);
    driveStraight(2800, 2850, 42.5);
    basePivot(-420, 400, 90);
    pwrRollers(0);
    driveStraight(-3200, 1600, 90);
    basePivot(430, 425, 90);
    pwrRollers(100);
    driveStraight(3000, 3300, 30);
    pwrRollers(55);
    driveStraight(-1500, 950, 90);
    pwrRollers(0);
    basePivot(1100, 1200, 90);
    pwrRollers(0);
    driveStraight(1300, 850, 90);
    trayTarget = TRAY_FULLY_OUT;
    betterDelay(2000);
    pwrLeftBase(-100);
    pwrRightBase(-100);
    betterDelay(150);
    trayTarget = TRAY_FULLY_IN;

}