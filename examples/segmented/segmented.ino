#include <LinearRegression.h>

//segmented
LinearRegression lr1 = LinearRegression();
LinearRegression lr2 = LinearRegression();
LinearRegression lr3 = LinearRegression();

//No segmented
LinearRegression lr = LinearRegression();

double values[2];

void setup() {
    Serial.begin(9600);     
}

void loop() {
    //[1,10] lr1 -> Y = X + 1
    //[11,20] lr2 -> Y = 2*X + 2
    //[21,30] lr3 -> Y = 3*X + 3

    Serial.println("Start learn");
    lr1.learn(1,2);  
    lr1.learn(2,3);
    lr1.learn(3,4);
    lr1.learn(6,7);
    lr1.learn(8,9);

    lr2.learn(11,24);  
    lr2.learn(12,26);
    lr2.learn(13,28);
    lr2.learn(16,34);
    lr2.learn(18,38);

    lr3.learn(21,66);  
    lr3.learn(22,69);
    lr3.learn(23,72);
    lr3.learn(26,81);
    lr3.learn(28,87);
    
    lr.learn(1,2);  
    lr.learn(2,3);
    lr.learn(3,4);
    lr.learn(6,7);
    lr.learn(8,9);
    lr.learn(11,24);  
    lr.learn(12,26);
    lr.learn(13,28);
    lr.learn(16,34);
    lr.learn(18,38);
    lr.learn(21,66);  
    lr.learn(22,69);
    lr.learn(23,72);
    lr.learn(26,81);
    lr.learn(28,87);
    Serial.println("End learn");

    Serial.println("Result (i): SEG , NO-SEG");

    for(int i = 0; i < 31; i++){
      Serial.print("Result (");
      Serial.print(i);
      Serial.print("): ");
      if(i < 11){
        Serial.print(lr1.calculate(i));    
      } else if(i < 21){
        Serial.print(lr2.calculate(i));
      } else {
        Serial.print(lr3.calculate(i));
      }
      Serial.print(" , ");
      Serial.println(lr.calculate(i));
    }

    Serial.println("Correlation: ");
    Serial.print("lr1: ");
    Serial.println(lr1.correlation());
    Serial.print("lr2: ");
    Serial.println(lr2.correlation());
    Serial.print("lr3: ");
    Serial.println(lr3.correlation());
    Serial.print("lr: ");
    Serial.println(lr.correlation());

    Serial.print("Values lr1: ");
    lr1.parameters(values);
    Serial.print("Y = ");
    Serial.print(values[0]);
    Serial.print("*X + ");
    Serial.println(values[1]); 

    Serial.print("Values lr2: ");
    lr2.parameters(values);
    Serial.print("Y = ");
    Serial.print(values[0]);
    Serial.print("*X + ");
    Serial.println(values[1]); 

    Serial.print("Values lr3: ");
    lr3.parameters(values);
    Serial.print("Y = ");
    Serial.print(values[0]);
    Serial.print("*X + ");
    Serial.println(values[1]);         
    
    Serial.print("Values lr: ");
    lr.parameters(values);
    Serial.print("Y = ");
    Serial.print(values[0]);
    Serial.print("*X + ");
    Serial.println(values[1]);       
    
    Serial.println("Reset");
    lr1.reset();
    lr2.reset();
    lr3.reset();
    lr.reset();

    delay(5000);
}
