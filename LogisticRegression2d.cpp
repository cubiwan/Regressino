#include "Arduino.h"
#include "LogisticRegression2d.h"

const double e=2.71828;

//y = b1x1 + b2x2 + a
void LogisticRegression2d::learn(double x1, double x2, double y){
    lr2d.learn(x1,x2,y);
}

double LogisticRegression2d::correlation() {
    return lr2d.correlation();
}

double LogisticRegression2d::correlationX1Y() {
    return lr2d.correlationX1Y();
}

double LogisticRegression2d::correlationX2Y() {
    return lr2d.correlationX2Y();
}

double LogisticRegression2d::correlationX1X2() {
    return lr2d.correlationX1X2();
}

double LogisticRegression2d::calculate(double x1, double x2) {
    double exp = lr2d.calculate(x1,x2)*-1; //-exp
    return 1/(1+pow(e, exp));
}

void LogisticRegression2d::parameters(double values[]){
    lr2d.parameters(values);
}

int LogisticRegression2d::samples(){
    return lr2d.samples();
}

double LogisticRegression2d::error(double x1, double x2, double y) {    
    return lr2d.error(x1, x2, y);
}

void LogisticRegression2d::reset(){
    lr2d.reset();
}
