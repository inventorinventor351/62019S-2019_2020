#include "main.h"

void pwrLeftBase(double voltPerc) {

    leftBase1.move_voltage(voltPerc * 12000 / 100); //divided percentage by 100 to get ratio and multiply ratio with 12000
    leftBase2.move_voltage(voltPerc * 12000 / 100);

}

void pwrRightBase(double voltPerc) {

    rightBase1.move_voltage(voltPerc * 12000 / 100); //divided percentage by 100 to get ratio and multiply ratio with 12000
    rightBase2.move_voltage(voltPerc * 12000 / 100);

}

double getLeftVel(void* param) {

    std::uint_least32_t now = millis();

    int prevEncVal = 0; //save encoder value for next interation
    double k = 1.0; //some constant that can be used to calculate in some untis

    while(true) {

        const int curretEncVal = leftEnc.get_value(); //get current encoder value
        return (double)(curretEncVal - prevEncVal) * k; //return k constant times difference between current encoder value and previous encoder value
        prevEncVal = curretEncVal; //save current encoder value for next iteration

        Task::delay_until(&now, 10); //iterate 100 times per second

    }

}

double getRightVel(void* param) {

    std::uint_least32_t now = millis();

    int prevEncVal = 0; //save encoder value for next interation
    double k = 1.0; //some constant that can be used to calculate in some untis

    while(true) {

        const int curretEncVal = leftEnc.get_value(); //get current encoder value
        return (double)(curretEncVal - prevEncVal) * k; //return k constant times difference between current encoder value and previous encoder value
        prevEncVal = curretEncVal; //save current encoder value for next iteration

        Task::delay_until(&now, 10); //iterate 100 times per second

    }

}

double leftVelTarget = 0; //default target is 0 rpm (aka not moving)
double rightVelTarget = 0; //default target is 0 rpm (aka not moving)

void baseVelControl(void* param) {

    std::uint_least32_t now = millis();

    while(true) {

        

        Task::delay_until(&now, 20); //iterate 50 times per second

    }

}