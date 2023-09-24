# C for Arduino Class
Enough C/C++ to start the Arduino Class

For an Arduino class 2023; FabLab will be first<br>
Author: Mark Olson<br>
To all who attended the first Arduino Class at FabLab: thanks and I hope you had fun while learning a few things!

**Table of Contents**
* [Top](#c-for-arduino-class "Top")
* [Learning C and Cplusplus](#learning-c-and-cplusplus "Learning C and Cplusplus")
* [Some resources on the Web](#some-resources-on-the-web "Some resources on the Web")

## Learning C and Cplusplus
[Top](#c-for-arduino-class "Top")<br>
One thing I learned when teaching the first class is that things will move much faster if everyone has some basic experience with a text-based programming language.

The Arduino IDE uses C and C++ languages (except for some of the I/O libraries, as explained later).
- If you have experience in any text-based programming language - Python, Java, or other programming languages - you will probably be able to catch on to the parts of C and C++ used in this class quickly.
- If you have never programmed before, I suggest you learn the basics of C before attending this class. You can easily pick up on the few parts of C++ used in this class if you have some knowledge of C (or even Python or Java or other languages)
- This **C for Arduino Class** is intended to provide enough experience with the C and C++ programming languages in the Arduino environment to bring a non-programmer to the stage that they can start the **Arduino Class** and learn the rest on the way through that class.
- https://github.com/Mark-MDO47/ArduinoClass/blob/master/README.md

One factor to consider: Arduino does not implement the standard "printing" etc. functions - not for C (printf and scanf) and not for C++ (IO Streams). Arduino uses relatively simple "Serial" methods such as Serial.begin, Serial.print and Serial.println for output; Serial.available, Serial.read and Serial.readln for input.
- If you want to learn the full languages to further your career, you will probably want to learn the standard C and C++ methods at the same time as learning enough C and C++ for this class. There is a lot to learn about C and C++!
- If you want to get started by doing some fun Arduino projects from this class you can skim the standard C and C++ methods, knowing that they are not used for these projects. You can return to the standard methods later.

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

As an aside: some of the projects will use **binary** arithmetic and **Boolean** logic to implement simple data compression. We will do a quick discussion on how this code works when the time comes. This is another one of those topics that is important but could be skimmed if you just want to enjoy the project and study it later.

There is a quick discussion of binary and other numbering systems in the resources page:
- https://github.com/Mark-MDO47/ArduinoClass/tree/master/99_Resources#tldr-decimal-and-binary-and-hexadecimal

Binary and Boolean are discussed more fully in Wikipedia:
- https://en.wikipedia.org/wiki/Binary_number
- https://en.wikipedia.org/wiki/Boolean_algebra
