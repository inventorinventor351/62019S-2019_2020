#ifndef _PRAGMA_H_
#define _PRAGMA_H_

extern Controller master; //main and only controller

/* LEGACY COMPONENTS */
extern ADIEncoder leftEnc; //encoder on the left tracker wheel
extern ADIEncoder rightEnc; //encoder on the right tracker wheel
extern ADIAnalogIn trayPot; //potentiometer on the tray
extern ADIAnalogIn liftPot; //potentionmeter on the dr4b lift

/* V5 COMPONENTS */
extern Motor leftBase1; //front left base motor
extern Motor leftBase2; //back left base motor
extern Motor rightBase1; //front right base motor
extern Motor rightBase2; //back right base motor
extern Motor leftRoller; //left roller motor
extern Motor rightRoller; //right roller motor
extern Motor trayMtr; //motor that tils the tray
extern Motor liftMtr; //motor that runs the dr4b lift up and down

#endif