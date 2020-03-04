#include "main.h"

void redBigZone() {

    //deploy
    pwrRollers(100);
    basePivot(0, 350, 90);

    //get second cube
    pwrRollers(80);
    driveStraight(900, 950, 90);

    //lift up to next four cubes
    liftTaskActive = true;
    liftTarget = 2700;
    basePivot(0, 1100, 90);
    driveStraight(1640, 1850, 70);
    liftTaskActive = false;
    pwrLift(-22.5);
    basePivot(0, 3000, 90);
    liftTaskActive = true;
    liftTarget = 0;
    driveStraight(325, 400, 90);

    //get last cube and go to goal
    basePivot(-1100, 1150, 90);
    driveStraight(2400, 1500, 90);
    basePivot(-275, 700, 90);
    pwrRollers(0);
    driveStraight(675, 750, 90);

    //stack
    trayTarget = TRAY_FULL_UP;
    basePivot(0, 2250, 90);

    //pull out
    pwrLeftBase(-100);
    pwrRightBase(-100);
    betterDelay(200);
    trayTarget = TRAY_FULLY_DOWN;
    betterDelay(800);
    pwrLeftBase(0);
    pwrRightBase(0);

}