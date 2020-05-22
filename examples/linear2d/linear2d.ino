#include <LinearRegression2d.h>

LinearRegression2d lr = LinearRegression2d();
double values[2];

void setup() {
    Serial.begin(9600);     
}

void loop() {
    Serial.println("Start learn");
    //y = 0.5*x1 + 3*x2 + 0.75
    lr.learn(1, 1, 4.25);
    lr.learn(0.5, 2, 7);
    lr.learn(2, 1, 4.75);
    lr.learn(4, 6, 22.75);
    lr.learn(3, 2, 8.25);


    Serial.println("End learn");

    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            Serial.print("Result (");
            Serial.print(i);
            Serial.print(", "); 
            Serial.print(j);
            Serial.print("): ");
            Serial.println(lr.calculate(i,j));
        }
    }

    Serial.print("Correlation: ");
    Serial.println(lr.correlation());

    Serial.print("Values: ");
    lr.parameters(values);
    Serial.print("Y = ");
    Serial.print(values[1]);
    Serial.print("*X1 + ");
    Serial.print(values[1]);
    Serial.print("*X2 + ");
    Serial.println(values[2]); 

    Serial.println("Reset");
    lr.reset();
    
    delay(5000);
}
