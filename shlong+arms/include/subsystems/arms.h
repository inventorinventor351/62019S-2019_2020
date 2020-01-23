#ifndef _ARMS_H_
#define _ARMS_H_

void pwrArms(double voltPerc); //directly run voltage into lift motor, takes in a percentage from -100 to 100
#define ARMS_FULLY_DOWN 1200
#define ARMS_FULLY_UP 2800
extern double armsTarget; //arms task method tries to get tray as close as possible to this value
extern bool armsTaskActive; //activates or deactivates the arms task
void armsTask(void* param); //PID control that gets the arms to specific positions

#endif