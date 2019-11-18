#include "main.h"

void redSmallZone8() { //8 pts

    runIntk(100);
    moveBase(1400, 1400, 900, 80);
    runIntk(63.75);
    moveBase(1700, 3000, 2300, 35);
    runIntk(30);
    moveBase(-2800, -3275, 1400, 100);
    runIntk(80);
    moveBase(2800, 2800, 2800, 35);
    moveBase(-1350, -1350, 1375, 60);
    runIntk(-20);
    delay(200);
    runIntk(82.5);
    delay(100);
    moveBase(1000, -1000, 1300, 45);
    runTray(-60);
    runIntk(0);
    moveBase(1800, 1800, 1400, 60);
    runIntk(30);
    preciseTray(3980, 1650);
    runIntk(0);
    delay(300);
    runIntk(-100);
    delay(125);
    runTray(42.5);
    delay(300);
    runTray(0);
    runLeftBase(-48.75);
    runRightBase(-48.75);

}