#include "main.h"

void blueSmallZone() {

    runIntk(100);
    moveBase(1000, 1000, 800, 85);
    delay(100);
    runIntk(80);
    moveBase(2400, 2400, 3000, 30);
    runIntk(5);
    moveBase(250, -300, 600, 60);
    moveBase(120, 120, 400, 100);
    moveBase(500,  900, 1100, 70);
    runIntk(70);
    moveBase(415, 465, 1400, 60);
    runIntk(22.5);
    delay(250);
    runIntk(20);
    moveBase(-1800, -1800, 1500, 70);
    delay(100);
    moveBase(-1050, 1050, 1100, 50);
    runTray(-30);
    moveBase(2400, 2400, 1800, 54);
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

}