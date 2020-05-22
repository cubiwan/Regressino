#include <PolynomialRegression.h>

PolynomialRegression pr = PolynomialRegression();
double values[3];

void setup() {
    Serial.begin(9600);     
}

void loop() {
    Serial.println("Start learn");
    //Y = 2*x*x + 3*x + 1
    pr.learn(1,6);  
    pr.learn(2,15);
    pr.learn(5,66);
    pr.learn(9,190);
    pr.learn(10,231);
    Serial.println("End learn");

    for(int i = 0; i < 100; i++){
        Serial.print("Result (");
        Serial.print(i);
        Serial.print("): ");
        Serial.println(pr.calculate(i));    
    }

    Serial.print("Correlation: ");
    Serial.println(pr.correlation());

    Serial.print("Values: ");
    pr.parameters(values);
    Serial.print("Y = ");
    Serial.print(values[0]);
    Serial.print("*X^2 + ");
    Serial.print(values[1]); 
    Serial.print("*X + ");
    Serial.println(values[2]); 

    Serial.println("Reset ->");
    pr.reset();
    
    delay(5000);
}
