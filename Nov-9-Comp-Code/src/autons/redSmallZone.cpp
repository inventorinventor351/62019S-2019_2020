#include "main.h"

void redSmallZone() { //5 pts
    
    runIntk(100);
    moveBase(1000, 1000, 800, 85);
    delay(100);
    runIntk(77.5);
    moveBase(2400, 2400, 3000, 30);
    delay(100);
    runIntk(15);
    moveBase(-1675, -1675, 1200, 80);    
    moveBase(1050, -1050, 1100, 50);
    runTray(-30);
    moveBase(1600, 1600, 1800, 54);
    runIntk(50);
    delay(250);
    runIntk(0);
    preciseTray(3990, 1300);
    delay(100);
    runIntk(-15);
    delay(150);
    runIntk(-80);
    delay(150);
    runTray(20);
    delay(250);
    runTray(0);
    delay(300);
    runLeftBase(-55);
    runRightBase(-55);
    delay(2259);
    runLeftBase(0);
    runRightBase(0);
    
}