#include "main.h"

void blueSmallZone() {

    /*moveBase(1200, 1200, 700, 100);
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
    moveBase(-2700, -1200, 3000, 100);*/

    trayTarget = TRAY_OUT_OF_THE_WAY;
    moveBase(1000, 1000, 775, 100);
    runRollers(-100);
    armsTarget = ARMS_FULLY_UP;
    delay(400);
    armsTarget = ARMS_FULLY_DOWN;
    runLeftBase(-50);
    runRightBase(-50);
    delay(250);
    runLeftBase(0);
    runRightBase(0);
    runRollers(100);
    trayTarget = TRAY_FULLY_IN;
    moveBase(3500, 2700, 4000, 40);
    runRollers(0);
    moveBase(-3925, -3250, 2000, 100);
    moveBase(800, 800, 600, 100);
    runRollers(100);
    moveBase(2800, 2800, 4000, 30);
    runRollers(0);
    moveBase(-2700, -600, 3000, 100);
    
}