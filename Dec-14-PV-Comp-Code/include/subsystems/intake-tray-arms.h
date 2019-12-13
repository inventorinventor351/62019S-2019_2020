#ifndef _INTAKE_TRAY_H_
#define _INTAKE_TRAY_H_

void runRollers(double percVolt);
void runTray(double percVolt);
void runArms(double percVolt);
#define TRAY_FULLY_IN 450
#define TRAY_OUT_OF_THE_WAY 900
#define TRAY_FULLY_OUT 2290
extern double trayTarget;
void trayTask(void* param);
#define ARMS_FULLY_DOWN 1200
#define ARMS_FULLY_UP 3000
extern double armsTarget;
extern bool armsActive;
void armsTask(void* param);

#endif