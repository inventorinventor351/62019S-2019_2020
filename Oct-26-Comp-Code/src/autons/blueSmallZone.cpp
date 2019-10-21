#include "main.h"

void blueSmallZone(){

    //5 pt kinda slow auton
    runIntk(80);
    moveBase(450, 450, 800, 100);
    moveBase(925, 925, 4250, 25);
    runIntk(0);
    delay(500);
    moveBase(-500, -500, 1000, 80);
    moveBase(-462, 462, 1400, 50);
    moveBase(775, 775, 1500, 70);
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

    //optimizing auton - 6 pt
    /*runIntk(80);
    moveBase(450, 450, 650, 100);
    moveBase(945, 945, 2750, 32.5);
    runIntk(80);
    delay(200);
    runIntk(0);
    moveBase(195, 50, 600, 80);
    runIntk(40);
    moveBase(440, 500, 1500, 60);
    runIntk(70);
    delay(180);
    runIntk(0);
    delay(200);
    moveBase(-1050, -1050, 1500, 80);
    moveBase(-515, 515, 1250, 50);
    moveBase(570, 620, 650, 70);
    moveBase(200, 0, 400, 100);
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
    runIntk(0);*/

}