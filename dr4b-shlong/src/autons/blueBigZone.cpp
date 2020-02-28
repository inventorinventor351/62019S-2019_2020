#include "main.h"

void blueBigZone() {

    //deploy
    pwrRollers(100);

    //get second cube
    pwrRollers(80);
    driveStraight(900, 950, 90);

    //lift up to next four cubes
    liftTaskActive = true;
    liftTarget = 2700;
    basePivot(0, 1100, 90);
    driveStraight(1550, 1800, 70);
    liftTaskActive = false;
    pwrLift(-22.5);
    basePivot(0, 3000, 90);
    liftTaskActive = true;
    liftTarget = 0;
    driveStraight(600, 750, 90);

    //get last cube and go to goal
    basePivot(1100, 1250, 90);
    driveStraight(2600, 1750, 90);
    basePivot(300, 600, 90);
    pwrRollers(0);
    driveStraight(550, 750, 90);

    //stack
    trayTarget = TRAY_FULL_UP;
    basePivot(0, 2000, 90);

    //pull out
    pwrLeftBase(-100);
    pwrRightBase(-100);
    betterDelay(200);
    trayTarget = TRAY_FULLY_DOWN;
    betterDelay(400);
    pwrLeftBase(0);
    pwrRightBase(0);

}