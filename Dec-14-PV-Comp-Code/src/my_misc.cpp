#include "main.h"

double sgn(double x) {

    return (x > 0) - (x < 0);

}

PID::PID(double _kP, double _kI, double _kD) {

    kP = _kP;
    kI = _kI;
    kD = _kD;

}

void PID::setError(double _error) {

    error = _error;

}

void PID::setSystemVar(double _systemVar) {

    systemVar = _systemVar;

}

void PID::setMaxOutput(double _maxOutput) {

    maxOutput = _maxOutput;

}

double PID::runPID() {

    integral += integrate ? error : 0;
    derivative = systemVar - prevSystemVar;
    prevSystemVar = systemVar;
    output = (kP * error) + (kI * integral) - (kD * derivative);

    if(fabs(output) > maxOutput) {

        integrate = (sgn(error) == sgn(output)) ? 0 : 1;
        return maxOutput * sgn(output);

    }

    else {

        integrate = 1;
        return output;

    }

}