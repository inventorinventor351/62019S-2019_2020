#ifndef _TRAY_H_
#define _TRAY_H_

void pwrTray(double voltPerc); //directly run voltage into tray motor, takes in a percentage from -100 to 100
#define TRAY_FULLY_IN 450
#define TRAY_OUT_OF_THE_WAY 1000
#define TRAY_FULLY_OUT 2290
extern double trayTarget; //tray task method tries to get tray as close as possible to this value
extern bool trayTaskActive; //activates or deactivates the tray task
void trayTask(void* param); //PID control that gets the tray to specific positions

#endif