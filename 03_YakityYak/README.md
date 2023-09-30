# NOTES

## Back to Root of Class
Click this link to back to go back to the root of the [C for Arduino Class](https://github.com/Mark-MDO47/CforArduinoClass "Link to C for Arduino Class")
- [https://github.com/Mark-MDO47/CforArduinoClass](https://github.com/Mark-MDO47/CforArduinoClass "Link to C for Arduino Class")

## Introduction

**Table Of Contents**


#### The Loop Code - for statement
[Back to Top](#notes "Back to Top")<br>
Inside the last **if** statement there is a statement **int f, c; // fahrenheit and centigrade** followed by **for (f = 0; f < 130; f += 10)**. What do these do?

First the **int** statement with a comma: this just means that both variables **f** and **c** are integers; the **int** applies to both of them. There can be tricky applications like what would happen if we said **int f, c = 5;**? Would both **f** and **c** be initialized to 5? This is an introductory class so I won't go into those type of detailed questions here. If you want to initialize both of them, you already know how to do that with two statements and no comma: **int f = 5; int c = 5;**.

The **for** statement (and the for loop that it generates) is an extremely useful and common happening in C/C++. it is divided into three parts by semicolons:
- **f = 0** - this is the initialization section, where you can initialize any variable before the for loop starts
  - If needed you can initialize more than one variable by separating with commas. Example: **f = 0, c = 1**
  - You can even define and initialize new variables in the initialization section that only affect the for loop. Example: **int new_variable = 7, f = 0, c = 1**
- **f < 130** - this is the definition of the **condition** that must be true to execute anything in the for statement
  - Pro Tip: it is checked BEFORE THE FIRST EXECUTION of the for loop. If it is false, the loop never executes.
- **f += 10** - this is the action taken AFTER each loop and BEFORE checking the **condition**.
  - Again, multiple actions could be taken. Example: **f += 10, Serial.println("Made f bigger")**

This for loop is seen below:
```C
  int f, c; // fahrenheit and centigrade
  Serial.println("\nFahrenheit and Centigrade computed with integers");
  for (f = 0; f < 130; f += 10) { // last loop will be 120 since 130 is not < 130
    c = ((f - 32) * 5) / 9;
    Serial.print(" degF, degC: "); Serial.print(f); Serial.print(", "); Serial.println(c);
  } // end Fahrenheit and Centigrade for loop
```

The for loop behaves **somewhat** like the following:
```C
  int f, c; // fahrenheit and centigrade
  Serial.println("\nFahrenheit and Centigrade computed with integers");
  //
  // for (f = 0; f < 130; f += 10) { // last loop will be 120 since 130 is not < 130
  //
  // initialization section
  f = 0;
  // condition
  if (f < 130) {
    // loop
    c = ((f - 32) * 5) / 9;
    Serial.print(" degF, degC: "); Serial.print(f); Serial.print(", "); Serial.println(c);
  }
  // action after LOOP
  f += 10;
  // condition
  if (f < 130) {
    // loop
    c = ((f - 32) * 5) / 9;
    Serial.print(" degF, degC: "); Serial.print(f); Serial.print(", "); Serial.println(c);
  }
  // action after LOOP
  f += 10;
  // condition
  if (f < 130) {
    // loop
    c = ((f - 32) * 5) / 9;
    Serial.print(" degF, degC: "); Serial.print(f); Serial.print(", "); Serial.println(c);
  }
  // etc. - this doesn't take care of the case where (f < 130) is false, but you see the gist of it
```

As the comment says, this doesn't take care of the case where (f < 130) is false, but you see the gist of it.

