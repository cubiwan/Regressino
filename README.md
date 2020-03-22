# Regressino &nbsp;&nbsp;&nbsp;&nbsp;<a href='https://ko-fi.com/I2I012UF3' target='_blank'><img height='36' style='border:0px;height:36px;' src='https://az743702.vo.msecnd.net/cdn/kofi1.png?v=2' border='0' alt='Buy Me a Coffee at ko-fi.com' /></a>

Library to calculate potential, exponential, logarithmic, and lineal regression in Arduino.


### Include

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

### Methods

```c
void learn(int x, int y);  
```

Learns one example.
* x: value of X
* y: value of Y

  
```c
double calculate(int x);  
```

Estimates value of Y for X
* x: value of x 



```c
double correlation();  
```

Return actual correlation value

   
```c
void reset();  
```

Reset values. Start learning since zero.

  
```c
void parameters(double values[]);
```

Return parameters of the regression
* values[0] = a;
* values[1] = b;

Lineal: **Y = a*X + b**  
Exponential: **Y = b * e^(a*X)**   
Logarithmic: **Y = a*ln(X) + b**  
Potential: **Y = b * x^a**  
  
  
```c
void samples();
```
Return number of examples learned


