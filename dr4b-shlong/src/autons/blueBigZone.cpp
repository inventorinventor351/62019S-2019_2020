#include "main.h"

void blueBigZone() {

    //deploy and go forward to collect first cube
    pwrRollers(100);
    basePivot(0, 350, 90);
    driveStraight(600, 950, 30);

    //go forward, raise lift, and go a little more forward to four stack
    driveStraight(1300, 920, 90);
    liftTaskActive = true;
    liftTarget = 2750;
    basePivot(0, 2150, 90);
    driveStraight(600, 800, 70);

    //go down on stack
    liftTaskActive = false;
    pwrLift(-40);
    basePivot(0, 1950, 90);
    liftTaskActive = true;
    liftTarget = 0;

    //turn, go forward, collect last cube, and go to goal
    basePivot(1050, 950, 90);
    driveStraight(1600, 1350, 90);
    basePivot(290, 1000, 90);
    trayTarget = 900;
    pwrRollers(0);
    driveStraight(1500, 1300, 90);

    //stack
    trayTarget = TRAY_FULL_UP;
    basePivot(0, 1300, 90);

    //pull out
    pwrLeftBase(-40);
    pwrRightBase(-40);
    betterDelay(500);
    pwrLeftBase(0);
    pwrRightBase(0);  

}