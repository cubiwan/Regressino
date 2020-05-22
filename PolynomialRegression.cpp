#include "Arduino.h"
#include "PolynomialRegression.h"

//Y = aX^2 + bX + c
void PolynomialRegression::learn(double x, double y){
    lr2d.learn(x*x,x,y);
}    

double PolynomialRegression::correlation() {
    return lr2d.correlation();
}

double PolynomialRegression::calculate(double x) {
    return lr2d.calculate(x*x,x);
}

void PolynomialRegression::parameters(double values[]){
    lr2d.parameters(values);
}

int PolynomialRegression::samples(){
    return lr2d.samples();
}

double PolynomialRegression::error(double x, double y) {    
    return abs(y - calculate(x));
}

void PolynomialRegression::reset(){
    lr2d.reset();
}


