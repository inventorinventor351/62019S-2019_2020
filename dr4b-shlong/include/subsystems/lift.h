#ifndef _LIFT_H_
#define _LIFT_H_

void pwrLift(double voltPerc);  //directly run voltage into lift motor, takes in a percentage from -100 to 100
#define LIFT_FULLY_DOWN 0       //lift encoder value when lift is all the way down
#define LIFT_FULL_UP 5000       //lift encoder value when lift is all the way up
extern double liftTarget;       //lift task minimizes difference between lift potentiometer and this value
extern bool liftTaskActive;     //activates or deactives the lift task function
void liftTask(void *param);     //PID control that gets the lift to specific positions

#endif