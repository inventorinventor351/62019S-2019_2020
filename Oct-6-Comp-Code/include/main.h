#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#ifdef __cplusplus //You can add C++-only headers here

#endif

#include "api.h"

using namespace pros;

//You should add more #includes here
#include "pragma.h"

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

#endif