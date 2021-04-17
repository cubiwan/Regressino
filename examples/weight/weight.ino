#include <LinearRegression.h>

LinearRegression lr = LinearRegression();
LinearRegression lrw = LinearRegression();
double values[2];

void setup() {
    Serial.begin(9600);     
}

void loop() {
    Serial.println("Start learn");
    lr.learn(1,3);  
    lr.learn(2,1);
    lr.learn(3,3);
    lr.learn(4,1);
    lr.learn(5,3);
    lr.learn(6,1);
    lr.learn(7,3);
    lr.learn(8,1);
    lr.learn(9,3);

    lrw.learn(1,3,1);  
    lrw.learn(2,1,0.5);
    lrw.learn(3,3,1);
    lrw.learn(4,1,0.5);
    lrw.learn(5,3,1);
    lrw.learn(6,1,0.5);
    lrw.learn(7,3,1);
    lrw.learn(8,1,0.5);
    lrw.learn(9,3,1);

    Serial.println("End learn");


    Serial.println("Correlation: ");
    Serial.println(lr.correlation());
    Serial.println(lrw.correlation());

    Serial.print("Values lr: ");
    lr.parameters(values);
    Serial.print("Y = ");
    Serial.print(values[0]);
    Serial.print("*X + ");
    Serial.println(values[1]); 

    Serial.print("Values lrw: ");
    lrw.parameters(values);
    Serial.print("Y = ");
    Serial.print(values[0]);
    Serial.print("*X + ");
    Serial.println(values[1]); 


    Serial.println("Reset");
    lr.reset();
    lrw.reset();
    
    delay(5000);
}
