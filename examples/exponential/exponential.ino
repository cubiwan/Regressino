#include <ExponentialRegression.h>

ExponentialRegression er = ExponentialRegression();
double values[2];

void setup() {
    Serial.begin(9600);     
}

void loop() {
    Serial.println("Start learn");
    er.learn(12,930);
    er.learn(41,815);
    er.learn(93,632);
    er.learn(147,487);
    er.learn(204,370);
    er.learn(264,265);
    er.learn(373,147);
    er.learn(509,76);
    er.learn(773,17);


    Serial.println("End learn");

    for(int i = 0; i < 100; i++){
        Serial.print("Result (");
        Serial.print(i);
        Serial.print("): ");
        Serial.println(er.calculate(i));    
    }

    Serial.print("Correlation: ");
    Serial.println(er.correlation());

    Serial.print("Values: ");
    er.parameters(values);
    Serial.print("Y = ");
    Serial.print(values[1]);
    Serial.print("*e ^");
    Serial.print(values[0]); 
    Serial.println("* X"); 

    Serial.println("Reset ->");
    er.reset();

    Serial.print("Values: ");  
    er.parameters(values);
    Serial.print(" a = ");
    Serial.print(values[0]);
    Serial.print(" b = ");
    Serial.println(values[1]); 
    Serial.println("");
    delay(5000);
}
