#ifndef _INTAKE_TRAY_H_
#define _INTAKE_TRAY_H_

void runRollers(double percVolt);
void runTray(double percVolt);
void runArms(double percVolt);
extern double trayTarget;
void trayTask(void* param);
extern double armsTarget;
void armsTask(void* param);

#endif