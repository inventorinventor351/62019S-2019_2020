#include "main.h"

void pwrLeftBase(double voltPerc) {

    leftBase1.move_voltage(voltPerc * 12000 / 100); //divided percentage by 100 to get ratio and multiply ratio with 12000
    leftBase2.move_voltage(voltPerc * 12000 / 100);

}

void pwrRightBase(double voltPerc) {

    rightBase1.move_voltage(voltPerc * 12000 / 100); //divided percentage by 100 to get ratio and multiply ratio with 12000
    rightBase2.move_voltage(voltPerc * 12000 / 100);

}

double getLeftBase() {

    return (leftBase1.get_position() + leftBase2.get_position()) / 2.0; //average left front motor's and left back motor's encoder values

}

double getRightBase() {

    return (rightBase1.get_position() + rightBase2.get_position()) / 2.0; //average right front motor's and right back motor's encoder values

}

void resetLeftBase() {

    leftBase1.tare_position(); //reset both left base motor encoders
    leftBase2.tare_position();

}

void resetRightBase() {

    rightBase1.tare_position(); //reset both right base motor encoders
    rightBase2.tare_position();

}

void driveStraight(double distance, int time, double maxOut) {
    
    std::uint_least32_t now = millis();

    double distVal = 0;
    FPID dist (0, 0.2, 0, 0.425);
    dist.setOutputBounds(0, maxOut);
    dist.setSetPoint(distance);

    double diffVal = 0;
    FPID diff (0, 1, 0, 0);
    diff.setOutputBounds(0, maxOut);
    diff.setSetPoint(0);

    resetLeftBase();
    resetRightBase();

    for(int i = 0; i < time; i+=10) {

        const double leftEncVal = getLeftBase();
        const double rightEncVal = getRightBase();

        dist.setSystemVar((leftEncVal + rightEncVal) / 2.0);
        diff.setSystemVar((leftEncVal - rightEncVal) / 2.0);

        distVal = dist.run();
        diffVal = diff.run();

        pwrLeftBase(distVal + diffVal);
        pwrRightBase(distVal - diffVal);

        std::cout << "time: " << i << "  |  " << "leftEncVal: " << leftEncVal << "  |  " << "leftPwr: " << distVal + diffVal << "  |  " << "rightEncVal: " << rightEncVal << "  |  " << "rightPwr: " << distVal - diffVal << "\n";

        Task::delay_until(&now, 10);

    }

    pwrLeftBase(0);
    pwrRightBase(0);

}

void basePivot(double angle, int time, double maxOut) {

    std::uint_least32_t now = millis();

    double distVal = 0;
    FPID dist (0, 1, 0, 0);
    dist.setOutputBounds(0, maxOut);
    dist.setSetPoint(0);

    double diffVal = 0;
    FPID diff (0, 0.2, 0, 0.3);
    diff.setOutputBounds(0, maxOut);
    diff.setSetPoint(angle);

    resetLeftBase();
    resetRightBase();

    for(int i = 0; i < time; i+=10) {

        const double leftEncVal = getLeftBase();
        const double rightEncVal = getRightBase();

        dist.setSystemVar((getLeftBase() + getRightBase()) / 2.0);
        diff.setSystemVar((getLeftBase() - getRightBase()) / 2.0);

        distVal = dist.run();
        diffVal = diff.run();

        pwrLeftBase(distVal + diffVal);
        pwrRightBase(distVal - diffVal);

        std::cout << "time: " << i << "  |  " << "leftEncVal: " << leftEncVal << "  |  " << "leftPwr: " << distVal + diffVal << "  |  " << "rightEncVal: " << rightEncVal << "  |  " << "rightPwr: " << distVal - diffVal << "\n";

        Task::delay_until(&now, 10);

    }

    pwrLeftBase(0);
    pwrRightBase(0);

}

double leftVel = 0; //logically, base starts at at 0 vel when code starts
double rightVel = 0; //logically, base starts at at 0 vel when code starts

