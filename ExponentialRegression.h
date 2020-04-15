#ifndef ExponentialRegression_h
#define ExponentialRegression_h

#include "Arduino.h"
#include "LinearRegression.h"

class ExponentialRegression {
    public:
        void learn(double x, double y);
        double calculate(double x);
        double correlation();
        void parameters(double values[]);
        void reset();
        int samples();
        double error(double x, double y);    
    private:
        LinearRegression lr;
};

#endif
