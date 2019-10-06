#include "main.h"

void redSmallZone() {

    runIntk(80);
    moveBase(450, 450, 650, 100);
    moveBase(945, 945, 2750, 32.5);
    runIntk(80);
    delay(200);
    runIntk(0);
    moveBase(50, 195, 600, 80);
    runIntk(40);
    moveBase(500, 440, 1500, 60);
    runIntk(70);
    delay(180);
    runIntk(0);
    delay(200);
    moveBase(-1050, -1050, 1500, 80);
    moveBase(515, -515, 1250, 50);
    moveBase(620, 570, 650, 70); 
    moveBase(0, 200, 400, 100);
    runTray(-60);
    intake1.set_brake_mode(E_MOTOR_BRAKE_COAST);
	intake2.set_brake_mode(E_MOTOR_BRAKE_COAST);
    delay(1300);
    runIntk(-10);
    delay(1400);
    runIntk(0);
    runTray(0);
    runIntk(-80);
    delay(400);
    moveBase(-750, -750, 2000, 20);
    runIntk(0);

}