void getLeftVel(void* param) {

    std::uint_least32_t now = millis();

    int prevEncVal = 0; //save encoder value for next interation
    double k = 1.0; //some constant that can be used to calculate in some untis

    while(true) { //loop indefinitely

        const int curretEncVal = leftEnc.get_value(); //get current encoder value
        leftVel = (double)(curretEncVal - prevEncVal) * k; //return k constant times difference between current encoder value and previous encoder value
        prevEncVal = curretEncVal; //save current encoder value for next iteration

        Task::delay_until(&now, 10); //iterate 100 times per second

    }

}

void getRightVel(void* param) {

    std::uint_least32_t now = millis();

    int prevEncVal = 0; //save encoder value for next interation
    double k = 1.0; //some constant that can be used to calculate in some untis

    while(true) { //loop indefinitely

        const int curretEncVal = rightEnc.get_value(); //get current encoder value
        rightVel = (double)(curretEncVal - prevEncVal) * k; //return k constant times difference between current encoder value and previous encoder value
        prevEncVal = curretEncVal; //save current encoder value for next iteration

        Task::delay_until(&now, 10); //iterate 100 times per second

    }

}

double leftAccel = 100; //make it something high so that left base doesn't take long to reach its target velocity
double rightAccel = 100; //make it something high so that right base doesn't take long to reach its target velocity

double leftVelTarget = 0; //default target is 0 rpm (aka not moving)
double rightVelTarget = 0; //default target is 0 rpm (aka not moving)

void setBaseTrajectories(double _leftVelTarget, double _leftAccel, double _rightVelTarget, double _rightAccel) {

    leftVelTarget = _leftVelTarget;
    leftAccel = _leftAccel;
    rightVelTarget = _rightVelTarget;
    rightAccel = _rightAccel;

}

void setBaseVelocities(double _leftVelTarget, double _rightVelTarget) {

    leftVelTarget = _leftVelTarget;
    rightVelTarget = _rightVelTarget;
    
}

void setBaseAccelerations(double _leftAccel, double _rightAccel) {

    leftAccel = _leftAccel;
    rightAccel = _rightAccel;
    
}

void baseVelControl(void* param) {

    std::uint_least32_t now = millis();

    double intermediateLeftVelTarget = 0; //intermediate value that ramps up or down towards the left base velocity target
    double intermediateRightVelTarget = 0; //intermediate value that ramps up or down towards the right bsae velocity target

    FPID leftVelFPID (0, 0, 0, 0); //FPID object for left base initialized with constants of
    FPID rightVelFPID (0, 0, 0, 0); //FPID object for right base initialized with constants of

    leftVelFPID.setOutputBounds(0, 100); //set output bounds for left base to be 0 and 100
    rightVelFPID.setOutputBounds(0, 100); //set output bounds for left base to be 0 and 100

    while(true) { //loop indefinitely

        intermediateLeftVelTarget = (fabs(leftVelTarget - intermediateLeftVelTarget) < leftAccel) ? (leftVelTarget) : (intermediateLeftVelTarget + (leftAccel * sgn(leftVelTarget - intermediateLeftVelTarget))); //increments or decrements intermediate left velocity target by left acceleration until the difference between actual left target and intermediate left target is less than the left acceleration
        intermediateRightVelTarget = (fabs(rightVelTarget - intermediateRightVelTarget) < rightAccel) ? (rightVelTarget) : (intermediateRightVelTarget + (rightAccel * sgn(rightVelTarget - intermediateRightVelTarget))); //increments or decrements intermediate right velocity target by right acceleration until the difference between actual right target and intermediate right target is less than the right acceleration

        leftVelFPID.setSetPoint(intermediateLeftVelTarget); //tell FPID controller to run left base as accurately as possible to the target velocity
        rightVelFPID.setSetPoint(intermediateRightVelTarget); //tell FPID controller to run right base as accurately as possible to the target velocity

        leftVelFPID.setSystemVar(leftVel); //pass through current left base velocity
        rightVelFPID.setSystemVar(rightVel); //pass through current right base velocity

        pwrLeftBase(leftVelFPID.run()); //power left base with voltage that FPID algorithm calculated
        pwrRightBase(rightVelFPID.run()); //power right base with voltage that FPID algorithm calculated

        Task::delay_until(&now, 20); //iterate 50 times per second

    }

}