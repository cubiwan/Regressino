#ifndef PotentialRegression_h
#define PotentialRegression_h

#include "Arduino.h"
#include "LinearRegression.h"

class PotentialRegression {
    public:
        void learn(double x, double y);
        double calculate(double x);
        double correlation();
        void parameters(double values[]);
        void reset();
        int samples();
    private:
        LinearRegression lr;
};

#endif