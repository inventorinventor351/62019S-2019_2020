#include "main.h"

void blueSmallZone() { //6 pts

    runIntk(100);
    moveBase(1000, 1000, 800, 85);
    delay(100);
    runIntk(77.5);
    moveBase(2390, 2430, 3150, 30);
    runIntk(2);
    moveBase(250, -300, 400, 60);
    moveBase(120, 120, 400, 100);
    moveBase(500,  900, 800, 70);
    runIntk(67.5);
    moveBase(415, 465, 1060, 60);
    runIntk(22.5);
    delay(250);
    runIntk(20);
    moveBase(-2100, -2100, 1800, 70);
    delay(100);
    moveBase(-1050, 1050, 1100, 50);
    runTray(-30);
    moveBase(2400, 2400, 1800, 54);
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

}