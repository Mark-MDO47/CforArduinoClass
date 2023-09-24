# NOTES

## Back to Root of Class
Click this link to back to go back to the root of the **C for Arduino Class**
- https://github.com/Mark-MDO47/CforArduinoClass/tree/master

In this section we will use the USB-serial interface to enter strings to our program and print strings from our program.

**Table of Contents**
* [Top](#notes "Top")
* [The USB Serial Interface](#the-usb-serial-interface "The USB Serial Interface")

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
