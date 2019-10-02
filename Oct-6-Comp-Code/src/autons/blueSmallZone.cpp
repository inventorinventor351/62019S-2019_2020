#include "main.h"

void blueSmallZone() 
{
    runIntk(40);
    moveBase(1100, 1100, 1500);
    runIntk(0);
    moveBase(-500, -500, 1000);
    moveBase(100, -500, 1000);
    moveBase(1000, 1000, 1000);
    runTray(-50);
    delay(200);
    runIntk(20);
    moveBase(-100, -100, 2000);


}