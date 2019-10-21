#include "main.h"

void blueBigZone()
{
    runIntk(80);
    delay(500);
    moveBase(1100, 1100, 2000, 100);
    delay(100);
    runIntk(0);
    moveBase(-500, -500, 1000, 100);
    moveBase(200, -200, 1000, 80);
    moveBase(500, 500, 1500, 80);
    runTray(-50);
    delay(200);
    runIntk(20);
    moveBase(-100, -100, 2000, 100);

}