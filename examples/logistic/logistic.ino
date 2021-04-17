#include <LogisticRegression.h>

LogisticRegression lr = LogisticRegression();
double values[2];

void setup() {
    Serial.begin(9600);     
}

void loop() {
    Serial.println("Start learn");
    lr.learn(-1,0);  
    lr.learn(-2,0);
    lr.learn(-3,0);
    lr.learn(-4,0);
    lr.learn(1,1);
    lr.learn(2,1);
    lr.learn(3,1);
    lr.learn(4,1);
    //lr.learn(-2.5,1);//erroneous data, compare results


    Serial.println("End learn");

    for(int i = -10; i < 10; i++){
        Serial.print("Result (");
        Serial.print(i);
        Serial.print("): ");
        Serial.println(lr.calculate(i));    
    }

    Serial.print("Correlation: ");
    Serial.println(lr.correlation());

    Serial.print("Values: ");
    lr.parameters(values);
    Serial.print("Y = 1 / 1+e^-(");
    Serial.print(values[0]);
    Serial.print("x + ");
    Serial.print(values[1]); 
    Serial.println(")");

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
