# NOTES

## Back to Root of Class
Click this link to back to go back to the root of the **C for Arduino Class**
- https://github.com/Mark-MDO47/CforArduinoClass/tree/master

In this section we will use the USB-serial interface to enter strings to our program and print strings from our program.

**Table of Contents**
* [Top](#notes "Top")
* [The USB Serial Interface](#the-usb-serial-interface "The USB Serial Interface")
* [The Code](#the-code "The Code")
  * [Comments and Code Statements](#comments-and-code-statements "Comments and Code Statements")
  * [Integers and other Strangers](#integers-and-other-strangers "Integers and other Strangers")

## The USB Serial Interface
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

All code statements that the compiler accepts end with **;** (semicolon). There can be more than one code statement on a line. For example, we could write:<br>
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

One of the oldest and still commonly used methods of specifying strings is in **zero-terminated** **ASCII**.
- ASCII stands for American Standard Code for Information Interchange.
- https://www.asciitable.com/ shows a table with the ASCII code for each character. Note that there are **printable**, **non-printable**, and **extended** character codes in ASCII. Here are some examples:
- A printable code is "A" represented by the number 65 (decimal).
- A non-printable code is "BEL" represented by the number 7 (decimal). In some systems, displaying "BEL" will cause some sort of sound to come out of the system.
- An extended code is the character "PI" represented by the number 227 (decimal). Extended codes are often as shown but some systems may not display them as expected.

There are other systems such as **UniCode** which will not be used in our Arduino Class.

The type of a variable that is an ASCII code is **char**. On the Arduino and on most systems **char** the same as a **uint8_t**.

That is how to represent many familiar characters; how do we represent "Hello World!"? Since we are using zero-terminated ASCII strings, each ASCII character will be placed one after another in consecutive bytes in memory. The end of the string is when one of the bytes contains the value zero, which is the ASCII code "NUL".

We could define this as follows:<br>
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
Both str_num and str_ptr can be used in code statements with exactly the same syntax.

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
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.println(""); // print a blank line in case there is some junk from power-on
  Serial.println("CforArduinoClass init...");

  Serial.println("");
  Serial.print("str_num: ");
  Serial.println(str_num);
  Serial.print("str_ptr: ");
  Serial.println(str_ptr);
  Serial.println("");
} // end setup()
```
