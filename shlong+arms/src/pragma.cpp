#include "main.h"

Controller master (E_CONTROLLER_MASTER); //initializing main and only controller as the master controller

ADIAnalogIn trayPot (7); //legacy port G
ADIAnalogIn armsPot (8); //legacy port H

Motor leftBase1 (10, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS); //v5 port 1, 200 rpm, not reversed, returns its encoder value in raw untis
Motor leftBase2 (21, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS); //v5 port 2, 200 rpm, not reversed, returns its encoder value in raw untis
Motor rightBase1 (1, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS); //v5 port 3, 200 rpm, reversed, returns its encoder value in raw untis
Motor rightBase2 (2, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS); //v5 port 4, 200 rpm, reversed, returns its encoder value in raw untis
Motor leftRoller (17, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS); //v5 port 5, 200 rpm, reversed, returns its encoder value in raw untis
Motor rightRoller (5, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS); //v5 port 6, 200 rpm, not reversed, returns its encoder value in raw untis
Motor trayMtr (19, E_MOTOR_GEARSET_36, 0, E_MOTOR_ENCODER_COUNTS); //v5 port 7, 100 rpm, not reversed, returns its encoder value in raw untis
Motor armsMtr (16, E_MOTOR_GEARSET_36, 1, E_MOTOR_ENCODER_COUNTS); //v5 port 8, 100 rpm, not reversed, returns its encoder value in raw untis