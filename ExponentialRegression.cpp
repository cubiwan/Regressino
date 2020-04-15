#include "Arduino.h"
#include "LinearRegression.h"
#include "ExponentialRegression.h"

const double e=2.71828;

//y = b*e^ax => ln(y) = ax + ln(b)
void ExponentialRegression::learn(double x, double y){
    lr.learn(x,log(y));
}    

double ExponentialRegression::correlation() {
    return lr.correlation();
}

double ExponentialRegression::calculate(double x) {
    double values[2]; //p[0] is a; p[1] is b
    lr.parameters(values); 
    double a = values[0];
    double b = pow(e, values[1]);
    return b*pow(e, a*x);
}

void ExponentialRegression::parameters(double values[]){    
    lr.parameters(values);
    values[1] = pow(e, values[1]);    
}

int ExponentialRegression::samples(){
    return lr.samples();
}

double ExponentialRegression::error(double x, double y) {    
    return abs(y - calculate(x));
}

void ExponentialRegression::reset(){
    lr.reset();
}
