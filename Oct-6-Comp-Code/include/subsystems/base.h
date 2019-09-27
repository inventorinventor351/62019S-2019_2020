#ifndef _BASE_H_
#define _BASE_H_

void runLeftBase(double percVolt);
void runRightBase(double percVolt);
double getLeftBase();
double getRightBase();
void resetLeftBase();
void resetRightBase();
void moveBase(double leftBaseTicks, double rightBaseTicks, double time);

#endif