#include "main.h"

void redSmallZone()
{
    runIntk(80);
    moveBase(450, 450, 800, 100);
    moveBase(925, 925, 4250, 25);
    runIntk(0);
    delay(500);
    moveBase(-500, -500, 1200, 65);
    moveBase(415, -415, 1400, 50);
    moveBase(725, 725, 1650, 70);
    runTray(-55);
    delay(1250);
    intake1.set_brake_mode(E_MOTOR_BRAKE_COAST);
	intake2.set_brake_mode(E_MOTOR_BRAKE_COAST);
    runIntk(-6);
    delay(2500);
    runTray(0);
    runIntk(-100);
    delay(500);
    moveBase(-700, -700, 2000, 25);
    runIntk(0);
    runTray(55);
    delay(1500);
    runTray(0);
}