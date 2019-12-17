#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define _USE_MATH_DEFINES //allows use of already defined mathematical constants
#include "api.h" //includes PROS library that is needed to control motors and read sensor values
#include "pros/apix.h" //includes addition tools from PROS, most importantly LLEMU functionality (aka custom v5 screen UI)

using namespace pros; //don't have to "pros::" every time

#ifdef __cplusplus //declarations of PROS's main functions
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus //inclusions of other project files, sorta brings the whole thing together

#include "pragma.h" //creates objects for all sensors, motors, and controllers that robot uses
#include "PID.h" //reusable PID class that makes motor control easier and more portable
#include "subsystems/base.h" //methods and tasks related to the base
#include "subsystems/rollers.h" //methods and tasks related to the intake rollers
#include "subsystems/tray.h" //methods and tasks related to the tray
#include "subsystems/lift.h" //methods and tasks related to the dr4b lift
#include "autonRoutines.h" //methods related to robot macros and autonomi

#endif

#endif
