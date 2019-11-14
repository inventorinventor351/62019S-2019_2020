#include "main.h"

void blueSmallZone8() { //8 pts

    runIntk(50);
    moveBase(1400, 1400, 1100, 80);
    runIntk(100);
    preciseTray(2200, 700);
    runIntk(70);
    preciseTray(1690, 700);
    runIntk(85);
    moveBase(2000, 2000, 2800, 37.5);
    runIntk(0);
    moveBase(300, -300, 700, 60);
    moveBase(-3200, -3200, 3000, 80);
    moveBase(-300, 300, 700, 60);
    runIntk(85);
    moveBase(2500, 2500, 2800, 37.5);
    runIntk(25);
    moveBase(-1500, -1500, 800, 70);
    moveBase(-1050, 1050, 1100, 50);
    runTray(-30);
    moveBase(1500, 1500, 1400, 55);
    preciseTray(3990, 1750);
    runIntk(-40);
    delay(300);
    runIntk(0);
    delay(125);
    runIntk(-85);
    delay(300);
    runTray(30);
    delay(150);
    runTray(0);
    moveBase(-2300, -2300, 1700, 55);
    runLeftBase(40);
    runRightBase(-40);
    preciseTray(1690, 1300);
    runLeftBase(0);
    runRightBase(0);

    /*runIntk(50);
    moveBase(1400, 1400, 800, 100);
    runIntk(100);
    preciseTray(1990, 450);
    runIntk(70);
    preciseTray(1690, 450);
    runIntk(100);
    moveBase(2000, 2000, 2000, 42.5);
    runIntk(0);
    moveBase(300, -300, 400, 80);
    moveBase(-3200, -3200, 1900, 100);
    moveBase(-300, 300, 400, 80);
    runIntk(85);
    moveBase(2500, 2500, 2400, 42.5);
    runIntk(25);*/

}