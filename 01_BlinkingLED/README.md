# NOTES

## Back to Root of Class
Click this link to back to go back to the root of the **C for Arduino Class**
- https://github.com/Mark-MDO47/CforArduinoClass/tree/master

In this section we will connect to the Arduino and run a standard sample program to make sure we are ready to do some C-language programming.

**Table of Contents**
* [Top](#notes "Top")
* [Introducing the Arduino Nano](#introducing-the-arduino-nano "Introducing the Arduino Nano")
* [Connect the Arduino Nano to the USB cable](#connect-the-arduino-nano-to-the-usb-cable "Connect the Arduino Nano to the USB cable")
* [Run the example Blink program](#run-the-example-blink-program "Run the example Blink program")
* [Now It Runs Whenever you Turn On Power](#now-it-runs-whenever-you-turn-on-power "Now It Runs Whenever you Turn On Power")

## Introducing the Arduino Nano
[Back to Top](#notes "Back to Top")<br>
![alt text](https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/Arduino-Nano-Pinout_from_circuitstoday.com.png "CircuitsToday.com picture of Arduino Nano")

The Student Kit includes an Arduino Nano clone. The above image is from CircuitsToday.com.

The Arduino is one of a class of open-source hardware single-module computers designed by an organization named Arduino. They build the genuine Arduino boards and make the designs avaliable. There are many companies either making clones (such as the ones in our Student Kit) or extending the family (such as the ESP32, currently my favorite Arduino variant).
- https://www.arduino.cc/en/about
- https://www.arduino.cc/en/hardware

These Arduino Nanos have 32Kbyte of FLASH memory (program storage), 2Kbyte of SRAM, and 1Kbyte of EEPROM.
- FLASH memory (no acronym) was an offshoot of EEPROM. For the Arduino Nano it is erasable and writeable in blocks of many bytes. FLASH is found in thumb drives, SD cards, and many other applications.
- EEPROM (Electrically Eraseable Programmable Read-Only Memory) is, for the Arduino Nano, erasable and writeable in blocks of one byte.
- SRAM (Static Random Access Memory) is, for the Arduino Nano, readable and writeable in blocks of one byte. There is typically no published limit on the number of times it can be read or written. It is somewhat faster to read than the FLASH or EEPROM and much much faster to write.

## Connect the Arduino Nano to the USB cable
[Back to Top](#notes "Back to Top")<br>
The Arduino Nano uses a USB Mini-B female and thus needs a cord from your laptop with a USB Mini-B Male connector. If your laptop has a USB A connection then I have cords you can use; otherwise please provide your own method to connect to either Mini-B directly or to bridge the gap to the USB A connector on the cord I can provide (for instance, if you only have USB C connectors). This USB connection provides both a serial port (for uploading and communication) and power/ground. The link below shows what many USB cables male and female connectors and sockets look like.
- https://en.wikipedia.org/wiki/USB

To minimize wear and tear on the Arduino Nano, after connecting the Arduino to the USB cable, one can disconnect at the PC or laptop side instead of the Arduino side.

To connect your computer to the Arduino Nano
- Connect the Arduino Nano to a USB port on your computer.
- Start the Arduino IDE and in the menu **Tools** -> **Board: ...** select **Arduino Nano**.

The Student Kit boards are built from relatively old Arduino Nano designs.
- In the Arduino IDE menu **Tools** -> **Processor** -> **ATmega328P** select **Old Bootloader**.
- **Programmer** should then automatically be selected as **AVRISP mkll**.

![alt text](https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/ConfigUSB.png "Configure USB port for old Arduino Nano")

## View an Empty Sketch (Arduino program)
[Back to Top](#notes "Back to Top")<br>
The Arduino IDE uses a variant of the C++ language. You can program in a C++ style or a C style. The code that we will use in this course will be quite straighforward and should be understandable if you know any computer language. One thing to note about C/C++: array indices start with zero.

An Arduino program (called a "sketch" in Arduino-speak) is typically stored with extension ".ino". If you save your program as fred.ino, you will find that it is saved in a directory named fred.

When opening the Arduino IDE you will initially see the empty sketch (program) as shown below. This is the standard architecture for Arduino code. It is possible to extend this to use interrupts, go to low power modes, and other special-purpose things. For our class we will just use the standard architecture as seen below.

```C
void setup() {
 // put your setup code here, to run once:
}
void loop() {
 // put your main code here, to run repeatedly:
}
```

## Run the example Blink program
[Back to Top](#notes "Back to Top")<br>
In the Arduino IDE, choose menu **File** -> **Examples** -> **01.Basics** -> **Blink**. This will bring up the starting point for our Blink exercise.

![alt text](https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/IDE_LoadBlink.png "Arduino IDE loading Blink example program")

If for some reason you do not have access to that you can find a copy (from 2023-08) in this area under _Examples_ArduinoIDE/Blink:
- https://github.com/Mark-MDO47/CforArduinoClass/tree/master/ArduinoCode

In the **setup()** function you will find a "pinMode" call; this sets the internal "pin" to OUTPUT mode so we can turn the internal LED on and off.
- LED_BUILTIN is a symbol for the "pin" number that controls the built-in LED on the Arduino. This LED_BUILTIN symbol will automatically be correct when compiling for any Arduino.

The **setup()** function is called only once, before ever calling the **loop()** function.

In the **loop()** function for the example Blink program you will find that it delays 1000 milliseconds, turns the LED **ON**, delays 1000 milliseconds, and turns the LED **OFF**.

Because the **loop()** function is called over and over, this will continue until you stop it by reprogramming, resetting, or powering off the Arduino Nano.

With the Arduino connected to the USB port on your computer, use the button circled in red in the image below to compile, load, and run the Blink example program. The on-board LED should blink.

![alt text](https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/IDE_CompileAndRun.png "Arduino IDE compile-load-run button")

**CONGRATULATIONS!** You have executed your first Arduino program!

## Now It Runs Whenever you Turn On Power
[Back to Top](#notes "Back to Top")<br>
Now that you have loaded a program into the "Program Memory" of the Arduino, it stays there when you power-off or disconnect the Arduino. If you unplug the USB cord, let the Arduino power off completely, and then plug the cord in again you will see that it runs the Blink program again after a short bootup.

This is how you can include an Arduino into your projects. You don't have to connect to a computer and program it each time; it will remember the last program you loaded because the program is stored in FLASH memory which persists across power-cycle.

You also can but don't have to power the Arduino through the USB port. Another way to power the Arduino is to use the Arduino pin marked VIN. If you provide 5 volts on VIN and connect ground to one of the GND pins, the last program will run again. Most Arduinos are able to run with a small range of voltages near 5 volts fed into the VIN pin; always be sure to check the documentation for the correct voltage range before doing this.

### TLDR the Arduino delay function
[Back to Top](#notes "Back to Top")<br>
As an aside, the Arduino delay(n) function does NOT behave similarly to all the sleep(n) functions I have seen in other languages.
- the sleep(n) functions I have seen will sleep **at least as long** as the parameter **n** indicates
- the Arduino delay(n) function will return after **at least as long** as **n-1** milliseconds
- https://forum.arduino.cc/t/problem-with-delay-and-millis/686674

Curiously, this behaviour is not mentioned in the Arduino documentation for the delay() function.
- https://www.arduino.cc/reference/en/language/functions/time/delay/

This doesn't matter to us very much here. If we sleep 999 milliseconds or 1000 milliseconds or even 1001 milliseconds it doesn't cause a traffic accident or other bad effects.
