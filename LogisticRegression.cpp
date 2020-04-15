#include "Arduino.h"
#include "LinearRegression.h"
#include "LogisticRegression.h"

const double e=2.71828;

void LogisticRegression::learn(double x, double y){
    lr.learn(x,y);
}    

double LogisticRegression::correlation() {
    return lr.correlation();
}

double LogisticRegression::calculate(double x) {    
    double exp = lr.calculate(x)*-1; //-exp
    return 1/(1+pow(e, exp));
}

void LogisticRegression::parameters(double values[]){
    lr.parameters(values);
}

int LogisticRegression::samples(){
    return lr.samples();
}

double LogisticRegression::error(double x, double y) {    
    return abs(y - calculate(x));
}

void LogisticRegression::reset(){
    lr.reset();
}


