#include "main.h"

double sgn(double x) { //returns sign (-1 or 1) of a number, and 0 for 0

	return (x > 0) - (x < 0); //really cool way of finding sign of a number

}

void betterDelay(int ms) { //delays for a certain number for milliseconds

	std::uint_least32_t now = millis();

    for(int i = 0; i < ms; i++) { //loop for how many milliseconds passed through

       Task::delay_until(&now, 1); //iterate 1000 times per second

    }

}

void disabled() { //disable all subsystems



}

void initialize() { //set motor break modes and start subsystem tasks
	


}

void competition_initialize() { //display auton selector



}

void autonomous() { //run auton that was selector from auton selector



}


void opcontrol() { //run driver controls



	while (true) {

		
		
	}

}
