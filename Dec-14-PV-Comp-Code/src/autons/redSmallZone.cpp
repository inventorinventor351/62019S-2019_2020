#include "main.h"

void redSmallZone() {

    /*trayTarget = TRAY_OUT_OF_THE_WAY;
    moveBase(1000, 1000, 675, 100);
    runRollers(-100);
    armsTarget = ARMS_FULLY_UP;
    delay(400);
    armsTarget = ARMS_FULLY_DOWN;
    runRollers(100);
    trayTarget = TRAY_FULLY_IN;
    moveBase(2700, 3500, 3500, 40);
    runRollers(0);
    moveBase(-3250, -3925, 1600, 100);
    runRollers(100);
    moveBase(3000, 3000, 3500, 32.5);
    runRollers(0);
    moveBase(-600, -2900, 1700, 100);
    moveBase(2250, 2250, 1400, 100);
    trayTarget = TRAY_FULLY_OUT;
    delay(1250);
    runLeftBase(-100);
    runRightBase(-100);
    delay(300);
    trayTarget = TRAY_FULLY_IN;*/

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
    moveBase(2400, 3100, 3250, 40);
    runRollers(0);
    moveBase(-2900, -3625, 1550, 100);
    runRollers(100);
    moveBase(3150, 3150, 3500, 32.5);
    runRollers(25);
    moveBase(-450, -2850, 1800, 100);
    runRollers(0);
    moveBase(1850, 1850, 1600, 100);
    runLeftBase(30);
    runRightBase(30);
    trayTarget = TRAY_FULLY_OUT;
    delay(1850);
    runLeftBase(-100);
    runRightBase(-100);
    delay(300);
    trayTarget = TRAY_FULLY_IN;
    
}