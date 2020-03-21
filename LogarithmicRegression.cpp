#include "Arduino.h"
#include "LinearRegression.h"
#include "LogarithmicRegression.h"

//y = a*ln(x)+b
void LogarithmicRegression::learn(double x, double y){
    lr.learn(log(x),y);
}    

double LogarithmicRegression::correlation() {
    return lr.correlation();
}

double LogarithmicRegression::calculate(double x) {
    return lr.calculate(log(x));
}

void LogarithmicRegression::parameters(double values[]){
    lr.parameters(values);
}

int LogarithmicRegression::samples(){
    return lr.samples();
}

void LogarithmicRegression::reset(){
    lr.reset();
}
