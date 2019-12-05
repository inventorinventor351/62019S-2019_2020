#include "main.h"

void blueSmallZone() {

    moveBase(1200, 1200, 700, 100);
    moveBase(-600, -600, 500, 100);
    trayTarget = 1450;
    delay(600);
    runRollers(-100);
    armsTarget = ARMS_FULLY_UP;
    delay(150);
    armsTarget = ARMS_FULLY_DOWN;
    delay(150);
    armsTarget = ARMS_FULLY_UP;
    delay(150);
    armsTarget = ARMS_FULLY_DOWN;
    trayTarget = TRAY_FULLY_IN;
    runLeftBase(-75);
    runRightBase(-75);
    delay(75);
    runLeftBase(0);
    runRightBase(0);
    runRollers(100);
    moveBase(3700, 2900, 3600, 40);
    runRollers(0);
    moveBase(-3900, -3200, 1500, 100);
    runRollers(100);
    moveBase(3250, 3250, 3500, 30);
    runRollers(0);
    moveBase(-2700, -1200, 3000, 100);

}