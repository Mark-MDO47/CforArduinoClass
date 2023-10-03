# NOTES

## Back to Root of Class
Click this link to back to go back to the root of the [C for Arduino Class](https://github.com/Mark-MDO47/CforArduinoClass "Link to C for Arduino Class")
- [https://github.com/Mark-MDO47/CforArduinoClass](https://github.com/Mark-MDO47/CforArduinoClass "Link to C for Arduino Class")

## Introduction
[Back to Top](#notes "Back to Top")<br>
In this section we will investigate reading input from the USB serial port and using it to affect our code operation.

Some of the code might get a little complicated. Don't worry, this is a first introduction so just try to follow the flow and get used to what code does. Also I left some debugging code in so you can see a couple of debugging techniques.

**Table Of Contents**
* [Top](#notes "Top")
* [Back to Root of Class](#back-to-root-of-class "Back to Root of Class")
* [Introduction](#introduction "Introduction")
* [The setup code](#the-setup-code "The setup code")
  * [The setup Code - before the setup Code](#the-setup-code-\--before-the-setup-code "The setup Code - before the setup Code")
  * [The setup Code - initialization](#the-setup-code-\--initialization "The setup Code - initialization")
  * [The setup Code - for loop inside the parenthesis](#the-setup-code-\--for-loop-inside-the-parenthesis "The setup Code - for loop inside the parenthesis")
  * [The setup Code - for loop inside the curly braces](#the-setup-code-\--for-loop-inside-the-curly-braces "The setup Code - for loop inside the curly braces")

## The setup code
[Back to Top](#notes "Back to Top")<br>
One thing I want to point out is that there is nothing magic about the **setup()** and **loop()** code. It is there for your convenience, but in this section we will only use the **setup()** and not do the **loop()** ever.

You can imagine that the code that calls **setup()** and **loop()** looks something like this:
```C
#define TRUE 1
void main() {
  setup();
  while (TRUE) {
    loop();
  } // end while()
} // end main()
```

This code would call **setup()** once and then loop forever calling **loop()**. This is because the **while () {}** statement will repeat the code inside the **{}** block as long as the condition inside the **()** is non-zero. Because we did **#define TRUE 1**, that will always be the case.

One way to break out of any loop is with the **break** statement. This would quit executing the loop **{}** block and continue on the next code statement after the loop **{}** block. This works for all types of loops.

In fact the code underneath **setup()** and **loop()** is more complicated than my code above, but you can almost always do your code as if it was being called from the above.

### The setup Code - before the setup Code
[Back to Top](#notes "Back to Top")<br>
We have a few routines definitions before the setup Code. Here is a little map:
| What | Description |
| --- | --- |
| #define's | We #define TRUE, FALSE, DO_DEBUG, and DO_DEBUG_INPUT.<br>The DEBUG #defines control macro definitions for things such as DEBUG_PRINT and DEBUG_PRINTLN. These statements can be sprinkled around to help debugging. After debugging is complete, DO_DEBUG and DO_DEBUG_INPUT can be #defined as 0 and the statements won't compile. |
| #define's | #define NUMOF(x) (sizeof((x)) / sizeof((*x))) // calculates the size of an array<br>This simple version of NUMOF is quite handy: it gives the number of elements in an array. We will use it with the array of character pointers named DAD_JOKES. The reason NUMOF is simple is that it doesn't try to do everything. If you give it something that is not an array and doesn't behave like an array, it will cheerfully give a compile error or quietly give you a nonsense number |
| get_3_int_values() | Routine to get three integer values from the USB serial port then flush to '\n'<br>'\n' is end of line; called **newline**<br>When you call this routine it will not return until it gets three integers. You can enter them all on one line such as "1,2,3" or enter each number on a separate line without using commas. If you enter "1,2,3,fred" it will ignore everything after the "," following 3. |
| get_one_string() | Routine to get one string (no leading or trailing ' ' or '\t') then flush to '\n'<br>'\t' is the **TAB** character<br>IF you enter "Fred Joe Mary" it will just return "Fred". |
| setup() | Initializes everything then does a forever loop with **while (TRUE) {}**.<br>Inside the while loop it asks "Enter T (Temp), J (Joke), C (ChooseJoke), or A (AllJoke)"<br>T (or t) asks for three integer parameters for a **for loop** converting degrees Fahrenheit to degrees Centigrade.<br>J gives you the next Dad Joke in its list.<br>C asks for three integer numbers to have the corresponding Dad Jokes printed.<br>A gives you all the Dad Jokes. |

### The setup Code - initialization
[Back to Top](#notes "Back to Top")<br>
```C
void setup() {
  // this serial communication is for general debug; set the USB serial port to 115,200 baud
  Serial.begin(115200);
  while (!Serial) {
    ; // note that ";" is a null code statement. Wait for serial port to connect.
  }
  while (Serial.available()) Serial.read(); // clear any startup junk from the serial queue

  Serial.println(""); // print a blank line in case there is some junk from power-on
  Serial.println(F("CforArduinoClass init..."));

  DEBUG_PRINT(F("\nNUMOF_DAD_JOKES ")); DEBUG_PRINTLN(NUMOF_DAD_JOKES); DEBUG_PRINTLN(F(""));
```

The serial initialization code looks pretty familiar with a **while (!Serial) { ; }** loop on three lines.

Next there is a **while (Serial.available()) Serial.read();**. Where are the curly braces?
- The answer is that in any block statement such as **if () {}** or **while () {}**, if there is only one code statement to be executed in the block you don't need the curly braces. If there is more than one code statement, you need the curly braces to show what is inside the block.

We start to do the normal prints and then we get **Serial.println(F("CforArduinoClass init..."));**. What is the **F()** doing there?
- The F() surrounding the string places the string into **PROGMEM** instead of **RAM**. The Arduino Nano has very little RAM but much more PROGMEM.
- Using PROGMEM usually requires some extra code, but replacing a double-quoted string in a function or method call is as simple as surrounding it with **F()**.
- I did this trick throughout the code so there would be more room for Dad Jokes.
- You can find more info about this in the Resources page from the Arduino Class: [PROGMEM and F macro to save RAM](https://github.com/Mark-MDO47/ArduinoClass/blob/master/99_Resources/README.md#progmem-and-f-macro-to-save-ram "PROGMEM and F macro to save RAM")

Then we see **DEBUG_PRINT(F("\nNUMOF_DAD_JOKES ")); DEBUG_PRINTLN(NUMOF_DAD_JOKES); DEBUG_PRINTLN(F(""));**. This is some debug code I put in to test my "#define NUMOF" macro.
- #define macros can get pretty complex. I won't really describe how they work here.
- If you are interested you might start with https://en.wikibooks.org/wiki/C_Programming/Preprocessor_directives_and_macros and search for #define
- NUMOF() was a simple to moderately-complicated macro to return the number of array elements in its parameter.
- I had an earlier statement **int NUMOF_DAD_JOKES = NUMOF(DAD_JOKES);** which initialized the variable NUMOF_DAD_JOKES with the number of elements in the array DAD_JOKES.
- DEBUG_PRINT() and DEBUG_PRINTLN() are simple macros that either turn into Serial.print() or Serial.println(). They can be set to just return blanks so there is no print statement.
- I left these DEBUG_ macros in the code since they can be pretty handy for debugging. When it seems to work you can turn them off. If later you experience another bug, you can turn them back on.
- **Pro Tip** - there are some predefined things \_\_file\_\_, \_\_func\_\_, \_\_line\_\_, and others that can be helpful to print in debug statements. Try setting **#define DO_DEBUG 1** and **#define DO_DEBUG_INPUT 1** and see what sorts of printouts there are.

### The setup Code - while TRUE - forever loop
[Back to Top](#notes "Back to Top")<br>
```C
  char * input_string; // this variable will store a pointer to a zero-terminated ASCII string

  while (TRUE) { // loop forever
    Serial.println(F(""));

    Serial.println(F("Enter T (Temp), J (Joke), C (ChooseJoke), or A (AllJoke)"));
    input_string = get_one_string(); 
    Serial.print(F("You entered ")); Serial.println(input_string); Serial.println(F(""));
    // make sure first letter of string is capitalized
    if (('a' <= input_string[0]) && ('z' >= input_string[0])) input_string[0] -= 'a' - 'A';
    if ('T' == input_string[0]) {
    } else if ('J' == input_string[0]) {
    } else if ('C' == input_string[0]) {
    } else if ('A' == input_string[0]) {
    } else {
      Serial.print(F("ERROR - ")); Serial.print(input_string); Serial.println(F(" is not a valid choice"));
    } // end if which command
```

We saw the concept of pointers to zero-terminated ASCII strings in the last exercise. This time we will fill in the pointer from a function call to **get_one_string()**.
- Once again we use routines from https://www.arduino.cc/reference/en/language/functions/communication/serial/
- get_one_string() is a surprisingly complicated routine to get a zero-terminated ASCII string from the USB serial port.
  - I thought I was avoiding the complexity of using something like Serial.readStringUntil() and having to explain the difference between a **String** and a **char \***, but maybe I should have gone the other way - or maybe I should re-write get_one_string().
- It only calls two routines to check and get characters: Serial.available() and Serial.read().
  - Serial.available() returns TRUE if there is a character that can be read
  - Serial.read() reads one character

Once we have the address of the string in input_string, we check the first letter of the string to see if it is lower-case between 'a' and 'z'.
- If so we convert to upper-case by subtracting the difference betwee ASCII 'a' and ASCII 'A'.
- Look again at https://www.asciitable.com/ if you want to see how this works.

Then we execute different code blocks depending on what the first letter is.
- Note the **if () {} else if () {} else {}** structure. If the first letter is not T, J, C or A we will complain and try again.

### The setup Code - Temp - for loop inside the parenthesis
[Back to Top](#notes "Back to Top")<br>
```C
  int f, c; // fahrenheit and centigrade
          < ... >
      for (f = first; f < beyond_maximum; f += increment) {
        c = ((f - 32) * 5) / 9;
        Serial.print(F(" degF, degC: ")); Serial.print(f); Serial.print(", "); Serial.println(c);
      } // end Fahrenheit and Centigrade for loop
```

Early in setup there is a statement **int f, c; // fahrenheit and centigrade** followed about 20 lines later by **for (f = first; f < beyond_maximum; f += increment)**. What do these do?

First the **int** statement with a comma: this just means that both variables **f** and **c** are integers; the **int** applies to both of them. There can be tricky applications like what would happen if we said **int f, c = 5;**? Would both **f** and **c** be initialized to 5? This is an introductory class so I won't go into those type of detailed questions here. If you want to initialize both of them, you already know how to do that with two statements and no comma:<br>
```C
  int f = 5; int c = 5;
```

The **for** statement (and the for loop that it generates) is an extremely useful and common happening in C/C++. it is divided into three parts by semicolons. In our case, the three sections are as follows:
- **f = first** - this is the initialization section, where you can initialize any variable before the "for loop" starts
  - If needed you can initialize more than one variable by separating with commas. Example: **f = first, c = 1**
  - You can even define and initialize new variables in the initialization section that only affect the for loop. Example: **int new_variable = 7, f = first, c = 1**
- **f < beyond_maximum** - this is the definition of the **condition** that must be true to execute anything in the for statement
  - **Pro Tip** - it is checked BEFORE THE FIRST EXECUTION of the for loop. If it is false, the loop never executes.
- **f += increment** - this is the action taken AFTER each loop and BEFORE checking the **condition**.
  - Again, multiple actions could be taken. Example: **f += increment, Serial.println("Made f bigger")**

This for loop is seen below:
```C
  for (f = first; f < beyond_maximum; f += increment) {
    c = ((f - 32) * 5) / 9;
    Serial.print(F(" degF, degC: ")); Serial.print(f); Serial.print(", "); Serial.println(c);
  } // end Fahrenheit and Centigrade for loop
```

The for loop behaves **somewhat** like the following:
```C
  int f, c; // fahrenheit and centigrade
  Serial.println("\nFahrenheit and Centigrade computed with integers");
  //
  // for (f = first; f < beyond_maximum; f += increment) { // last loop will be less than beyond_maximum
  //
  // initialization section
  f = first;
  // condition
  if (f < beyond_maximum) {
    // loop
    c = ((f - 32) * 5) / 9;
    Serial.print(" degF, degC: "); Serial.print(f); Serial.print(", "); Serial.println(c);
  }
  // action after LOOP
  f += increment;
  // condition
  if (f < beyond_maximum) {
    // loop
    c = ((f - 32) * 5) / 9;
    Serial.print(" degF, degC: "); Serial.print(f); Serial.print(", "); Serial.println(c);
  }
  // action after LOOP
  f += increment;
  // condition
  if (f < beyond_maximum) {
    // loop
    c = ((f - 32) * 5) / 9;
    Serial.print(" degF, degC: "); Serial.print(f); Serial.print(", "); Serial.println(c);
  }
  // etc. - this doesn't take care of the case where (f < 130) is false, but you see the gist of it
```

As the comment says, this doesn't take care of the case where (f < 130) is false, but you see the gist of it.

### The setup Code - Temp - for loop inside the curly braces
