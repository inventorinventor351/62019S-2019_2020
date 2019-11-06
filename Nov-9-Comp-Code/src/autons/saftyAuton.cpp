#include "main.h"

void oneCubeSafety() { //1 pt
    
    runIntk(100);
    delay(1000);
    runIntk(0);
    moveBase(1200, 1200, 2000, 60);
    runIntk(-80);
    delay(1000);
    runIntk(0);
    moveBase(-600, -600, 2000, 60);

}