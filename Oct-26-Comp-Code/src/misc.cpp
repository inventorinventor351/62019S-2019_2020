#include "main.h"

double sgn(double x) {

    return (x > 0) - (x < 0);

}

PID::PID(double _kP, double _kI, double _kD) {

    kP = _kP;
    kI = _kI;
    kD = _kD;

}

double PID::getError() {

    return error;

}

void PID::setError(double _error) {

    error = _error;

}

double PID::runPID() {

    integral += integrate ? error : 0;
    derivative = error - prevError;
    prevError = error;
    output = (kP * error) + (kI * integral) + (kD* derivative);

    if(abs(output) > maxSpeed) {

        integrate = (sgn(error) == sgn(output)) ? 0 : 1;
        return maxSpeed * sgn(output);

    }

    else {

        integrate = 1;
        return output;

    }

} 