#include "main.h"

void pwrArms(double voltPerc) {

    armsMtr.move_voltage(voltPerc * 12000 / 100); //divided percentage by 100 to get ratio and multiply ratio with 12000

}

double armsTarget = ARMS_FULLY_DOWN;
bool armsTaskActive = false;

void armsTask(void* param) {

    std::uint_least32_t now = millis();

    PID armsPID (0.25, 0.0005, 0);
    armsPID.setOutputBounds(0, 100);

    while(true) {

        if(armsTaskActive) {
        
        armsPID.setSetPoint(armsTarget);
        armsPID.setSystemVar(armsPot.get_value());

        pwrArms(armsPID.run());

        }

        Task::delay_until(&now, 10);

    }
    
}