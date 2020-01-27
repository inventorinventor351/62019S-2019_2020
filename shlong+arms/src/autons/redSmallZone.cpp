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
    pwrRollers(32.5);
    driveStraight(-1500, 940, 90);
    pwrRollers(0);
    basePivot(1215, 1400, 90);
    pwrRollers(0);
    driveStraight(1425, 890, 90);
    armsTaskActive = false;
    trayTarget = TRAY_FULLY_OUT;
    betterDelay(2000);
    pwrLeftBase(23.75);
    pwrRightBase(23.75);
    betterDelay(1750);
    pwrLeftBase(-100);
    pwrRightBase(-100);
    betterDelay(100);
    trayTarget = TRAY_FULLY_IN;
    armsTaskActive = true;
    betterDelay(700);
    pwrLeftBase(0);
    pwrRightBase(0);
    basePivot(-1310, 2000, 90);
    pwrRollers(100);
    driveStraight(2200, 2000, 90);
    pwrRollers(0);
    driveStraight(-300, 1200, 90);
    trayTarget = TRAY_OUT_OF_THE_WAY;
    delay(1000);
    armsTarget = ARMS_FULLY_UP;
    delay(4000);
    pwrRollers(-100);
    driveStraight(-600, 1000, 90);

}