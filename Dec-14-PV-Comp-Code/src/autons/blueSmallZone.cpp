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

    armsActive = false;
    trayTarget = TRAY_OUT_OF_THE_WAY;
    moveBase(800, 800, 500, 100);
    runRollers(-100);
    runArms(100);
    delay(550);
    armsActive = true;
    armsTarget = ARMS_FULLY_DOWN;
    trayTarget = TRAY_FULLY_IN;
    delay(150);
    runRollers(100);
    moveBase(3100, 2400, 3200, 40);
    runRollers(0);
    moveBase(-3625, -2900, 1500, 100);
    runRollers(100);
    moveBase(3150, 3150, 3450, 32.5);
    runRollers(15);
    moveBase(-2850, -450, 1750, 100);
    runRollers(0);
    moveBase(2000, 2250, 1600, 100);
    trayTarget = TRAY_FULLY_OUT;
    delay(1800);
    runLeftBase(40);
    runRightBase(40);
    delay(200);
    runLeftBase(-100);
    runRightBase(-100);
    delay(300);
    trayTarget = TRAY_FULLY_IN;
    
}