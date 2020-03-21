#include <LogarithmicRegression.h>

LogarithmicRegression lr = LogarithmicRegression();
double values[2];

void setup() {
    Serial.begin(9600);     
}

void loop() {
    Serial.println("Start learn");
    lr.learn(1,3);  
    lr.learn(1.2,4);
    lr.learn(1.5,5);
    lr.learn(2,2);
    lr.learn(3,4.1);
    lr.learn(3.7,5);
    lr.learn(4,7);
    lr.learn(4.5,6.5);

    Serial.println("End learn");

    for(int i = 0; i < 100; i++){
        Serial.print("Result (");
        Serial.print(i);
        Serial.print("): ");
        Serial.println(lr.calculate(i));    
    }

    Serial.print("Correlation: ");
    Serial.println(lr.correlation());

    Serial.print("Values: ");
    lr.parameters(values);
    Serial.print("Y = ");
    Serial.print(values[0]);
    Serial.print("*ln(X) + ");
    Serial.println(values[1]); 

    Serial.println("Reset ->");
    lr.reset();

    Serial.print("Values: ");  
    lr.parameters(values);
    Serial.print(" a = ");
    Serial.print(values[0]);
    Serial.print(" b = ");
    Serial.println(values[1]); 
    Serial.println("");
    delay(5000);
}
