#ifndef _PID_H_
#define _PID_H_

class PID { //blueprint PID, makes implementing the algorithm for different subsystems really easy

    private: //member components that can only be accessed within the object
    double error, //error between set point and system variable
    integral, //total integral of error v. time, unless if its been disabled of course
    derivative, //current change of error over known time interval
    setPoint, //value that the system variable is trying to be
    systemVar, //system variable, usually the sensor value itself
    prevSystemVar, //system variable of the pervious iteration
    kP, kI, kD, //k constants for proportional, integral, and derivative components of FPID
    output, //calculated by PID algorithm
    minOutput, //lower bounds of the output
    maxOutput; //upper bounds of the output
    bool integrate; //enables and disables integral component of FPID

    public: //member components that can be accessed outside the object
    PID(double _kP, double _kI, double _kD); //constructor, takes values for k constants for proportional, integral, and derivative components of PID
    void setSetPoint(double _error); //sets error for the FPID algorithm
    void setSystemVar(double _systemVar); //set system variable for the PID algorithm
    void setOutputBounds(double _minOutput, double _maxOutput); //sets bounds for the output
    double run(); //computes PID algorithm

};

#endif