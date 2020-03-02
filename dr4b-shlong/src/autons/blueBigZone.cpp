#include "main.h"

void blueBigZone() {

    //deploy
    pwrRollers(100);
    basePivot(0, 500, 90);

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
    basePivot(1100, 1200, 90);
    driveStraight(2400, 1550, 90);
    basePivot(275, 700, 90);
    pwrRollers(0);
    driveStraight(800, 750, 90);

    //stack
    trayTarget = TRAY_FULL_UP;
    basePivot(0, 2000, 90);

    //pull out and lift lift up for driver
    trayTarget = TRAY_FULLY_DOWN;
    driveStraight(-900, 800, 90);

}