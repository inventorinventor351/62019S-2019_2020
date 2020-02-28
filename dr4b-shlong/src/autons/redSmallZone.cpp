#include "main.h"

void redSmallZone() {

    //deploy
    pwrRollers(100);
    liftTaskActive = false;
    pwrLift(100);
    basePivot(0, 300, 90);
    pwrLift(-100);
    basePivot(0, 300, 90);
    pwrLift(0);

    //collect first two
    driveStraight(1150, 700, 90);
    driveStraight(900, 1800, 25);
    pwrRollers(0);

    //turn, go back, and face the four cubes
    basePivot(-550, 900, 90);
    driveStraight(-2425, 1300, 90);
    basePivot(575, 1000, 90);
    pwrRollers(100);

    //collect last four
    driveStraight(2500, 2400, 45);

    //turn and go to goal
    driveStraight(-1575, 1300, 90);
    pwrRollers(0);
    basePivot(1170, 1300, 90);
    driveStraight(1200, 1000, 90);

    //stack
    trayTarget = TRAY_FULL_UP;
    basePivot(0, 2000, 90);

    //pull out
    pwrLeftBase(-100);
    pwrRightBase(-100);
    betterDelay(200);
    trayTarget = TRAY_FULLY_DOWN;
    betterDelay(800);
    pwrLeftBase(0);
    pwrRightBase(0);

}