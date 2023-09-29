# C for Arduino Class
Enough C/C++ to start the Arduino Class

For an Arduino class 2023; FabLab will be first<br>
Author: Mark Olson<br>

**Table Of Contents**
* [Top](#c-for-arduino-class "Top")
* [Learning C and Cplusplus](#learning-c-and-cplusplus "Learning C and Cplusplus")
  * [Start C for Arduino Class](#start-c-for-arduino-class "Start C for Arduino Class")
  * [Some resources on the Web](#some-resources-on-the-web "Some resources on the Web")

## Learning C and Cplusplus
[Top](#c-for-arduino-class "Top")<br>
One thing I learned when teaching the first Arduino Class is that things will move much faster if everyone has some basic experience with a text-based programming language.

The Arduino IDE uses C and C++ languages for general programming.
- If you have experience in any text-based general programming language - Python, Java, or other programming languages - you will probably be able to catch on to the parts of C and C++ used in this class quickly.
- If you have never programmed in a text-based general programming language before, I suggest you learn the basics of C before attending the [Arduino Class](#https://github.com/Mark-MDO47/ArduinoClass "Arduino Class"). You can easily pick up on the few parts of C++ used in this class if you have some knowledge of C (or even Python or Java or other languages). 
- This **C for Arduino Class** is intended to provide enough experience with the C and C++ programming languages in the Arduino environment to bring a non-programmer to the stage that they can start the **Arduino Class** and then learn the enough to enjoy that class on the way.
- https://github.com/Mark-MDO47/ArduinoClass/blob/master/README.md

One factor to consider: Arduino does not implement the standard "printing" etc. functions - not for C (printf and scanf) and not for C++ (IO Streams). Arduino uses relatively simple "Serial" methods such as Serial.begin, Serial.print and Serial.println for output; Serial.available, Serial.read and Serial.readln for input.
- If you want to get started by doing some fun Arduino projects from this class you can skim (or temporarily skip) the standard C and C++ methods, knowing that they are not used for these projects. You can return to the standard methods later.
- If you want to learn the full languages to further your career, you will probably want to learn the standard C and C++ methods at the same time as learning enough C and C++ for this class. There is a lot to learn about C and C++!

For this class we will take the more slimmed down approach: we will learn in the Arduino environment and leave the standard C and C++ methods out. So here are the paths. You can do them in either order or just do one or the other.
* [Start C for Arduino Class](#start-c-for-arduino-class "Start C for Arduino Class")
* [Some resources on the Web](#some-resources-on-the-web "Some resources on the Web")

### Start C for Arduino Class
[Top](#c-for-arduino-class "Top")<br>
I will bring some Arduino Nanos for the class, along with a few USB cables to connect them to laptops or PCs or Macs. Please bring your personal or work laptop to the class if possible. If you have a USB cable that can connect your laptop to a USB Mini-B, please bring that. You will find some pointers to USB Mini-B in the 00_InstallArduinoIDE section below.

| Lesson | Description | Image |
| --- | --- | --- |
| [00_InstallArduinoIDE](https://github.com/Mark-MDO47/CforArduinoClass/tree/master/00_InstallArduinoIDE "00_InstallArduinoIDE") | Install the Arduino IDE<br>Brief discussion of the venerable C/C++ language<br>Quick introduction to schematics and Fritzing<br>**If possible, please read this lesson and install the Arduino IDE before class!** | <img src="https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/IDE_Blink.png" width="142" alt="Image of Arduino IDE"> |
| [01_BlinkingLED](https://github.com/Mark-MDO47/CforArduinoClass/tree/master/01_BlinkingLED "01_BlinkingLED") | Blink some simple LEDs<br>YouTube: https://youtu.be/c5UH3J40uWE<br>Discusses ways to power Arduino and program persistence through power-cycling.<br><br>External Image of Arduino Nano from CircuitsToday.com | <img src="https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/Arduino-Nano-Pinout_from_circuitstoday.com.png" width="142" alt="CircuitsToday.com picture of Arduino Nano"><br><img src="https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/01_BlinkingLED_part_A_setup.png" width="150" alt="Image of Blinking LED part B"> |

### Some resources on the Web
[Top](#c-for-arduino-class "Top")<br>
Here are some web resources for learning the C language:
- https://www.java67.com/2020/07/5-free-courses-to-learn-c-programming.html
- https://medium.com/javarevisited/10-best-c-programming-courses-for-beginners-2c2c1f6bcb12

Here are a few of the highly rated **free** C-language ones from the above lists. I have not taken these classes myself but at a quick glance they seem OK.
- https://www.udemy.com/course/quickstart-guide-c-programming/
- https://www.udemy.com/course/c-programming-2019-master-the-basics/
- https://www.youtube.com/watch?v=KJgsSFOSQv0   C Programming Tutorial for Beginners (about 4 hours)
- https://www.educative.io/courses/learn-c-from-scratch

There are many books on learning the C language. I have no experience with most of them.<br>
The following book is how I learned the C language, back when dinosaurs ruled the earth. I really like its approach of building up knowledge in blocks such that you can use them immediately and they all fit together.<br>
- **The C Programming Language** by Brian W. Kernighan and Dennis M. Ritchie

If you search you might find the "mass-market paperback" at around $20 or maybe a used copy for even less.<br>
If you are going to get a copy, I suggest you try to get the latest edition. Since you will be investing the time, you might as well be close to up-to-date (2nd edition is Copyright 2012).

As an aside: some of the projects will use **binary** arithmetic and **Boolean** logic to implement simple data compression. We will do a quick discussion on how this code works when the time comes. This is another one of those topics that is important but could be skimmed if you just want to enjoy the project and study it later.

There is a quick discussion of binary and other numbering systems in the resources page:
- https://github.com/Mark-MDO47/ArduinoClass/tree/master/99_Resources#tldr-decimal-and-binary-and-hexadecimal

Binary and Boolean are discussed more fully in Wikipedia:
- https://en.wikipedia.org/wiki/Binary_number
- https://en.wikipedia.org/wiki/Boolean_algebra
