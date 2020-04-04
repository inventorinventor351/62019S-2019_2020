#include "main.h"

FPID::FPID(double _kF, double _kP, double _kI, double _kD)
{

    kF = _kF;
    kP = _kP;
    kI = _kI;
    kD = _kD;
}

void FPID::setSetPoint(double _setPoint)
{

    setPoint = _setPoint;
}

void FPID::setSystemVar(double _systemVar)
{

    systemVar = _systemVar;
}

void FPID::setOutputBounds(double _minOutput, double _maxOutput)
{

    minOutput = _minOutput;
    maxOutput = _maxOutput;
}

double FPID::run()
{

    error = setPoint - systemVar;                                                                                //error is just where controller wants to be minus where it is right now
    integral += integrate ? error : 0;                                                                           //estimate integral of error v. time by summing error over known constant time intervals
    derivative = systemVar - prevSystemVar;                                                                      //estimate derivative with slope formula: (y2 - y1) / (x2 - x1), realize denominator is constant for a known constant time interval
    prevSystemVar = systemVar;                                                                                   //set previous system variable to current system variable in order to use it next iteration
    output = (kF * setPoint + (minOutput * sgn(setPoint))) + (kP * error) + (kI * integral) - (kD * derivative); //calculate output by summing all components of FPID

    if (fabs(output) >= maxOutput)
    { //integral windup prevention

        integrate = (sgn(error) == sgn(output)) ? false : true; //if absolute value of ouput is greater than max output AND the sign of the error is the same as the sign of the ouput, then stop integrating
        return maxOutput * sgn(output);
    }

    else
    {

        integrate = true;
        return output;
    }
}