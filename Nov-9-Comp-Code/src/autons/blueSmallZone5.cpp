#include "main.h"

void blueSmallZone5() { //5 pts

    runIntk(90);
    moveBase(1000, 1000, 800, 85);
    moveBase(2400, 2400, 2700, 37.5);
    runIntk(15);
    moveBase(-1800, -1800, 2000, 85);
    moveBase(-1050, 1050, 1100, 50);
    runTray(-30);
    moveBase(1800, 1800, 1800, 54);
    runIntk(40);
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
    delay(2000);
    runLeftBase(0);
    runRightBase(0);

}