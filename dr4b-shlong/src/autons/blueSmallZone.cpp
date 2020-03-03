#include "main.h"

void blueSmallZone() {

    //deploy
    pwrRollers(100);
    liftTaskActive = false;
    pwrLift(100);
    basePivot(0, 275, 90);
    pwrLift(-100);
    basePivot(0, 275, 90);
    pwrLift(0);
    basePivot(0, 100, 90);

    //collect first two
    driveStraight(1150, 700, 90);
    driveStraight(900, 1700, 25);

    //turn, go back, and face the four cubes
    basePivot(550, 900, 90);
    driveStraight(-2500, 1400, 90);
    basePivot(-600, 1000, 90);

    //collect last four
    driveStraight(2500, 2200, 45);

    //turn and go to goal
    driveStraight(-1575, 1300, 90);
    basePivot(-1175, 1350, 90);
    driveStraight(950, 1000, 90);
    pwrRollers(0);

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