#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#include "api.h"
#include "pros/apix.h"

using namespace pros;

#ifdef __cplusplus
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

#ifdef __cplusplus



#endif

#endif
