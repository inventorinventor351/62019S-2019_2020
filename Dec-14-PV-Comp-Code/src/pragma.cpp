#include "main.h"

Controller master (E_CONTROLLER_MASTER);

ADIEncoder leftEnc (1, 2, 0);
ADIEncoder rightEnc (3, 4, 1);
ADIEncoder yawEnc (5, 6, 0);
ADIAnalogIn trayPot (7);
ADIAnalogIn armPot (8);

Motor leftBase1 (10, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS);
Motor leftBase2 (7, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS);
Motor rightBase1 (1, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS);
Motor rightBase2 (2, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS);
Motor intake1 (17, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS);
Motor intake2 (5, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS);
Motor tray (8, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_COUNTS);
Motor arms (16, E_MOTOR_GEARSET_06, 1, E_MOTOR_ENCODER_COUNTS);