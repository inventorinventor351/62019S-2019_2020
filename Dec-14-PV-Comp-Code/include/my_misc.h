#ifndef _MY_MISC_H_
#define _MY_MISC_H_

double sgn(double x);

class PID {

    private:
    double error,
    integral,
    derivative,
    systemVar,
    prevSystemVar,
    kP, kI, kD,
    output,
    maxOutput;
    bool integrate;

    public:
    PID(double _kP, double _kI, double _kD);
    void setError(double _error);
    void setSystemVar(double _systemVar);
    void setMaxOutput(double _maxOutput);
    double runPID();

};

#endif