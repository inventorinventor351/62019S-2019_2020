#ifndef _PRAGMA_H_
#define _PRAGMA_H_

extern Controller master; //main and only controller

/* LEGACY COMPONENTS */
extern ADIAnalogIn trayPot; //potentiometer on the tray
extern ADIAnalogIn armsPot; //potentionmeter on the arms

/* V5 COMPONENTS */
extern Motor leftBase1; //front left base motor
extern Motor leftBase2; //back left base motor
extern Motor rightBase1; //front right base motor
extern Motor rightBase2; //back right base motor
extern Motor leftRoller; //left roller motor
extern Motor rightRoller; //right roller motor
extern Motor trayMtr; //motor that tilts the tray
extern Motor armsMtr; //motor that runs the arms up and down

#endif