#include "main.h"

void blueSmallZone() 
{
    runIntk(80);
    delay(500);
    runIntk(40);
    moveBase(3000, 3000, 4000);
    runIntk(0);
    moveBase(500, -100, 1000);
    moveBase(100, -500, 1000);
    moveBase(1000, 1000, 1000);
    runTray(-50);
    delay(200);
    runIntk(20);
    moveBase(-100, -100, 2000);

}