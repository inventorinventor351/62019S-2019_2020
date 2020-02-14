#include "main.h"

Controller master (E_CONTROLLER_MASTER); //initializing main and only controller as the master controller

ADIEncoder leftEnc (1, 2, 0); //legacy ports A and B, not reversed
ADIEncoder rightEnc (3, 4, 1); //legacy ports C and D, reversed
ADIAnalogIn trayPot (7); //legacy port G
ADIAnalogIn randoPot (8); //legacy port H

Motor leftBase1 (16, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS); //v5 port 16, 200 rpm, not reversed, returns its encoder value in raw untis
Motor leftBase2 (19, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS); //v5 port 19, 200 rpm, not reversed, returns its encoder value in raw untis
Motor rightBase1 (15, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS); //v5 port 15, 200 rpm, reversed, returns its encoder value in raw untis
Motor rightBase2 (7, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS); //v5 port 7, 200 rpm, reversed, returns its encoder value in raw untis
Motor leftRoller (20, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS); //v5 port 20, 200 rpm, not reversed, returns its encoder value in raw untis
Motor rightRoller (11, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS); //v5 port 11, 200 rpm, reversed, returns its encoder value in raw untis
Motor trayMtr (13, E_MOTOR_GEARSET_36, 0, E_MOTOR_ENCODER_COUNTS); //v5 port 14, 100 rpm, not reversed, returns its encoder value in raw untis
Motor liftMtr (17, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS); //v5 port 17, 200 rpm, not reversed, returns its encoder value in raw untis