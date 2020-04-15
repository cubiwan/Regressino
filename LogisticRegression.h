#ifndef LogisticRegression_h
#define LogisticRegression_h

#include "Arduino.h"
#include "LinearRegression.h"

class LogisticRegression {
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