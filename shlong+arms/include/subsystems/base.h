#ifndef _BASE_H_
#define _BASE_H_

void pwrLeftBase(double voltPerc); //directly run voltage into left base motors, takes in a percentage from -100 to 100
void pwrRightBase(double voltPerc); //directly run voltage into right base motors, takes in a percentage from -100 to 100
double getLeftBase(); //get left base encoder value
double getRightBase(); //get right base encoder value
void resetLeftBase(); //set left base encoder value to 0
void resetRightBase(); //set right base encoder value to 0
void driveStraight(double distance, int time, double maxOut); //drives base in a straight line, either forward or backward
void basePivot(double angle, int time, double maxOut); //pivots base in place

#endif