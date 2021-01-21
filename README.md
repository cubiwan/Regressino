# Regressino &nbsp;&nbsp;&nbsp;&nbsp;<a href='https://ko-fi.com/I2I012UF3' target='_blank'><img height='36' style='border:0px;height:36px;' src='https://az743702.vo.msecnd.net/cdn/kofi1.png?v=2' border='0' alt='Buy Me a Coffee at ko-fi.com' /></a>

Library to calculate potential, exponential, logarithmic, lineal and logistic regression in Arduino.

Lineal: **Y = a*X + b**  
Exponential: **Y = b * e^(a*X)**   
Logarithmic: **Y = a*ln(X) + b**  
Potential: **Y = b * x^a**  
Logistic: **Y = 1 / (1 + e^-(a*x+b))**  
Polynomial: **Y = a1*x^2 + a2*x + b**  
Linear2d: **Y = a1*x1 + a2*x2 + b**  
Logistic2d:**Y = 1 / (1 + e^-(1*x1 + a2*x2 + b))** 

Graphs with a = 2 and b = 3:

![](https://raw.githubusercontent.com/cubiwan/Regressino/master/Regressino.png)

Logistic regression:

![](https://raw.githubusercontent.com/cubiwan/Regressino/master/Logistic.png)

Polynomial regression:

![](https://raw.githubusercontent.com/cubiwan/Regressino/master/polynomial.png)

Linear and Logistic 2 variables

![](https://raw.githubusercontent.com/cubiwan/Regressino/master/Linear2.png)

## Use

### Include 

#### 1 variable

#### Linear 

```c
#include <LinearRegression.h>

LinearRegression lr = LinearRegression();
```

#### Exponential 

```c
#include <ExponentialRegression.h>

ExponentialRegression er = ExponentialRegression;
```

#### Logarithmic 

```c
#include <LogarithmicRegression.h>

LogarithmicRegression lr = LogarithmicRegression();
```

#### Potential

```c
#include <PotentialRegression.h>

PotentialRegression pr = PotentialRegression();
```

#### Logistic

```c
#include <LogisticRegression.h>

LogisticRegression pr = LogisticRegression();
```

#### Polynomial

```c
#include < PolynomialRegression.h>

 PolynomialRegression pr =  PolynomialRegression();
```

#### 2 variables

#### Linear2d

```c
#include <LinearRegression2d.h>

LinearRegression lr = LinearRegression2d();
```

#### Logistic2d 

```c
#include <LogisticRegression2d.h>

LogisticRegression pr = LogisticRegression2d();
```

### Methods 1 variable

```c
void learn(double x, double y);  
```

Learns one example.
* x: value of X
* y: value of Y  
<br>
  
```c
double calculate(double x1);  
```

Estimates value of Y for X
* x: value of x  
<br>
  
```c
double correlation();  
```

Return correlation value  
<br>
   
```c
void reset();  
```

Reset values. Start learning since zero.  
<br>
  
```c
void parameters(double values[]);
```

Return parameters of the regression *y = mx + b*
* values[0] = m;
* values[1] = b;  

In polynomial values are *y = b1x^2 + b2x + a* :
* values[0] = b1;
* values[1] = b2;  
* values[2] = a;  
<br>  

```c
double error(double x, double y);  
```
  
Return estimation error. If you need more options to calculate error you can use error module from [SimpleStatisticsArduino](https://github.com/cubiwan/SimpleStatisticsArduino)  
<br>
  
```c
void samples();
```
Return number of examples learned


### Methods 2 variables

```c
void learn(double x1, double x2, double y);  
```

Learns one example.
* x1: value of X1
* x2: value of X2
* y: value of Y  
<br>
  
```c
double calculate(double x1, double x2);  
```

Estimates value of Y 
* x1: value of x1 
* x2: value of x2  
<br>
  
```c
double correlation();  
```

Return correlation value  
<br>

```c
double correlationX1Y();  
```

Return correlation value between X1 and Y
<br>

```c
double correlationX1Y();  
```

Return correlation value between X1 and Y
<br>
   
```c
double correlationX2Y();  
```

Return correlation value between X2 and Y
<br>
   
```c
double correlationX1X2();  
```

Return correlation value between X1 and X2
<br>
      

```c
void reset();  
```

Reset values. Start learning since zero.  
<br>
  
```c
void parameters(double values[]);
```

Return parameters of the regression *y = b1x1 + b2x2 + a*
* values[0] = b1;
* values[1] = b2;
* values[2] = a;  
<br>  

```c
double error(double x1, double x2, double y);  
```
  
Return estimation error. If you need more options to calculate error you can use error module from [SimpleStatisticsArduino](https://github.com/cubiwan/SimpleStatisticsArduino) 
<br>
  
```c
void samples();
```
Return number of examples learned
