#ifndef LogarithmicRegression_h
#define LogarithmicRegression_h

#include "Arduino.h"
#include "LinearRegression.h"

class LogarithmicRegression {
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
