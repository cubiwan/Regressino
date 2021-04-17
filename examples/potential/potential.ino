#include <PotentialRegression.h>

PotentialRegression pr = PotentialRegression();
double values[2];

void setup() {
    Serial.begin(9600);     
}

void loop() {
    Serial.println("Start learn");
    pr.learn(10,1.06);
    pr.learn(20,1.33);
    pr.learn(30,1.52);
    pr.learn(40,1.68);
    pr.learn(50,1.81);
    pr.learn(60,1.91);
    pr.learn(70,2.01);
    pr.learn(80,2.11);

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
    Serial.print(" * X ^ ");
    Serial.println(values[1]); 

    Serial.println("Reset ->");
    pr.reset();

    Serial.print("Values: ");  
    pr.parameters(values);
    Serial.print(" a = ");
    Serial.print(values[0]);
    Serial.print(" b = ");
    Serial.println(values[1]); 
    Serial.println("");
    delay(5000);
}
