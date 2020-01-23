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

    leftBase1.tare_position();
    leftBase2.tare_position();

}

void resetRightBase() {

    rightBase1.tare_position();
    rightBase2.tare_position();

}

void driveStraight(double distance, int time, double maxOut) {
    
    std::uint_least32_t now = millis();

    double distVal = 0;
    PID dist (0.2, 0, 0.325);
    dist.setOutputBounds(0, maxOut);
    dist.setSetPoint(distance);

    double diffVal = 0;
    PID diff (1, 0, 0);
    diff.setOutputBounds(0, maxOut);
    diff.setSetPoint(0);

    resetLeftBase();
    resetRightBase();

    for(int i = 0; i < time; i+=10) {

        const double leftEnc = getLeftBase();
        const double rightEnc = getRightBase();

        dist.setSystemVar((leftEnc + rightEnc) / 2.0);
        diff.setSystemVar((leftEnc - rightEnc) / 2.0);

        distVal = dist.run();
        diffVal = diff.run();

        pwrLeftBase(distVal + diffVal);
        pwrRightBase(distVal - diffVal);

        std::cout << "time: " << i << "  |  " << "leftEnc: " << leftEnc << "  |  " << "leftPwr: " << distVal + diffVal << "  |  " << "rightEnc: " << rightEnc << "  |  " << "rightPwr: " << distVal - diffVal << "\n";

        Task::delay_until(&now, 10);

    }

    pwrLeftBase(0);
    pwrRightBase(0);

}

void basePivot(double angle, int time, double maxOut) {

    std::uint_least32_t now = millis();

    double distVal = 0;
    PID dist (1, 0, 0);
    dist.setOutputBounds(0, maxOut);
    dist.setSetPoint(0);

    double diffVal = 0;
    PID diff (0.2, 0, 0.325);
    diff.setOutputBounds(0, maxOut);
    diff.setSetPoint(angle);

    resetLeftBase();
    resetRightBase();

    for(int i = 0; i < time; i+=10) {

        const double leftEnc = getLeftBase();
        const double rightEnc = getRightBase();

        dist.setSystemVar((getLeftBase() + getRightBase()) / 2.0);
        diff.setSystemVar((getLeftBase() - getRightBase()) / 2.0);

        distVal = dist.run();
        diffVal = diff.run();

        pwrLeftBase(distVal + diffVal);
        pwrRightBase(distVal - diffVal);

        std::cout << "time: " << i << "  |  " << "leftEnc: " << leftEnc << "  |  " << "leftPwr: " << distVal + diffVal << "  |  " << "rightEnc: " << rightEnc << "  |  " << "rightPwr: " << distVal - diffVal << "\n";

        Task::delay_until(&now, 10);

    }

    pwrLeftBase(0);
    pwrRightBase(0);

}