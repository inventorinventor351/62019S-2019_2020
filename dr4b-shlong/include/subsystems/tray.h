#ifndef _TRAY_H_
#define _TRAY_H_

void pwrTray(double voltPerc); //directly run voltage into tray motor, takes in a percentage from -100 to 100
#define TRAY_FULLY_DOWN 0 //tray potentiomter value when tray is all the way down
#define TRAY_FULL_UP 1000 //tray potentiometer value when tray is all the way up
extern double trayTarget; //tray task minimizes difference between tray potentiometer and this value
extern bool trayTaskActive; //activates or deactives the tray task function
void trayTask(void* param); //PID control that gets the tray to specific positions

#endif