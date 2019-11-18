#include "main.h"

void runIntk(double percVolt) {

    intake1.move_voltage(percVolt * 12000 / 100);
    intake2.move_voltage(percVolt * 12000 / 100);

}

void runTray(double percVolt) {

    tray1.move_voltage(percVolt * 12000 / 100);
    tray2.move_voltage(percVolt * 12000 / 100);

}

void preciseTray(double pos, double time) {

    PID tray(0.075, 0, 0);
	tray.maxSpeed = 60;

    std::uint_least32_t now = millis();

    for(int i = 0; i < time; i++) {

        tray.setError(trayPot.get_value() - pos);
		runTray(tray.runPID());

        Task::delay_until(&now, 1);

    }

    runTray(0);

}