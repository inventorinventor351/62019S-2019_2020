#include "main.h"

void blueSmallZone()
{

    //go forward to avoid anti tip hitting wall and then deploy
    driveStraight(500, 400, 90);
    pwrRollers(100);
    liftTaskActive = false;
    pwrLift(100);
    basePivot(0, 250, 90);
    pwrLift(-100);
    basePivot(0, 250, 90);
    pwrLift(0);
    liftTaskActive = true;
    liftTarget = 0;

    //go forward and get first two cubes
    driveStraight(800, 600, 90);
    driveStraight(800, 1500, 25);

    //turn, go back, and then turn again, facing last 4 cubes
    basePivot(575, 970, 90);
    driveStraight(-2375, 1270, 90);
    basePivot(-600, 970, 90);

    //go forward and collect last four cubes
    driveStraight(2200, 1970, 45);

    //go back, turn, and go to zone
    driveStraight(-1575, 1570, 90);
    basePivot(-1175, 1470, 90);
    driveStraight(950, 970, 90);
    pwrRollers(0);

    //stack
    trayTarget = TRAY_FULL_UP;
    basePivot(0, 2200, 90);

    //pull out
    pwrLeftBase(-100);
    pwrRightBase(-100);
    betterDelay(200);
    trayTarget = TRAY_FULLY_DOWN;
    betterDelay(800);
    pwrLeftBase(0);
    pwrRightBase(0);
}