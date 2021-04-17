#include "Arduino.h"
#include "LinearRegression.h"

//y = mx + b
void LinearRegression::learn(double x, double y){
    n++;
    meanX = meanX + ((x-meanX)/n);
    meanX2 = meanX2 + (((x*x)-meanX2)/n);
    varX = meanX2 - (meanX*meanX);

    meanY = meanY + ((y-meanY)/n);
    meanY2 = meanY2 + (((y*y)-meanY2)/n);
    varY = meanY2 - (meanY*meanY);

    meanXY = meanXY + (((x*y)-meanXY)/n);

    covarXY = meanXY - (meanX*meanY);

    m = covarXY / varX;
    b = meanY-(m*meanX);
}

void LinearRegression::learn(double x, double y, double w){
    if(w >= 1) { 
        learn(x,y);
    } else if(w <= 0) {
        return;
    } 

    x = x*w + meanX*(1-w);
    y = y*w + meanY*(1-w);
    learn(x, y);
}

double LinearRegression::correlation() {
    double stdX = sqrt(varX);
    double stdY = sqrt(varY);
    double stdXstdY = stdX*stdY;
    double correlation;

    if(stdXstdY == 0){
        correlation = 1;
    } else {
        correlation = covarXY / stdXstdY;
    }
    return correlation;
}

double LinearRegression::calculate(double x) {
    return (m*x) + b;
}

void LinearRegression::parameters(double values[]){
    values[0] = m;
    values[1] = b;
}

int LinearRegression::samples(){
    return n;
}

double LinearRegression::error(double x, double y) {    
    return abs(y - calculate(x));
}

void LinearRegression::reset(){
    meanX = 0;
    meanX2 = 0;
    varX = 0;
    meanY = 0;
    meanY2 = 0;
    varY = 0;
    meanXY = 0;
    covarXY = 0;
    n = 0;
    m = 0;
    b = 0;  
}
