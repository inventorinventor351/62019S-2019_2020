#include "main.h"

void pwrLift(double voltPerc)
{

    liftMtr.move_voltage(voltPerc * 12000 / 100); //divided percentage by 100 to get ratio and multiply ratio with 12000
}

double liftTarget = LIFT_FULLY_DOWN; //lift should stay down at start of program execution
bool liftTaskActive = false;         //lift task should be deactivated at start of program execution

void liftTask(void *param)
{

    std::uint_least32_t now = millis();

    FPID liftPID(0, 1, 0.01, 0);     //kF = 0, kP = 1, kI = 0.01, kD = 0
    liftPID.setOutputBounds(0, 100); //minOutput = 0%, maxOutput = 100%

    while (true)
    { //loop indefinitely

        if (liftTaskActive)
        { //if liftTaskActive equals true, then run code inside brackets

            liftPID.setSetPoint(liftTarget);              //set setpoint to the lift target specified by user
            liftPID.setSystemVar(liftMtr.get_position()); //set system variable to the lift motor encoder
            pwrLift(liftPID.run());                       //run FPID algorithm using variables specified above and power the lift motor to the output
        }

        //std::cout << liftTarget << "  |  " << liftMtr.get_position() << "  |  " << liftPID.run() << "\n";

        Task::delay_until(&now, 5); //iterate 200 times a second
    }
}