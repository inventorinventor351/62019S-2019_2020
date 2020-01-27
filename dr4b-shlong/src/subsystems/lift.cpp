#include "main.h"

void pwrLift(double voltPerc) {

    liftMtr.move_voltage(voltPerc * 12000 / 100); //divided percentage by 100 to get ratio and multiply ratio with 12000

}

double liftTarget = LIFT_FULLY_DOWN; //lift should stay down at start of program execution
bool liftTaskActive = true; //lift task should be active at start of program execution

void liftTask(void* param) {

    std::uint_least32_t now = millis();

    FPID liftPID (0, 0, 0, 0); //kF = 0, kP = 0, kI = 0, kD = 0
    liftPID.setOutputBounds(0, 100); //minOutput = 0%, maxOutput = 100%

    while(true) { //loop indefinitely

        if(liftTaskActive) { //if liftTaskActive equals true, then run code inside brackets

            liftPID.setSetPoint(liftTarget); //set setpoint to the lift target specified by user
            liftPID.setSystemVar(liftPot.get_value()); //set system variable to the lift potentiometer
            pwrLift(liftPID.run()); //run FPID algorithm using variables specified above and power the lift motor to the output

        }

        Task::delay_until(&now, 10); //iterate 100 times a second

    }

}