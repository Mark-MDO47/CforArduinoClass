# C for Arduino Class
This is the [C for Arduino Class](https://github.com/Mark-MDO47/CforArduinoClass/tree/master "C for Arduino Class") 2023; FabLab will be first<br>
- Enough C/C++ to start the [Arduino Class](https://github.com/Mark-MDO47/ArduinoClass "Arduino Class")

Author: Mark Olson

**Table Of Contents**
* [Top](#c-for-arduino-class "Top")
* [Why a C for Arduino Class](#why-a-c-for-arduino-class "Why a C for Arduino Class")
* [About this C for Arduino Class](#about-this-c-for-arduino-class "About this C for Arduino Class")
* [C for Arduino Class Lesson Plan](#c-for-arduino-class-lesson-plan "C for Arduino Class Lesson Plan")
* [Some resources on the Web](#some-resources-on-the-web "Some resources on the Web")

## Why a C for Arduino Class
[Top](#c-for-arduino-class "Top")<br>
One thing I learned when teaching the first [Arduino Class](https://github.com/Mark-MDO47/ArduinoClass "Arduino Class") is that things will move much faster if everyone has some basic experience with a text-based programming language.

The Arduino IDE uses C and C++ languages for general programming.
- If you have experience in any text-based general programming language - Python, Java, or other programming languages - you will probably be able to catch on to the parts of C and C++ used in the [Arduino Class](https://github.com/Mark-MDO47/ArduinoClass "Arduino Class") quickly.
- If you have never programmed in a text-based general programming language before, I suggest you learn the basics of C before attending the [Arduino Class](https://github.com/Mark-MDO47/ArduinoClass "Arduino Class").
  - This [C for Arduino Class](https://github.com/Mark-MDO47/CforArduinoClass/tree/master "C for Arduino Class") is intended to provide enough experience with the C and C++ programming languages in the Arduino environment to bring a non-programmer to the stage that they can start the [Arduino Class](https://github.com/Mark-MDO47/ArduinoClass "Arduino Class") and enjoy that class on the way.
  - There are also [Some resources on the Web](#some-resources-on-the-web "Some resources on the Web") if you want to learn C/C++ on you own or want to supplement this introductory [C for Arduino Class](https://github.com/Mark-MDO47/CforArduinoClass/tree/master "C for Arduino Class").

## About this C for Arduino Class

In this class there will be sections marked as **Syntax**, as **Pro Tip**, and as **TLDR**.
- **Syntax** indicates a section that discusses how to write code statements to achieve a particular purpose. These are sections that you might want to look at again when you are doing a project and want to remember how to write a section of code that does that.
- **Pro Tip** indicates a detail that is a good technique or a common source of error - or sometimes an obscure source of error. Learning these may save some debugging time later.
- **TLDR** indicates a section that is true, interesting, useful eventually but not necessary at the moment. In Internet-ese this stands for Too Long Didn't Read. If all the discussion prior to that makes sense and you want to understand it in a deeper way, read these. Just remember - even after reading these there is always more!

One factor to consider: Arduino does not implement the standard "printing" etc. functions - not for C (printf and scanf) and not for C++ (IO Streams). Arduino uses relatively simple "Serial" methods such as Serial.begin, Serial.print and Serial.println for output; Serial.available and Serial.read and Serial.read variations for input. See the [Serial Main Page](https://www.arduino.cc/reference/en/language/functions/communication/serial/ "Link to Serial Main Page") for more details.
- If you want to get started by doing some fun Arduino projects from this class you can skim (or temporarily skip) the standard C and C++ methods, knowing that they are not used for these projects. You can return to the standard methods later.
- If you want to learn the full languages to further your career, you will probably want to learn the standard C and C++ methods at the same time as learning enough C and C++ for this class. There is a lot to learn about C and C++!

For this class we will take the more slimmed down approach: we will learn in the Arduino environment and leave the standard C and C++ methods out. So here are the paths. You can do them in either order or just do one or the other.
* [C for Arduino Class Lesson Plan](#c-for-arduino-class-lesson-plan "C for Arduino Class Lesson Plan")
* [Some resources on the Web](#some-resources-on-the-web "Some resources on the Web")

## C for Arduino Class Lesson Plan
[Top](#c-for-arduino-class "Top")<br>
I will bring some Arduino Nanos for the class, along with a few USB cables to connect them to laptops or PCs or Macs. Please bring your personal or work laptop to the class if possible. If you have a USB cable that can connect your laptop to a USB Mini-B, please bring that. You will find some pointers to USB Mini-B in the 00_InstallArduinoIDE section below.

| Lesson | Description | Image |
| --- | --- | --- |
| [00_InstallArduinoIDE](https://github.com/Mark-MDO47/CforArduinoClass/tree/master/00_InstallArduinoIDE "00_InstallArduinoIDE") | Install the Arduino IDE<br>Brief discussion of the venerable C/C++ language<br>Quick introduction to schematics and Fritzing<br>**If possible, please read this lesson and install the Arduino IDE before class!** | <img src="https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/IDE_Blink.png" width="142" alt="Image of Arduino IDE"> |
| [01_BlinkingLED](https://github.com/Mark-MDO47/CforArduinoClass/tree/master/01_BlinkingLED "01_BlinkingLED") | Blink some simple LEDs<br>YouTube: https://youtu.be/c5UH3J40uWE<br>Discusses ways to power Arduino and program persistence through power-cycling.<br><br>External Image of Arduino Nano from CircuitsToday.com | <img src="https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/Arduino-Nano-Pinout_from_circuitstoday.com.png" width="142" alt="CircuitsToday.com picture of Arduino Nano"><br><img src="https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/01_BlinkingLED_part_A_setup.png" width="150" alt="Image of Blinking LED part B"> |
| [02_LetsGetTalking](https://github.com/Mark-MDO47/CforArduinoClass/tree/master/02_LetsGetTalking "02_LetsGetTalking") | Shows how to print to the Serial Monitor<br>Looks at ASCII strings, arrays, and indexing.<br>Also explores **setup()** and **loop()** and some branching and looping C-statements | <img src="https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/02_SerMon_run.png" width="142" alt="Serial Monitor showing debug print output"> |
| [03_YakityYak](https://github.com/Mark-MDO47/CforArduinoClass/tree/master/03_YakityYak "03_YakityYak") | Shows how to read strings and integers from typing on Serial Monitor<br>Goes deeper on branching and looping, some #define macro trickery to help debugging<br>Begins to explore variable declaration, initialization, scope and storage, and dynamic variable deletion upon return from routine | <img src="https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/03_SerMon_run.png" width="142" alt="Serial Monitor showing typed input and responses"> |

## Some resources on the Web
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

As an aside: some of the projects in the [Arduino Class](https://github.com/Mark-MDO47/ArduinoClass "Arduino Class") will use **binary** arithmetic and **Boolean** logic to implement simple data compression, and this class will just barely touch on these topics. In the [Arduino Class](https://github.com/Mark-MDO47/ArduinoClass "Arduino Class") we will do a quick discussion on how this code works. This is another one of those **TLDR** topics that is important but could be skimmed if you just want to enjoy the project and study it later.

On the other hand, if you truly want to understand how computers work, including the Arduino, then you will want to eventually grasp the topics of **binary** arithmetic and **Boolean** logic.

There is a quick discussion of binary and other numbering systems in the [Arduino Class](https://github.com/Mark-MDO47/ArduinoClass "Arduino Class") resources page:
- https://github.com/Mark-MDO47/ArduinoClass/tree/master/99_Resources#tldr-decimal-and-binary-and-hexadecimal

Binary and Boolean are discussed more fully in Wikipedia:
- https://en.wikipedia.org/wiki/Binary_number
- https://en.wikipedia.org/wiki/Boolean_algebra
