#include "main.h"

void blueSmallZone() {

    runIntk(85);
    moveBase(1000, 1000, 525, 100);
    moveBase(2400, 2400, 2500, 37.5);
    runIntk(0);
    moveBase(180, -150, 250, 50);
    runIntk(70);
    delay(200);
    moveBase(875,  1125, 1600, 42);
    runIntk(20);
    moveBase(-2400, -2400, 1300, 80);
    delay(100);
    moveBase(-985, 985, 5000, 50);

}