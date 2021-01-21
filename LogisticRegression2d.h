#ifndef LogisticRegression_h
#define LogisticRegression_h

#include "Arduino.h"
#include "LinearRegression2d.h"

class LogisticRegression2d {
    public:
        void learn(double x1, double x2, double y);
        double calculate(double x1, double x2);
        double correlation();
        double correlationX1Y();
        double correlationX2Y();
        double correlationX1X2();
        void parameters(double values[]);
        void reset();
        int samples();
        double error(double x1, double x2, double y); 
    private:
        LinearRegression2d lr2d;
};

#endif