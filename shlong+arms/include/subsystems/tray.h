#ifndef _TRAY_H_
#define _TRAY_H_

void pwrTray(double voltPerc); //directly run voltage into tray motor, takes in a percentage from -100 to 100
#define TRAY_FULLY_IN 450
#define TRAY_OUT_OF_THE_WAY 900
#define TRAY_FULLY_OUT 2290
extern double trayTarget;
extern bool trayTaskActive;
void trayTask(void* param);

#endif