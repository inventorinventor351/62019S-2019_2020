#include "main.h"

void blueSmallZone() {

    runIntk(80);
    moveBase(450, 450, 800, 100);
    moveBase(925, 925, 4250, 25);
    runIntk(0);
    delay(500);
    moveBase(-500, -500, 1000, 80);
    moveBase(-500, 500, 1000, 80);
    moveBase(675, 675, 1500, 70);
    runTray(-55);
    intake1.set_brake_mode(E_MOTOR_BRAKE_COAST);
	intake2.set_brake_mode(E_MOTOR_BRAKE_COAST);
    delay(1250);
    runIntk(-10);
    delay(2500);
    runTray(0);
    runIntk(-80);
    delay(500);
    moveBase(-650, -650, 2000, 25);
    runIntk(0);
    runTray(55);
    delay(1500);
    runTray(0);

}