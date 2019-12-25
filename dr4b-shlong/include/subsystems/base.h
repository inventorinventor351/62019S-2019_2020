#ifndef _BASE_H_
#define _BASE_H_

void pwrLeftBase(double voltPerc); //directly run voltage into left base motors, takes in a percentage from -100 to 100
void pwrRightBase(double voltPerc); //directly run voltage into right base motors, takes in a percentage from -100 to 100
extern double leftVel; //variable to store the current velocity of left base
extern double rightVel; //variable to store the current velocity of right base
void getLeftVel(void* param); //task that calculates rpm for left side of base (idk if its units are rotations per minute tho)
void getRightVel(void* param); //task that calculates rpm for right side of base (idk if its units are rotations per minute tho)
extern double leftAccel; //how quickly the left base should ramp up or down to the target velocity, angular acceleration
extern double rightAccel; //how quickly the right base should ramp up or down to the target velocity, angular acceleration
extern double leftVelTarget; //left target rpm that the FPID controller for the base will try to meet (idk if its units are rotations per minute tho)
extern double rightVelTarget; //right target rpm that the FPID controller for the base will try to meet (idk if its units are rotations per minute tho)
void setBaseTrajectory(double _leftVelTarget, double _leftAccel, double _rightVelTarget, double _rightAccel); //quality of life method that allows specification of different motions for both sides of base
void setBaseVelocities(double _leftVelTarget, double _rightVelTarget); //quality of life method that allows specifications of different velocities for both sides of base
void setBaseAccelerations(double _leftAccel, double _rightAccel); //quality of life method that allows specifications of different accelerations for both sides of base
void baseVelControl(void* param); //FPID base controller task

#endif