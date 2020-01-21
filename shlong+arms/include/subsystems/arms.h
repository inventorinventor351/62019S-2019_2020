#ifndef _ARMS_H_
#define _ARMS_H_

void pwrArms(double voltPerc); //directly run voltage into lift motor, takes in a percentage from -100 to 100
#define ARMS_FULLY_DOWN 1200
#define ARMS_FULLY_UP 3000
extern double armsTarget;
extern bool armsTaskActive;
void armsTask(void* param);

#endif