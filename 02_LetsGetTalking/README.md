# NOTES

## Back to Root of Class
Click this link to back to go back to the root of the **C for Arduino Class**
- https://github.com/Mark-MDO47/CforArduinoClass/tree/master

## Introduction
In this section we will use the USB-serial interface to enter strings to our program and print strings from our program.

We will do some printing from **setup()** and from **loop()** and do some if and loop statements and some expressions.
- The goal is to show a few examples of common ways to do things.
- It is not the goal to show every way to do things or explore every odd case.

For a more thorough exploration of the C/C++ language, I am sure you can find some excellent tutorials and classes on the web. Also, you can look at my list of a few resources I found on the web:
- https://github.com/Mark-MDO47/CforArduinoClass/blob/master/README.md#some-resources-on-the-web

**Table Of Contents**
* [Top](#notes "Top")
* [Back to Root of Class](#back-to-root-of-class "Back to Root of Class")
* [Introduction](#introduction "Introduction")
* [The Arduino USB Serial Interface](#the-arduino-usb-serial-interface "The Arduino USB Serial Interface")
* [The Code](#the-code "The Code")
  * [Comments and Code Statements](#comments-and-code-statements "Comments and Code Statements")
  * [Integers and other Strangers](#integers-and-other-strangers "Integers and other Strangers")
  * [ASCII Characters and Strings](#ascii-characters-and-strings "ASCII Characters and Strings")
  * [Run the setup code](#run-the-setup-code "Run the setup code")
  * [Expressions - Express Yourself](#expressions-\--express-yourself "Expressions - Express Yourself")
  * [Run the loop code](#run-the-loop-code "Run the loop code")
  * [TLDR Float your Boat](#tldr-float-your-boat "TLDR Float your Boat")
  * [TLDR There are many other operators](#tldr-there-are-many-other-operators "TLDR There are many other operators")

## The Arduino USB Serial Interface
[Back to Top](#notes "Back to Top")<br>
Now we will start using the USB serial port for input from the keyboard and output to the screen - a fantastically useful diagnostic tool.

For our USB Serial communications we will use some **Serial.*()** routines such as Serial.begin(), Serial.print(), and Serial.println(). These are documented starting in this area:
- https://www.arduino.cc/reference/en/language/functions/communication/serial/

For instance, the various ways to use Serial.print() are documented here
- https://www.arduino.cc/reference/en/language/functions/communication/serial/print/

When using the USB serial port, the Arduino IDE "Serial Monitor" needs to be started as seen here:

![alt text](https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/Config_USB_SerialMonitor.png "Start Arduino IDE Serial Monitor")

The screen itself looks like this:

![alt text](https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/Config_USB_SerialMonitor_screen.png "Arduino IDE Serial Monitor Screen")

You may need to set the serial monitor to 115,200 baud to match what our **setup()** routine is going to do.

## The Code
[Back to Top](#notes "Back to Top")<br>
This will be a gentle introduction; we won't get to far into details.

### Comments and Code Statements
[Back to Top](#notes "Back to Top")<br>

Load the file ArduinoCode/02_LetsGetTalking/02_LetsGetTalking.ino into the Arduino IDE.
- https://github.com/Mark-MDO47/CforArduinoClass/blob/master/ArduinoCode/02_LetsGetTalking/02_LetsGetTalking.ino

It starts with some comments:<br>
```C
/* 02_LetsGetTalking
 *
 * Mark Olson for his "C for Arduino Class" https://github.com/Mark-MDO47/CforArduinoClass
 * 
 * We are using an Arduino Nano with a USB mini-B connector
 *            V3.0 ATmega328P 5V 16M CH340 Compatible to Arduino Nano V3
 *            32Kbyte Flash (program storage), 2Kbyte SRAM, 1Kbyte EEPROM
 *            http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf
 *            http://www.pighixxx.com/test/pinouts/boards/nano.pdf
 *
 * This is code for https://github.com/Mark-MDO47/CforArduinoClass/02_LetsGetTalking
 * 
 */
```

Anything between **/*** and ***/** is a comment, whether it spans multiple lines or is in the middle of a code statement.<br>
This means the entire code snippet above is a comment and is ignored by the compiler.

Also anything after **//** is a comment, as seen below. Note also that blank lines are ignored.<br>
```C

// loop_count is a "variable" that can store one "int" (integer).
// Because it is defined up front and not inside {} brackets, it can be "seen" by everything below
int loop_count = 0;

```

We also see this:<br>
```C
#include "string.h" // includes the standard C definitions found in string.h
```
This tells the compiler to find the standard C file string.h and compile as if it copied those lines in here as replacement for the #include statement. We will use the **strlen()** function that returns the length of a character string (zero-terminated ASCII string; we will discuss later) so we need to do this #include.

Note that the #include statement does NOT end with a semicolon (**;**). That is in general true of the other keywords starting with **#** that we will see later. That allows these **#** statements to operate on **;** as just another part of the string.

**TLDR** it is also possible to do **#include <string.h>**. The difference as far as we are concerned is not a big one; it just narrows down the range of places that the C compiler would look for the file string.h. Anywhere in this class or in the Arduino Class, using the **"** form is always OK.

All **code statements** that the compiler accepts DO end with a semicolon (**;**). There can be more than one code statement on a line. For example, we could write:<br>
```C
// we can do this either way; this:
int loop_count = 0;
int my_state = 1;
// or this:
int loop_count = 0; int my_state = 1;
// one or the other may be more readable but the compiler doesn't care
```

### Integers and other Strangers
[Back to Top](#notes "Back to Top")<br>

So what does that statement **int loop_count = 0;** mean?

It creates an **int** **variable** named **loop_count**, which means **memory** location in the Arduino RAM (Random Access Memory) in which an integer value (**int**) is stored; the **= 0;** part means that it is initially set to zero. In general, if you do not initialize your variables they could have any value, even a ridiculous value.

The compiler will assign some memory at a particular address. We usually don't care what the address is; when we say **loop_count** the compiler will use the memory address that is assigned for that purpose.

There are different types and sizes of integers.
- A signed integer, such as we just created for loop_count, can be zero, positive, or negative - for example, 0 or +1 or -1.
- An unsigned integer can only be zero or positive.
  - If a negative number is assigned to an unsigned integer, it will probably give results that were not wanted. However, there can be reasons to do this if you know exactly what you are doing.

**NOTE: I will discuss the different sizes available for integers because the Arduino Nano has very little storage available for variables.**

A common practice in C and C++ is to specify the size when defining integers. The size of **int** can vary depending on what computer processor the code is running. To get consistent results it is best to specify a size that handles anything that will be stored in it. However, the Arduino Nano is very constrained for its RAM memory, so we want to make each variable big enough but not too big.

Because the size of **int** (and its cousins such as **unsigned int**, **long int**, and **unsigned long int**) is not the same for every processor, there is a method to specify the size in units of how many **binary bits** the variable will have. We will discuss binary and other numbering systems later. For now just remember that the more bits there are in an integer, the bigger the numbers that can be stored.

The following type definitions show the pattern of a common methodology for doing this. Because almost all modern processors including Arduinos are **2's complement** (don't worry about that for now), I show the ranges in terms of 2's complement numbers.
| Type Definition | Signed/Unsigned | # of bits | Range |
| --- | --- | --- | --- |
| int8_t | signed | 8 | -128 through +127 |
| uint8_t | unsigned | 8 | 0 through 255 |
| int16_t | signed | 16 | -32,768 through +32,767 |
| uint16_t | unsigned | 16 | 0 through +65,535 |
| int32_t | signed | 32 | -2,147,483,648 through +2,147,483,647 |
| uint32_t | unsigned | 32 | 0 through +4,294,967,295 |

### ASCII Characters and Strings
[Back to Top](#notes "Back to Top")<br>

What if you want to print "Hello World!" to the terminal? Computers only understand bits and bytes; how do we specify text strings?
- Printing "Hello World!" is a common exercise ever since the first publication of **The C Programming Language** by Kernighan and Ritchie.

One of the oldest and still commonly used methods of specifying strings is in **zero-terminated** **ASCII**.
- ASCII stands for American Standard Code for Information Interchange.
- https://www.asciitable.com/ shows a table with the ASCII code for each character. Note that there are **printable**, **non-printable**, and **extended** character codes in ASCII. Here are some examples:
- A printable code is "A" represented by the number 65 (decimal).
- A non-printable code is "BEL" represented by the number 7 (decimal). In some systems, displaying "BEL" will cause some sort of sound to come out of the system.
- An extended code is the character "PI" represented by the number 227 (decimal). Extended codes are often as shown but some systems may not display them as expected.

NOTE: There are other systems such as **UniCode** which will not be used in our Arduino Class.

The type of a variable that is an ASCII code is **char**. On the Arduino and on most systems **char** the same as a **uint8_t**.

That shows how to represent many familiar characters; how do we represent "Hello World!"? Since we are using zero-terminated ASCII strings, each ASCII character will be placed one after another in consecutive bytes in memory. The end of the string is when one of the bytes contains the value zero, which is the ASCII code "NUL".

**NOTE: I will go into detail on zero terminated string arrays since (1) strings are common, (2) arrays are common, (3) pointers are very useful.**

We could define this string as follows:<br>
```C
// Two different ways to have a zero-terminated ASCII string that says "Hello World!"
// str_num is an array of 13 "char", which happens to end in zero. Many routines exist
//     that can do things with zero-terminated ASCII strings.
// The "char *" in front of str_ptr indicates that str_ptr is a "pointer" and contains the address
//     to zero or more consecutive "char". The "Hello World!" creates a zero-terminated ASCII string
//     and stores the address into str_ptr.
// str_num and str_ptr can be used in the same way in the code.
//     To get the first character, refer to str_num[0] or str_ptr[0].
//     To print a line that says "Hello World!", either use:
//        Serial.println(str_num);
//        Serial.println(str_ptr);
//
char  str_num[13] = { 72,  101,  108,  108,  111,  32,  87,  111,  114,  108,  100,  33,  0 };
char *str_ptr = "Hello World!";
```
The "char str_num[13] = { ... }" notation defines an **array** of type **char** of length **13** and then initializes them with the numbers shown.
The 'char *str_ptr = "Hello World!"' creates a zero-terminated **array** of type **char** somewhere and stores the address in str_ptr.
Both str_num and str_ptr can **almost** always be used in code statements with exactly the same syntax.

Below is how the array str_num is initialized:<br>
| type | str_num[0] | str_num[1] | str_num[2] | str_num[3] | str_num[4] | str_num[5] | str_num[6] | str_num[7] | str_num[8] | str_num[9] | str_num[10] | str_num[11] | str_num[12] |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| ASCII | 'H' | 'e' | 'l' | 'l' | 'o' | ' ' | 'W' | 'o' | 'r' | 'l' | 'd' | '!' | NUL |
| decimal | 72 | 101 | 108 | 108 | 111 | 32 | 87 | 111 | 114 | 108 | 100 | 33 | 0 |

Note these things about the C/C++ language and our str_num/str_ptr definition:
- putting a character inside of single quotes produces the ASCII character value
  - char tmp = 'H'; // 'H' has value decimal 72
- putting zero or more characters inside of double quotes produces the address of a zero-terminated ASCII string
  - Serial.println("CforArduinoClass init...");
- an array is indexed with a number inside square brackets **[]** starting at zero.
  - str_num[1] contains 'e' which has the value 101
- our ASCII string str_num contains 13 elements, the last of which is the zero for zero-termination
  - str_num[12] contains ASCII NUL which has the value 0
- the **str_num** example is just to make the point clear; nobody initializes strings as arrays of numbers

Now let's look at the code inside the **setup()** block. Remember, **setup()** will be called first and only once. After that, **loop()** will be called over and over.<br>
```C
// the setup function runs once when you press reset or power the board
void setup() {

  // this serial communication is for general debug; set the USB serial port to 115,200 baud
  Serial.begin(115200);

  while (!Serial) {
    ; // note that ";" is a null code statement. Wait for serial port to connect.
  }
  
  Serial.println(""); // print a blank line in case there is some junk from power-on
  Serial.println("CforArduinoClass init...");

  Serial.println("");
  Serial.print("str_num: ");
  Serial.println(str_num);
  Serial.print("str_ptr: "); Serial.println(str_ptr);
  Serial.print("strlen(str_num): "); Serial.println(strlen(str_num));
  Serial.print("strlen(str_ptr): "); Serial.println(strlen(str_ptr));
  Serial.print("strlen(\"Hello World!\"): "); Serial.println(strlen("Hello World!"));
  Serial.print("sizeof(str_num): "); Serial.println(sizeof(str_num));
  Serial.print("sizeof(str_ptr): "); Serial.println(sizeof(str_ptr));
  Serial.print("sizeof(\"Hello World!\"): "); Serial.println(sizeof("Hello World!"));

  Serial.println("");
} // end setup()
```

For now, just think of the **Serial.begin(115200);** and the block inside **while (!Serial)** as a way to initialize the **Serial** object. We can discuss the details of how this works at a later time; for now, this is just how we get it working.

The next thing we see is **Serial.println("");**.
- The "" is a double-quoted string of zero characters, so it creates an address that points to a zero-terminated ASCII string. Since there are no characters inside the "", the zero-terminated ASCII string starts with the ASCII NUL (zero) character and then ends; it is of length one.
- Serial.println("") takes this pointer to a string with just the NUL character and prints or displays it, stopping before printing the NUL. Serial.print**ln** then creates a new line. If we used Serial.print("") instead of Serial.print**ln**(""), it would not create a new line.
- You can think of it as if the Arduino program was typing in a text editor:
  - Serial.print("aa"); Serial.print("bb"); Serial.println("cc"); - types aabbcc then (because the last one is print**ln**) presses enter
- The ; at the end terminates the code statement; the // means to ignore the rest of the line.
- The result is that we print/display a blank line.

The rest of the Serial.print and Serial.println statements follow the above pattern. Notice that we can use one (or more) lines for a code statement or we can put more than one code statement on one line. The compiler does not care.

Here are a few other capabilities we use in the **setup()** code:
- strlen() (see #include "string.h" above) counts the number of ASCII bytes NOT including the zero termination. This works the same in all three usages.
- sizeof() counts the number of bytes in the actual thing within the parentheses **()**:
  - str_num is an array of 13 bytes so sizeof(str_num) returns 13
  - str_ptr is a pointer to an array of 13 bytes, but the pointer is two bytes so it returns 2
  - "Hello World!" (at least in this C compiler's mind) is an array of 13 bytes

### Run the setup code
[Back to Top](#notes "Back to Top")<br>
Below shows the results on the Serial Monitor from running the **setup()** code:<br>
![alt text](https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/02_SerMon_setup_only.png "02 Lets get talking Serial Monitor from running setup code")

### Expressions - Express Yourself
[Back to Top](#notes "Back to Top")<br>

In C/C++, an expression is something that returns a value. This is not a complete list but here are some example expressions, using i and j as integer variables:
* i = 17 * 17; // 17 * 17 is an expression for 17 times 17 = 289
* i = squared(17); // squared my be a function that returns the value of the parameter squared
* i = i+1; // if i is 289, this will store 289+1 = 290 into i
* i += 1; // this is a shorthand way of doing the above
* i++; ++i; // more ways to add one to i; these are subtly different from each other
* i = i / 17; // this stores the truncated integer value into i - If i is 293 then 17 gets stored into i and the remainder of 4 is discarded
* i = 293 % 17; // the remainder or modulo - this time the remainder of 4 is stored in i and the 17 gets discarded
* j = (i /= 4) * 3; // this is complicated. Don't worry about this one too much; it is somewhat rare
  * (i /= 4) means the left hand side divided by the right hand side, so 17/4 is 4.25 but truncated to 4 and stored into i
  * then the 4 is multiplied by 3 to get 12 and stored into j

Terms like +, -, /, *, etc. are called **operators**.

### Run the loop code
[Back to Top](#notes "Back to Top")<br>

Here is the loop code:
```C
// the loop function runs over and over again forever
void loop() {
  loop_count += 1;    // instead of loop_count = loop_count + 1

  if (1 == loop_count) { // first time loop() is called
    Serial.print("1 && 1: "); Serial.println(1 && 1);
    Serial.print("1 && 2: "); Serial.println(1 && 2);
    Serial.print("-1 && 999: "); Serial.println(-1 && 999);
    Serial.print("-1 && 0: "); Serial.println(-1 && 0);
    Serial.print("0 || 2: "); Serial.println(0 || 2);
    Serial.print("!(0 || 2): "); Serial.println(!(0 || 2));
    Serial.println("");
  } // end if (loop_count == 1)

  if (loop_count <= 10) { // first 10 times loop() is called
    // Serial.print() does not go to a new line; Serial.println() does
    Serial.print(" loop_count: "); Serial.println(loop_count);
  } // end if (loop_count...)

  delay(1000);                       // wait for a second
} // end loop()
```

The first **if** statement tests the expression inside **()** and executes the code block inside the **{}** if the expression is TRUE (1).
- The first time the code enters loop(), loop_count is zero
  - loop_count += 1; sets loop_count to 1
  - if (1 == loop_count) is TRUE the first time so we execute the code block inside the **{}**
- The second time the code enters loop(), loop_count is one
  - loop_count += 1; sets loop_count to 2
  - if (1 == loop_count) is FALSE the second and subsequent times so we skip the code block inside the **{}**
- the third and subsequent times the code enters the loop
  - if (1 == loop_count) is FALSE the second and subsequent times so we skip the code block inside the **{}**
    - actually it is FALSE for a long time but eventually loop_count will overflow
- The result: we only print the lines from the code block inside the **{}** one time on the first time in loop()

The second **if** statement tests the expression (loop_count <= 10) and executes the code block inside the **{}** if the expression is TRUE (1).
- This is TRUE the first 10 times loop() is called
- After that it is FALSE until loop_count overflows (a long time)

Finally we reach the delay(1000); code statement. This waits for about 1000 milliseconds each time loop() is called because it is not inside any control block such as **if** or **while**, etc.
- delay(1000); waits for at least 999 (1000-1) milliseconds and then continues. This delay of 999+ doesn't bother us; we are not doing precise timing. This could be troublesome if we were trying to do a small delay such as 1 millisecond.

Below shows the results on the Serial Monitor from running the entire Arduino program:<br>
![alt text](https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/02_SerMon_run.png "02 Lets get talking Serial Monitor from running entire Arduino program")

### TLDR Float your Boat
[Back to Top](#notes "Back to Top")<br>

Floating point numbers allow storage and use of numbers that are not integers, such as the familiar 3.141592. Just as **int** is one **type** used for integer storage, **float** is one **type** of floating point storage. As usual, floats come in different sizes: **float**, **double**, **long double**.

Be aware that floating point numbers are stored in binary format and there is no finite-length binary fraction that can exactly represent 0.1 - nor many other floating point number fractions expressed in decimal notation. Thus if you add 0.1 to itself often enough you will start to notice that the result is not exactly what you would expect if 0.1 were represented exactly. However, the result will be correct to a certain number of significant digits, within certain complicated mathematical limits we won't get into here.
- With C/C++ integer numbers we always need to watch out for generating a number that is too big to fit in the size and type of integer we have.
- With C/C++ floating point numbers there are maximum and minimums for what can be expressed, plus we always have to watch out for the accumulation of small errors.
- Dividing by zero in C/C++ is always a bad idea.

### TLDR There are many other operators 

There are a few operators used when doing binary or boolean operations. We will talk about these later in the Arduino class when we briefly cover those topics, but here are some of the common ones: **<<**, **>>**, **&**, **|**, **^**, and **~** for bitwise left shift, bitwise right shift, bitwise AND, bitwise OR, bitwise XOR, and bitwise NOT (one's complement).

There are some comparison operators **==**, **<**, **<=**, **>**, **>=**, and **!=**, for equal to, less than, less than or equal to, greater than, greater than or equal to, and not equal to.

Logical operators return a 1 (often thought of as TRUE) or 0 (often thought of as FALSE). The comparison operators are logical operators. In addition there is **&&**, **||**, and **!** for logical AND, logical OR, and logical NOT.
* Note that during calculations, anything that is not zero is treated as 1. For instance
  * 1 && 1 is TRUE
  * 1 && 2 is TRUE
  * -1 && 999 is TRUE
  * 0 || 2 is TRUE
  * !(0 || 2) is FALSE
