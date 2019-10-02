#include "main.h"

void runLeftBase(double percVolt) {

    leftBase1.move_voltage(percVolt * 12000 / 100);
    leftBase2.move_voltage(percVolt * 12000 / 100);
    
}

void runRightBase(double percVolt) {

    rightBase1.move_voltage(percVolt * 12000 / 100);
    rightBase2.move_voltage(percVolt * 12000 / 100);
    
}

double getLeftBase() {

    return (leftBase1.get_position() + leftBase2.get_position()) / 2.0;

}

double getRightBase() {

    return (rightBase1.get_position() + rightBase2.get_position()) / 2.0;

}

void resetLeftBase() {

    leftBase1.tare_position();
    leftBase2.tare_position();

}

void resetRightBase() {

    rightBase1.tare_position();
    rightBase2.tare_position();

}

void moveBase(double leftBaseDeltaTicks, double rightBaseDeltaTicks, double time, double _maxSpeed) {

    const double leftBaseTarget = getLeftBase() + leftBaseDeltaTicks;
    const double rightBaseTarget = getRightBase() + rightBaseDeltaTicks;
   
    PID leftBase (0.325, 0, 0);
    PID rightBase (0.3, 0, 0);

    leftBase.maxSpeed = _maxSpeed;
    rightBase.maxSpeed = _maxSpeed;

    std::uint_least32_t now = millis();

    for(int i = 0; i < time; i++) {

        leftBase.setError(leftBaseTarget - getLeftBase());
        rightBase.setError(rightBaseTarget - getRightBase());

        runLeftBase(leftBase.runPID());
        runRightBase(rightBase.runPID());

        //std::cout << "Left Error: " << leftBase.getError() << "   |   Right Error: " << rightBase.getError();
        std::printf("Left: %7f Right: %f\n", getLeftBase(), getRightBase());

        Task::delay_until(&now, 1);

    }

    runLeftBase(0);
    runRightBase(0);

}