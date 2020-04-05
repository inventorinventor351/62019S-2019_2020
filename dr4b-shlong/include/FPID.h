#ifndef _FPID_H_
#define _FPID_H_

class FPID {  //blueprint FPID, makes implementing the algorithm for different subsystems really easy

   private:              //member components that can only be accessed within the object
    double error,        //error between set point and system variable
        integral,        //total integral of error v. time, unless if its been disabled of course
        derivative,      //current change of error over known time interval
        setPoint,        //value that the system variable is trying to be
        systemVar,       //system variable, usually the sensor value itself
        prevSystemVar,   //system variable of the pervious iteration
        kF, kP, kI, kD,  //k constants for feed foward, proportional, integral, and derivative components of FPID
        output,          //calculated by FPID algorithm
        minOutput,       //lower bounds of the output
        maxOutput;       //upper bounds of the output
    bool integrate;      //enables and disables integral component of FPID

   public:                                                       //member components that can be accessed outside the object
    FPID(double _kF, double _kP, double _kI, double _kD);        //constructor, takes values for k constants for feed foward, proportional, integral, and derivative components of FPID
    void setSetPoint(double _error);                             //sets error for the FPID algorithm
    void setSystemVar(double _systemVar);                        //set system variable for the FPID algorithm
    void setOutputBounds(double _minOutput, double _maxOutput);  //sets bounds for the output
    double run();                                                //computes FPID algorithm
};

#endif