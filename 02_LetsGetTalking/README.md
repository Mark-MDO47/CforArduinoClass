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
  * [Integers](#integers "Integers")

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

Anything between **/*** and ***/** is a comment, whether it spans multiple lines or is in the middle of a code statement.

Also anything after **//** is a comment, as seen below. Note also that blank lines are ignored.<br>
```C

// loop_count is a "variable" that can store "int" (integers)
//   because it is defined up front and not inside {} brackets, it can be "seen" by everything below
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


### Integers
[Back to Top](#notes "Back to Top")<br>
