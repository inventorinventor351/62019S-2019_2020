#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#ifdef __cplusplus //c++ only headers like <iostream>

    #include <cmath>

#endif

#include "./pros/apix.h" //include PROS extend api

using namespace pros; //instead of pros::Motor(), it's just Motor()

//Include Project Files
#include "config.h"
#include "pragma.h"
#include "misc.h"
#include "./subsystems/base.h"
#include "./subsystems/intake.h"
#include "./subsystems/lift.h"
#include "autons.h"

#ifdef __cplusplus //DO NOT TOUCH

    extern "C" {

#endif

        void autonomous(void);
        void initialize(void);
        void disabled(void);
        void competition_initialize(void);
        void opcontrol(void);

#ifdef __cplusplus

    }

#endif //DO NOT TOUCH

#endif  // _PROS_MAIN_H_
