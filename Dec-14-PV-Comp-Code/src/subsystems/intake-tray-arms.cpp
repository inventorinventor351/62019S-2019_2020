#include "main.h"

void runIntake(double percVolt) {

    intake1.move_voltage(percVolt * 12000 / 100);
    intake2.move_voltage(percVolt * 12000 / 100);

}

void runTray(double percVolt) {

    tray.move_voltage(percVolt * 12000 / 100);

}

void runArms(double percVolt) {

    arms.move_voltage(percVolt * 12000 / 100);

}

void trayTask(void* param) {

    std::uint_least32_t now = millis();

    while(true) {

        Task::delay_until(&now, 1);

    }

}

void armsTask(void* param) {

    std::uint_least32_t now = millis();

    while(true) {

        Task::delay_until(&now, 1);

    }
    
}