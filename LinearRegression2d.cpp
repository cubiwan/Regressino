#include "Arduino.h"
#include "LinearRegression2d.h"

//y = b1x1 + b2x2 + a
void LinearRegression2d::learn(double x1, double x2, double y){
    n++;
    
    x1y += x1*y;
    x2y += x2*y;
    x1x2 += x1*x2;
    x1x1 += x1*x1;
    x2x2 += x2*x2;
    meanX1 = meanX1 + ((x1-meanX1)/n);
    meanX2 = meanX2 + ((x2-meanX2)/n);
    meanY = meanY + ((y-meanY)/n);

    meanX1X1 = meanX1X1 + (((x1*x1)-meanX1X1)/n);
    varX1 = meanX1X1 - (meanX1*meanX1);
    
    meanX2X2 = meanX2X2 + (((x2*x2)-meanX2X2)/n);
    varX2 = meanX2X2 - (meanX2*meanX2);

    meanYY = meanYY + (((y*y)-meanYY)/n);
    varY = meanYY - (meanY*meanY);

    meanX1Y = meanX1Y + (((x1*y)-meanX1Y)/n);   
    meanX2Y = meanX2Y + (((x2*y)-meanX2Y)/n);
    meanX1X2 = meanX1X2 + (((x1*x2)-meanX1X2)/n);   

    covarX1Y = meanX1Y - (meanX1*meanY);
    covarX2Y = meanX2Y - (meanX2*meanY);
    covarX1X2 = meanX1X2 - (meanX1*meanX2);

    div = (x1x1*x2x2) - (x1x2*x1x2);
    b1 = ((x2x2*x1y) - (x1x2*x2y)) / div;
    b2 = ((x1x1*x2y) - (x1x2*x1y)) / div;
    a = meanY - b1*meanX1 - b2*meanX2;  
}

double LinearRegression2d::correlation() {
    double rX1Y = correlationX1Y();
    double rX2Y = correlationX2Y();
    double rX1X2 = correlationX1X2();

    return sqrt(((rX1Y*rX1Y)+(rX2Y*rX2Y) - 2*(rX1Y*rX2Y*rX1X2))/(1-(rX1X2*rX1X2)));
}

double LinearRegression2d::correlationX1Y() {
    double stdX1 = sqrt(varX1);
    double stdY = sqrt(varY);
    double stdX1stdY = stdX1*stdY;
    double correlation;

    if(stdX1stdY == 0){
        correlation = 1;
    } else {
        correlation = covarX1Y / stdX1stdY;
    }
    return correlation;
}

double LinearRegression2d::correlationX2Y() {
    double stdX2 = sqrt(varX2);
    double stdY = sqrt(varY);
    double stdX2stdY = stdX2*stdY;
    double correlation;

    if(stdX2stdY == 0){
        correlation = 1;
    } else {
        correlation = covarX2Y / stdX2stdY;
    }
    return correlation;
}

double LinearRegression2d::correlationX1X2() {
    double stdX1 = sqrt(varX1);
    double stdX2 = sqrt(varX2);
    double stdX1stdX2 = stdX1*stdX2;
    double correlation;

    if(stdX1stdX2 == 0){
        correlation = 1;
    } else {
        correlation = covarX1X2 / stdX1stdX2;
    }
    return correlation;
}

double LinearRegression2d::calculate(double x1, double x2) {
    return b1*x1 + b2*x2 + a;
}

void LinearRegression2d::parameters(double values[]){
    values[0] = b1;
    values[1] = b2;
    values[2] = a;
}

int LinearRegression2d::samples(){
    return n;
}

double LinearRegression2d::error(double x1, double x2, double y) {    
    return abs(y - calculate(x1, x2));
}

void LinearRegression2d::reset(){
    n = 0;    
    x1y = 0;
    x2y = 0;
    x1x2 = 0;
    x1x1 = 0;
    x2x2 = 0;
    meanX1 = 0;
    meanX2 = 0;
    meanY = 0;
    div = 0;
    b1 = 0;
    b2 = 0;
    a = 0;
    meanX1X1 = 0;
    varX1 = 0;        
    meanX2X2 = 0;
    varX2 = 0;
    meanYY = 0;
    varY = 0;
    meanX1Y = 0;
    meanX2Y = 0;
    meanX1X2 = 0;
    covarX1Y = 0;
    covarX2Y = 0;
    covarX1X2 = 0;
}