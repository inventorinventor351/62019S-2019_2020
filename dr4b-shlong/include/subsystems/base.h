#ifndef _BASE_H_
#define _BASE_H_

void pwrLeftBase(double voltPerc); //directly run voltage into left base motors, takes in a percentage from -100 to 100
void pwrRightBase(double voltPerc); //directly run voltage into right base motors, takes in a percentage from -100 to 100
double getLeftVel(void* param); //task that calculates rpm for left side of base (idk if its units are rotations per minute tho)
double getRightVel(void* param); //task that calculates rpm for right side of base (idk if its units are rotations per minute tho)
extern double leftVelTarget; //left target rpm that the FPID controller for the base will try to meet (idk if its units are rotations per minute tho)
extern double rightVelTarget; //right target rpm that the FPID controller for the base will try to meet (idk if its units are rotations per minute tho)
void baseVelControl(void* param); //FPID base controller task

#endif