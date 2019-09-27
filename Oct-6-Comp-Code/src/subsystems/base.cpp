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

void moveBase(double leftBaseDeltaTicks, double rightBaseDeltaTicks, double time) {

    double leftBaseTarget = getLeftBase() + leftBaseDeltaTicks;
    double rightBaseTarget = getRightBase() + leftBaseDeltaTicks;
    
    PID leftBase (1, 0, 0);
    PID rightBase (1, 0, 0);

    std::uint_least32_t now = millis();

    for(int i = 0; i < time; i++) {

        leftBase.setError(leftBaseTarget - getLeftBase());
        rightBase.setError(rightBaseTarget - getRightBase());

        runLeftBase(leftBase.runPID());
        runRightBase(rightBase.runPID());

        Task::delay_until(&now, 1);

    }

}