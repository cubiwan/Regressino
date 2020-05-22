#ifndef LinearRegression2d_h
#define LinearRegression2d_h

#include "Arduino.h"

class LinearRegression2d {
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
        double n = 0;    
        double x1y = 0;
        double x2y = 0;
        double x1x2 = 0;
        double x1x1 = 0;
        double x2x2 = 0;
        double meanX1 = 0;
        double meanX2 = 0;
        double meanY = 0;
        double div = 0;
        double b1 = 0;
        double b2 = 0;
        double a = 0;
        double meanX1X1 = 0;
        double varX1 = 0;        
        double meanX2X2 = 0;
        double varX2 = 0;
        double meanYY = 0;
        double varY = 0;
        double meanX1Y = 0;
        double meanX2Y = 0;
        double meanX1X2 = 0;
        double covarX1Y = 0;
        double covarX2Y = 0;
        double covarX1X2 = 0;
};

#endif