#include "Arduino.h"
#include "LinearRegression.h"
#include "PotentialRegression.h"

const double e=2.71828;

//y = b*x^a => ln(y) = a*ln(x)+10^b
void PotentialRegression::learn(double x, double y){
    lr.learn(log10(x),log10(y));
}    

double PotentialRegression::correlation() {
    return lr.correlation();
}

double PotentialRegression::calculate(double x) {
    double values[2]; 
    lr.parameters(values); 
    double a = values[0];
    double b = pow(10, values[1]);
    return b*pow(x, a);
}

void PotentialRegression::parameters(double values[]){    
    lr.parameters(values);
    values[1] = pow(10, values[1]);   
}

int PotentialRegression::samples(){
    return lr.samples();
}

double PotentialRegression::error(double x, double y) {    
    return abs(y - calculate(x));
}

void PotentialRegression::reset(){
    lr.reset();
}
