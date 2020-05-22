#ifndef LinearRegression_h
#define LinearRegression_h

#include "Arduino.h"
#include "LinearRegression2d.h"

class PolynomialRegression {
    public:
        void learn(double x, double y);
        double calculate(double x);
        double correlation();
        void parameters(double values[]);
        void reset();
        int samples();
        double error(double x, double y); 
    private:
        LinearRegression2d lr2d;
};

#endif
