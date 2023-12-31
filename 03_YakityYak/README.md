# NOTES

## Back to Root of Class
Click this link to back to go back to the root of the [C for Arduino Class](https://github.com/Mark-MDO47/CforArduinoClass "Link to C for Arduino Class")
- [https://github.com/Mark-MDO47/CforArduinoClass](https://github.com/Mark-MDO47/CforArduinoClass "Link to C for Arduino Class")

## Introduction
[Back to Top](#notes "Back to Top")<br>
In this section we will investigate reading **input from the USB serial port** and using it to direct the execution  of the program. We will also look at a few C-language **syntax** items, some **for** and **while** loops (we won't look at **until** loops), and **#define** macros for debugging. I left some debugging code in so you can see a couple of debugging techniques.

Some of the code might get a little complicated at this early stage in your learning to code. It might feel like drinking from a fire hose. Don't worry, this is a first introduction so just try to follow the flow and get used to what code does. We will cover many of these topics again in the [Arduino Class](https://github.com/Mark-MDO47/ArduinoClass "Link to Arduino Class").

What will you want to pay attention to or return to when you have a need?
- General useful C language:
  - [Before the setup Code](#before-the-setup-code "Before the setup Code")
  - [Before the setup Code - DAD_JOKES](#before-the-setup-code-\--dad_jokes "Before the setup Code - DAD_JOKES")
  - [Before the setup Code - get_3_int_values](#before-the-setup-code-\--get_3_int_values "Before the setup Code - get_3_int_values")
  - [Before the setup Code - get_ascii_string](#before-the-setup-code-\--get_ascii_string "Before the setup Code - get_ascii_string") - the **Syntax** section.
- Techniques to get numbers or strings from a serial port:
  - [Before the setup Code - get_3_int_values](#before-the-setup-code-\--get_3_int_values "Before the setup Code - get_3_int_values")
  - [Before the setup Code - get_ascii_string](#before-the-setup-code-\--get_ascii_string "Before the setup Code - get_ascii_string")
- Looping methods:
  - [The setup Code - while TRUE - forever loop](#the-setup-code-\--while-true-\--forever-loop "The setup Code - while TRUE - forever loop")
  - [The setup Code - forever loop - Temperature for loop](#the-setup-code-\--forever-loop-\--temperature-for-loop "The setup Code - forever loop - Temperature for loop")
  - [The setup Code - forever loop - All Jokes for loop](#the-setup-code-\--forever-loop-\--all-jokes-for-loop "The setup Code - forever loop - All Jokes for loop")
- Debugging methods and #define macros:
  - [Before the setup Code - Debugging](#before-the-setup-code-\--debugging "Before the setup Code - Debugging")
  - [The setup Code - initialization](#the-setup-code-\--initialization "The setup Code - initialization")
  - [Running with DEBUG code enabled](#running-with-debug-code-enabled "Running with DEBUG code enabled")

**Table Of Contents**
* [Top](#notes "Top")
* [Back to Root of Class](#back-to-root-of-class "Back to Root of Class")
* [Introduction](#introduction "Introduction")
* [All the Code](#all-the-code "All the Code")
* [Calling the setup code](#calling-the-setup-code "Calling the setup code")
* [Before the setup Code](#before-the-setup-code "Before the setup Code")
  * [Before the setup Code - Debugging](#before-the-setup-code-\--debugging "Before the setup Code - Debugging")
  * [Before the setup Code - DAD_JOKES](#before-the-setup-code-\--dad_jokes "Before the setup Code - DAD_JOKES")
  * [Before the setup Code - get_3_int_values](#before-the-setup-code-\--get_3_int_values "Before the setup Code - get_3_int_values")
    * [How to call get_3_int_values and get three values back](#how-to-call-get_3_int_values-and-get-three-values-back "How to call get_3_int_values and get three values back")
    * [How does get_3_int_values work](#how-does-get_3_int_values-work "How does get_3_int_values work")
  * [Before the setup Code - get_ascii_string](#before-the-setup-code-\--get_ascii_string "Before the setup Code - get_ascii_string")
    * [How to call get_ascii_string and get a pointer to the string back](#how-to-call-get_ascii_string-and-get-a-pointer-to-the-string-back "How to call get_ascii_string and get a pointer to the string back")
    * [How does get_ascii_string work](#how-does-get_ascii_string-work "How does get_ascii_string work")
* [The setup Code](#the-setup-code "The setup Code")
  * [The setup Code - initialization](#the-setup-code-\--initialization "The setup Code - initialization")
  * [The setup Code - while TRUE - forever loop](#the-setup-code-\--while-true-\--forever-loop "The setup Code - while TRUE - forever loop")
  * [The setup Code - forever loop - Temperature for loop](#the-setup-code-\--forever-loop-\--temperature-for-loop "The setup Code - forever loop - Temperature for loop")
  * [The setup Code - forever loop - Joke](#the-setup-code-\--forever-loop-\--joke "The setup Code - forever loop - Joke")
  * [The setup Code - forever loop - Choose Joke](#the-setup-code-\--forever-loop-\--choose-joke "The setup Code - forever loop - Choose Joke")
  * [The setup Code - forever loop - All Jokes for loop](#the-setup-code-\--forever-loop-\--all-jokes-for-loop "The setup Code - forever loop - All Jokes for loop")
  * [the setup Code - input error detected](#the-setup-code-\--input-error-detected "the setup Code - input error detected")
* [Running with DEBUG code enabled](#running-with-debug-code-enabled "Running with DEBUG code enabled")
* [Running with DEBUG code disabled](#running-with-debug-code-disabled "Running with DEBUG code disabled")
* [Congratulations - that is the end](#congratulations-\--that-is-the-end "Congratulations - that is the end")

## All the Code
[Back to Top](#notes "Back to Top")<br>
The code for this exercise is at
- https://github.com/Mark-MDO47/CforArduinoClass/blob/master/ArduinoCode/03_YakityYak/03_YakityYak.ino

We will be examining and running this code.

## Calling the setup code
[Back to Top](#notes "Back to Top")<br>
One thing I want to point out is that there is nothing magic about the **setup()** and **loop()** code. It is there for your convenience, but in this section we will only use the **setup()** and not do the **loop()** ever.

You can imagine that the code that calls **setup()** and **loop()** looks something like this:
```C
#define TRUE 1
#define FALSE 0
void main() {
  setup();
  while (TRUE) {
    loop();
  } // end while()
} // end main()
```

This code would call **setup()** once and then loop forever calling **loop()**. This is because the **while () {}** statement will repeat the code inside the **{}** block as long as the condition inside the **()** is non-zero. Because we did **#define TRUE 1**, that will always be the case.

In fact the code calling **setup()** and **loop()** is more complicated than my code above, but you can **almost** always do your code as if it was being called from the above.

**TLDR** - a **while (1) {}** loop doesn't have to loop forever if you don't want it to. One way to break out of any loop is with the **break** statement. This would quit executing the loop **{}** block and continue on the next code statement after the loop **{}** block. The **break** statement works for exiting all types of loops.

## Before the setup Code
[Back to Top](#notes "Back to Top")<br>
We have a few routines and definitions before the setup Code. Here is a little road map to this earlier code:
| What | Description |
| --- | --- |
| #define's | We #define TRUE, FALSE, DO_DEBUG, and DO_DEBUG_INPUT.<br>The DEBUG #defines control macro definitions for things such as DEBUG_PRINT and DEBUG_PRINTLN. These statements can be sprinkled around to help debugging. After debugging is complete, DO_DEBUG and DO_DEBUG_INPUT can be #defined as 0 and the statements won't compile. |
| #define's | #define NUMOF(x) (sizeof((x)) / sizeof((*x))) // calculates the size of an array<br>This simple version of NUMOF is quite handy: it gives the number of elements in an array. We will use it with the array of character pointers named DAD_JOKES. The reason NUMOF is simple is that it doesn't try to do everything. If you give it something that is not an array and doesn't behave like an array, it will cheerfully give a compile error or quietly give you a nonsense number |
| get_3_int_values() | Routine to get three integer values from the USB serial port then flush to '\n'<br>'\n' is end of line; called **newline**<br>When you call this routine it will not return until it gets three integers. You can enter them all on one line such as "1,2,3" or enter each number on a separate line without using commas. If you enter "1,2,3,fred" it will ignore everything after the "," following 3. |
| get_ascii_string() | Routine to get one string (no leading or trailing ' ' or '\t') then flush to '\n'<br>'\t' is the **TAB** character<br>IF you enter "Fred Joe Mary" it will just return "Fred". |

### Before the setup Code - Debugging
[Back to Top](#notes "Back to Top")<br>
Here are some **#define macros** that I use to print debug information until the code is working, and then turn it off (into blank lines). If I see more bugs I can turn it on again.
```C
#define TRUE  1 // in a LOGICAL statement, anything non-zero is true
#define FALSE 0 // in a LOGICAL statement, only zero is false

#define DO_DEBUG FALSE // TRUE=debug, FALSE=no debug
#if DO_DEBUG
  // NOTE: these are not complex enough to cover all the cases
  #define DEBUG_PRINT(x) Serial.print((x))
  #define DEBUG_PRINTLN(x) Serial.println((x))
#else
  #define DEBUG_PRINT(x) 
  #define DEBUG_PRINTLN(x) 
#endif // DO_DEBUG

#define DO_DEBUG_INPUT FALSE // TRUE=debug, FALSE=no debug
#if DO_DEBUG_INPUT
  // NOTE: these are not complex enough to cover all the cases
  #define DEBUG_INPUT_PRINT(x) Serial.print((x))
  #define DEBUG_INPUT_PRINTLN(x) Serial.println((x))
#else
  #define DEBUG_INPUT_PRINT(x)
  #define DEBUG_INPUT_PRINTLN(x)
#endif // DO_DEBUG_INPUT
```

First we #define TRUE as 1 and FALSE as 2. Remember that this means wherever the C compiler sees TRUE it will replace it with 1, etc.

Next we see **#define DO_DEBUG FALSE**. As we will see this "turns off" the DEBUG_PRINT and DEBUG_PRINTLN macros. If we said **#define DO_DEBUG TRUE** it would turn on those macros.

Next we see **#if DO_DEBUG**, **#else** and **#endif**. The are conditional compilation directives.
- Everything between **#if DO_DEBUG** and **#else** is only compiled if DO_DEBUG is TRUE or non-zero; otherwise it is not compiled.
- Everything between **#else** and **#endif** is only compiled if DO_DEBUG is FALSE or zero; otherwise it is not compiled.
- If **#define DEBUG_INPUT_PRINT(x) Serial.print((x))** is compiled, **DEBUG_PRINT("This is a string");** will turn into **Serial.print(("This is a string"));**
- If **#define DEBUG_PRINT(x)** with no text after is compiled,  **DEBUG_PRINT("This is a string");** will turn into **;** (a null code statement)
- This is a **#define** macro with a parameter. The **(x)** is the parameter.
  - A **#define** macro could have more than one parameter, separated by commas. The DEBUG_PRINT (and later NUMOF) macro use just one parameter.
  - IMHO the open parenthesis should be adjacent to the name of the macro both when defined and when used.

**TLDR** - there is another variant for "#if" we don't use here: **#elif** for "else if". Useful but not used in this code nor in the [Arduino Class](https://github.com/Mark-MDO47/ArduinoClass "Arduino Class").
- **TLDR** - there are even more conditional compilation directives: **#ifdef**, **#ifndef**. These test if a #define has been done for a symbol. There is also **#undef** to "un-define" a symbol.
- **TLDR** - continuing on the tests for being "#define"d, there is a **#if defined(SYMBOL)** that is precisely equivalent to #ifdef SYMBOL.
  - **TLDR** - this allows tests of multiple symbols - example **#if defined(SYMBOL_1) && defined(SYMBOL_2)**

Similar statements apply to DO_DEBUG_INPUT and DEBUG_INPUT_PRINT, etc.
- I left these DEBUG_ macros in the code since they can be pretty handy for debugging. When it seems to work you can turn them off. If later you experience another bug, you can turn them back on.

**#define macros** can get pretty complex. I will give more discussion of parameter substitution in the **#define NUMOF(x)** macro below, but I won't go much deeper than that.
- If you are interested you might start with https://en.wikibooks.org/wiki/C_Programming/Preprocessor_directives_and_macros and search for #define
- Or **The C Programming Language** by Kernighan and Ritchie.
- **Pro Tip** - there are some predefined things \_\_file\_\_, \_\_func\_\_, \_\_line\_\_, and others that can be helpful to print in debug statements.
- **TLDR** - the code for 98_TLDR_LetsGetTalking has more complicated input functions and more complex use of these debugging methods.

### Before the setup Code - DAD_JOKES
[Back to Top](#notes "Back to Top")<br>
The definition of the DAD_JOKES array of pointers is shown below, with **< ... >** indicating some lines left out.
```C
// NOTE: the following will not warn you if you use it on something that is not an array
#define NUMOF(x) (sizeof((x)) / sizeof((x[0]))) // calculates the size of an array

const char * DAD_JOKES[] = {
  "What's a lawyer's favorite drink? Subpoena colada.",
  "I'm afraid for the calendar. Its days are numbered.",
          < ... >
  "My wife said I should do lunges to stay in shape. That would be a big step forward.",
  "I used to run a dating service for chickens. But I was struggling to make hens meet."
/*
  "My hotel tried to charge me ten dollars extra for air conditioning. That wasn't cool.",
          < ... >
  "A man walks into a magic forest and tries to cut down a talking tree. \"You can't cut me down,\" the tree complains. \"I'm a talking tree!\" The man responds, \"You may be a talking tree, but you will dialogue.\"",
 */
}; // end DAD_JOKES[]

int NUMOF_DAD_JOKES = NUMOF(DAD_JOKES);
int CURRENT_DAD_JOKE = 0;
```

As we saw in [02_LetsGetTalking section on characters and strings](https://github.com/Mark-MDO47/CforArduinoClass/blob/master/02_LetsGetTalking/README.md#ascii-characters-and-strings "02_LetsGetTalking section on characters and strings"), the form using double-quoted text such as **"string"** creates in most instances a **pointer** to a place where the **zero-terminated ASCII string** is stored. The code **const char * DAD_JOKES[] = {** creates an array of **const char \*** (int this case, pointers to strings) and everything after the open-curly-brace **{** until the closing-curly-brace **}** creates initialization values for this array.
- The **const** part is a tricky syntax to avoid a C++ warning about turning a "pointer to a constant string (one of the dad jokes)" into a "pointer to a string that could be modified (char * DAD_JOKES[])". The rules for the placement of **const** can get very tricksy, but this one is simple.

These strings take a lot of our RAM and our total usage of allocated RAM is almost 75% as shown when we compile.
- Global variables use 1522 bytes (74%) of dynamic memory, leaving 526 bytes for local variables. Maximum is 2048 bytes.

Because we need to leave some RAM for dynamic allocation, I just commented out a bunch of dad jokes until we had about 25% of RAM left.
- We could have done trickier code to put these strings into PROGMEM instead of RAM but that would make everything even trickier.
- For a description of PROGMEM, see https://github.com/Mark-MDO47/ArduinoClass/blob/master/99_Resources/README.md#progmem-and-f-macro-to-save-ram

**Syntax** - we create the #define macro **#define NUMOF(x) (sizeof((x)) / sizeof((x[0])))**. Later in a code statement we use **NUMOF(DAD_JOKES)** to initialize an int variable named NUMOF_DAD_JOKES.
- This #define macro is a little more complex than DEBUG_PRINT or its variations. 
- If we look at **sizeof(DAD_JOKES)** we will see it is 38, but there are 19 strings that are not commented out.
  - That is because each entry in DAD_JOKES is two bytes long which we can see by looking at the size of the first entry: **sizeof(DAD_JOKES[0])**.
- Replacing each **x** in the macro with **DAD_JOKES**, we get **(sizeof((DAD_JOKES)) / sizeof((DAD_JOKES[0])))** or **(38 / 2)**
- So NUMOF(DAD_JOKES) does the division (38/2) to get 19, the number of strings in DAD_JOKES.
- The extra levels **()** helps to make the macro **NUMOF** work even on some odd ways of defining an array or using NUMOF in expressions.

By using this NUMOF macro, I don't have to count the strings by hand later on when I set up a loop to print all the DAD_JOKES.

### Before the setup Code - get_3_int_values
[Back to Top](#notes "Back to Top")<br>

We will first talk syntax on how to call a routine and get three values back. Next we will show how get_3_int_values reads the input and converts it to 3 integers.

#### How to call get_3_int_values and get three values back
[Back to Top](#notes "Back to Top")<br>
Some later code does the following
```C
      int first, increment, beyond_maximum; // temp loop parameters
          < ... >
      Serial.println(F("Enter start degF, end degF, and stride degF\n"));
      get_3_int_values(&first, &beyond_maximum, &increment);
      Serial.print(F("You entered ")); Serial.print(first); Serial.print(F(", ")); Serial.print(beyond_maximum); Serial.print(F(", and "));
```

**Syntax** - the comma (**,**) in **int first, increment, beyond_maximum;** causes all of these variables to be defined as **int**.

At the end of **get_3_int_values** we see the code
```C
void get_3_int_values(int * first, int * second, int * third) {
          < ... >
    *first = tmp_first;
    *second = tmp_second;
    *third = tmp_third;
```

**Syntax**
- the ampersand **&** in the call to **get_3_int_values(&first, &beyond_maximum, &increment);** means to pass a pointer to (the address of) the variables first, etc.
- the asterisk **\*** in routine **get_3_int_values(int * first, int * second, int * third)** tells the C compiler to treat the parameters being passed in as a pointer to (the address of) the three integers.
- the parameters get substituted in order. For instance, &first in the call goes to "int * first" in the routine get_3_int_values, &beyond_maximum goes to "int * second", and &increment goes to "int * third".
- to store into beyond_maximum from the routine get_3_int_values, we use the asterisk **\*** again in the code statement "*second = tmp_second;". This is known as **dereferencing the pointer**.

#### How does get_3_int_values work
[Back to Top](#notes "Back to Top")<br>
Here is the code for get_3_int_values():
```C
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// get_3_int_values() - get three integer values then flush to '\n'
//
//    parameters:
//       int * first, int * second, int * third - place to store three integers
//    returns: nothing; values are stored via parameter pointers
//
// Reads from Serial, gets three integers then flushes to '\n'.
// Stores the three integers via the addresses from the three input parameters
// Does not return until the flush is complete.
//
// Example input strings that will fill results with 1, 2, and 3:
//     (one line) -> "1,2,3"
//     (one line) -> "    1   2   3    this text is ignored"
//     (one line) -> "1x2y3"
//     (6 lines)  -> "q ignores non integers but watch out for minus and plus sign
//                    a
//                    k
//                    1
//                    2
//                    3"
//

void get_3_int_values(int * first, int * second, int * third) {
  int tmp_first, tmp_second, tmp_third;

  while (0 == Serial.available()) ; // wait for some typing

  // now read the next three numbers. Serial.parseInt() will keep going until it has a number
  // get the next valid integer in the incoming serial stream:
  tmp_first = Serial.parseInt();
  DEBUG_PRINT(F("DEBUG tmp_first=")); DEBUG_PRINT(tmp_first);
  // do it again:
  tmp_second = Serial.parseInt();
  DEBUG_PRINT(F(" tmp_second=")); DEBUG_PRINT(tmp_second);
  // do it again:
  tmp_third = Serial.parseInt();
  DEBUG_PRINT(F(" tmp_third=")); DEBUG_PRINT(tmp_third);

  // look for the newline. That's the end of the "sentence":
  while (!(Serial.read() == '\n')) ; // wait for the end of line
  DEBUG_PRINTLN(F(" Got the newline"));

  *first = tmp_first;
  *second = tmp_second;
  *third = tmp_third;
} // end get_3_int_values()
```

REMEMBER that the **DEBUG_PRINT** and **DEBUG_PRINTLN** macros will turn into blank lines unless **DO_DEBUG** is defined as TRUE or non-zero.
- See [Before the setup Code - Debugging](#before-the-setup-code-\--debugging "Before the setup Code - Debugging") for more info

The first thing get_3_int_values() does is wait for some typing from the "Serial Monitor" - **while (0 == Serial.available()) ;**.
- The **while** loop executes the while block until the while condition inside the parenthesis is TRUE.
  - **(0 == Serial.available())** will be TRUE until typing starts, then FALSE.
- The while block in this case is the null statement **;**. This causes the code to continuously check the while condition is FALSE.

Now that there is some typing it will call **Serial.parseInt()** three times to get the three integers.
- Each time it is called, Serial.parseInt() will keep looking until it gets an integer. It skips characters that could not be an integer, using them as separators. It even skips over new lines.
- Notice that if it sees something like all-ok, it will interpret the **-** minus sign as -0 and return zero. Same for **+** plus sign.

Next it calls **Serial.read()** to get all the characters one at a time until we get the newline character **'\n'**.

Finally it stores the three numbers where the caller told us to put them and returns.

### Before the setup Code - get_ascii_string
[Back to Top](#notes "Back to Top")<br>
Once again, first we will discuss how to call the routine and get the data back. Then we will discuss how the routine works.

#### How to call get_ascii_string and get a pointer to the string back
[Back to Top](#notes "Back to Top")<br>
Here is the start and end of the code for get_ascii_string():
```C
#define MAX_STRING_LENGTH 20

char * get_ascii_string() {
  static char ascii_string[MAX_STRING_LENGTH+1]; // only this routine knows the name, but we return a pointer to it
  String my_string_object = "Hello!";
       < ... >
  return(ascii_string);
} // end get_ascii_string() - STRING CLASS version
```

**Syntax** - by declaring **char * get_ascii_string() {**, we are telling the C compiler that get_ascii_string() will return a pointer to zero or more characters. By design, get_ascii_string() will return a pointer to one or more characters in a zero-terminated ASCII string. It does this in the code statement **return(ascii_string);**.

The code that calls get_ascii_string() looks like this:
```C
  char * input_string; // this variable will store a pointer to a zero-terminated ASCII string
       < ... >
    input_string = get_ascii_string(); 
    Serial.print(F("You entered ")); Serial.println(input_string); Serial.println(F(""));
```

**Syntax** - As you can see, the address of the string that is returned from get_ascii_string() goes into the variable input_string that is declared as **char \*** - a pointer to zero or more char, just like in the declaration of get_ascii_string(). We can print this string with **Serial.println(input_string);**.

**Syntax** - the **static** keyword in **static char ascii_string[MAX_STRING_LENGTH+1];** makes ascii_string usable after get_ascii_string() returns.
```C
#define MAX_STRING_LENGTH 20

char * get_ascii_string() {
  static char ascii_string[MAX_STRING_LENGTH+1]; // only this routine knows the name, but we return a pointer to it
  String my_string_object = "Hello!";
       < ... >
  return(ascii_string);
} // end get_ascii_string() - STRING CLASS version
```

If we left "static" out but still returned the address of ascii_string, it would be a classic type of bug: **use after free**.
- Any variable declared inside a curly-braces block or in a for-loop parenthesis without **static** will be allocated in **dynamically-allocatable free RAM** - almost certainly on a **stack** - and returned to **free** usage when the block completes. Such variables should not be used after they are freed - they might have been dynamically allocated to some other use in the meantime.
- As an example, the next declaration **String my_string_object = "Hello!";** is allocated in dynamically-allocatable free RAM and "freed" when get_ascii_string() returns. We say that the **scope** of the variable **my_string_object** is within get_ascii_string().

A different way to have the ascii_string variable usable after get_ascii_string() returns would be to declare it outside of all the code blocks - perhaps near the start of the 03_YakityYak.ino file. This would give the variable the **scope** of the entire file, and would automatically make it have a persistent character such as that given by the static keyword.
  - This is what was done with the declarations of DAD_JOKES, NUMOF_DAD_JOKES, and CURRENT_DAD_JOKE. Notice that all of these can be accessed inside of **loop()** even though they were not defined inside of **loop()**. They could also be accessed anywhere else in the file 03_YakityYak.ino that is after the declaration, such as **setup()** etc.
  - For instance **int CURRENT_DAD_JOKE = 0;** is placed early in the file before the first executable routine. It could but doesn't need to say **static** in order to have the **scope** of the rest of the file. Much later in the file, inside **setup()**, we have the code that uses CURRENT_DAD_JOKE. All of the other routines (get_3_int_values, get_ascii_string, loop) could access and/or change CURRENT_DAD_JOKE since they come after the declaration. However, only setup() accesses and changes it.
    - That actually means that it would be better to have placed a **static int CURRENT_DAD_JOKE = 0;** inside setup(). I would have done this except I wanted to show the different ways to affect storage (static or dynamic) and scope (within a block or within a file).
```C
int CURRENT_DAD_JOKE = 0;
        < ... >
void setup() {
        < ... >
      Serial.print(CURRENT_DAD_JOKE+1); Serial.print(": "); Serial.println(DAD_JOKES[CURRENT_DAD_JOKE++]);
      if ((NUMOF_DAD_JOKES-1) < CURRENT_DAD_JOKE) CURRENT_DAD_JOKE = 0;
        < ... >
} // end setup()
```

**TLDR** **Syntax** - You will not need this in the introductory [C for Arduino Class](https://github.com/Mark-MDO47/CforArduinoClass "Link to C for Arduino Class").
- There is another level to **scope** in addition to within a block or within a file - this would be **global** and accessible within multiple files. 
- Sometimes code gets so complicated that it gets split into multiple files. In the Arduino world, this means having one *.ino file with at least setup() and loop() and other files (usually *.c or *.cpp for executable code and *.h for definitions to be shared among multiple files).
- To make something have global scope to two or more files, we use the **extern** keyword.
- Typically a *.h file is created to contain (in our example) **extern int CURRENT_DAD_JOKE;**. This tells the C Compiler/Linker that there is something called CURRENT_DAD_JOKE that is an int and that could be used in more than one file.
  - Let us say that this file is named **current_dad_joke.h** and placed in the same directory as all the other *.ino, *.h, *.c and/or *.cpp files for that project. 
- All *.ino, *.c and/or *.cpp files that need to use CURRENT_DAD_JOKE will have the line **#include "current_dad_joke.h"**, typically early in the file.
- Within **one and only one** of the *.ino, *.c and/or *.cpp files that have this include line, there will be the line **int CURRENT_DAD_JOKE = 0;** which declares the variable, allocates static memory for an int, and initializes it to zero.
- All of the *.ino, *.c and/or *.cpp files that have that **#include "current_dad_joke.h"** line will be free to access and/or change CURRENT_DAD_JOKE in any code **after the include statement** in that file.
- This sort of arrangement with lots of **global scope** or **file scope** variables is considered to be bad form and to be avoided.
  - The reasoning is that if there is a bug, the code that accesses the variable is spread all over the place so the bug is harder to find. As time goes on and changes and additions are made, the number of places that the variable is used are likely to proliferate.
  - The other side of the coin is that it makes the lines of the code shorter and perhaps clearer to use the global variables that "everyone" knows about.
- Of course there are other variations and even different uses for extern that are possible, especially for accessing executable routines.
- As Paul Harvey used to say, "Now you know ... the rest of the story".
  - Or at least some more of the story. We didn't (and won't) talk about **C++ namespaces**, but be aware they exist and make it so you can have multiple libraries with a variable named DEBUG and they don't have to collide.

**Syntax** - the next declaration is **String my_string_object = "Hello!";**. The **String** type is an Arduino built-in C++ class. When we say **String my_string_object = "Hello!";**, we are declaring the variable and initializing it to contain the string **"Hello!"**. This initialization would typically include setting other aspects of this string object, perhaps including the length of the string. There are other ways to initialize our String object; if you are interested you can find more information here:
- https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/
- https://docs.arduino.cc/built-in-examples/strings/StringConstructors

**Syntax** - get_ascii_string() will use **methods** of this String object my_string_object
```C
#define MAX_STRING_LENGTH 20

char * get_ascii_string() {
  static char ascii_string[MAX_STRING_LENGTH+1]; // only this routine knows the name, but we return a pointer to it
  String my_string_object = "Hello!";
```

#### How does get_ascii_string work
[Back to Top](#notes "Back to Top")<br>
Here is the code for get_ascii_string():
```C
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// get_ascii_string() - get one string (no leading or trailing ' ' or '\t') then flush to '\n'
//
// THIS IS THE STRING CLASS VERSION
//
//    parameters: none
//    returns:    char * pointer to the string
//
// Reads from Serial, gets one string then flushes to '\n'.
// Does not return until the flush is complete.
// Maximum string length is MAX_STRING_LENGTH
//
// Restriction: if you want to get two different strings, you need to copy
//    them out of our string buffer when we return and store the strings in
//    your own separate buffers.
// Another way to say this is that this routine only has one string buffer.
//    The second time you call it, it will overwrite the string buffer from
//    the first call.
//
#define MAX_STRING_LENGTH 20

char * get_ascii_string() {
  static char ascii_string[MAX_STRING_LENGTH+1]; // only this routine knows the name, but we return a pointer to it
  String my_string_object = "Hello!";
  int16_t tmp1 = 0;
  int16_t tmp2 = 0;
  uint8_t found = FALSE;

  Serial.setTimeout(10000); // 10,000 milliseconds is 10 seconds
  memset((void *)ascii_string, 0, NUMOF(ascii_string)); // clear buffer; good idea for zero-terminated strings

  while (!found) {
    while (!Serial.available()) ; // wait for typing to start
    my_string_object = Serial.readStringUntil('\n'); // get a line
    DEBUG_INPUT_PRINT(F("DBGIN Entire String object |")); DEBUG_INPUT_PRINT(my_string_object); DEBUG_INPUT_PRINTLN(F("|"));
    my_string_object.trim(); // trim off spaces/tabs front and back
    DEBUG_INPUT_PRINT(F("DBGIN trimmed String object |")); DEBUG_INPUT_PRINT(my_string_object); DEBUG_INPUT_PRINTLN(F("|"));
    if (0 != my_string_object.length()) {
      found = TRUE;
      tmp1 = my_string_object.indexOf(' ');
      tmp2 = my_string_object.indexOf('\t');
      DEBUG_INPUT_PRINT(F("DBGIN tmp1=")); DEBUG_INPUT_PRINT(tmp1); DEBUG_INPUT_PRINT(F(", tmp2=")); DEBUG_INPUT_PRINTLN(tmp2);
      if (-1 == tmp1) tmp1 = 2*MAX_STRING_LENGTH; // make it big and positive
      if (-1 == tmp2) tmp2 = 2*MAX_STRING_LENGTH;
      // if no ' ' or '\t' found, will copy entire string
      //string2ascii_ncopy(my_string_object, ascii_string, 0, min(tmp1,tmp2), MAX_STRING_LENGTH);
      tmp1 = min(tmp1,tmp2);
      tmp1 = min(tmp1,my_string_object.length());
      tmp1 = min(tmp1,MAX_STRING_LENGTH);
      for (int i = 0; i < tmp1; i++) {
        ascii_string[i] = my_string_object[i];
      }
      DEBUG_INPUT_PRINT(F("DBGIN Entire ASCII string result |")); DEBUG_INPUT_PRINT(ascii_string); DEBUG_INPUT_PRINTLN(F("|"));
    } // end if my_string_object has at least one character
  } // end while (!found)

  return(ascii_string);
} // end get_ascii_string() - STRING CLASS version
```

REMEMBER that the **DEBUG_INPUT_PRINT** and **DEBUG_INPUT_PRINTLN** macros will turn into blank lines unless **DO_DEBUG_INPUT** is defined as TRUE or non-zero.
- See [Before the setup Code - Debugging](#before-the-setup-code-\--debugging "Before the setup Code - Debugging") for more info

get_ascii_string() uses the builtin **String object** capabilities and these routines/methods:
- Serial.setTimeout() - sets the timeout for routines like readStringUntil()
- Serial.available() - returns TRUE if there is a character that can be read
- Serial.readStringUntil() - reads typing until either timeout or the character specified
- <string-object>.trim() - removes leading or trailing blanks and/or TABs (' ' or '\t') from String object
- <string-object>.length() - returns length in characters of the ASCII string within String object
- <string-object>.indexOf() - returns -1 or first character position of specified character within String object
- <string-object>.[] - returns the ASCII character at the specified position of the ASCII string within String object
  - Yes this is a "method" of an "object" in C++ - too complicated for an introductory class to cover

We start by increasing the **Serial** timeout value and zeroing out **ascii_string**.
- If we call a string routine and nothing happens for the timeout, it will return without getting all the typing. There doesn't seem to be a way to get the current timeout value so it could restore that value after. I didn't see a problem with just setting it longer.
- Once ascii_string is zero, if we copy a string into it that is at least one char shorter than ascii_string then it will automatically be zero-terminated.
```C
  Serial.setTimeout(10000); // 10,000 milliseconds is 10 seconds
  memset((void *)ascii_string, 0, NUMOF(ascii_string)); // clear buffer; good idea for zero-terminated strings
```

The user could type in a string of indefinite length and we have a place to store it with a fixed length - **#define MAX_STRING_LENGTH 20**. If not handled properly, this could lead to a classic type of bug known as a **buffer overflow**, where data is written past the end of a buffer and therefore into areas that may be unrelated. get_ascii_string() has code to prevent a buffer overflow.
- When getting the typing from the user, the typing goes into a C++ object of type **String** in the call **Serial.readStringUntil('\n');**. Assuming there is enough RAM available for dynamic allocation, this object will prevent buffer overflows. If there is not enough RAM, there is not much it can do but I assume it will be pretty robust.
- get_ascii_string() then uses this <String> object to determine the start and end of the part of the string we want by means of methods <String>.trim() and <String>..indexOf(). We want a string without any blanks or tabs.
  - **my_string_object.trim();** removes all spaces or tabs either before the first non-blank or after the last non-blank
  - **if (0 != my_string_object.length()) {** is used to see if there is anything left after removing leading or trailing spaces or tabs
  - if there are still some characters, **tmp1 = my_string_object.indexOf(' ');** and **tmp2 = my_string_object.indexOf('\t');** get the locations of the first blank and tab. **.indexOf()** returns -1 if it doesn't find anything.
  - statements like **if (-1 == tmp1) tmp1 = 2*MAX_STRING_LENGTH;** will change **-1** values to something bigger than MAX_STRING_LENGTH, causing those numbers to be ignored later. 
- get_ascii_string() then range checks all the information and copies at most only as many non-blank non-tab characters as will fit into the ASCII char buffer. This code is the series of **tmp1 = min(tmp1,...)** statements. Note that the last of these checks against MAX_STRING_LENGTH.

At this point, tmp1 is the minimum of all the **.indexOf()**, **.length()**, and MAX_STRING_LENGTH. The following **for loop** copies the ASCII characters from **my_string_object** to **ascii_string**. The **[]** notation is an array index for ascii_string but it is a String object method for my_string_object.
```C
      for (int i = 0; i < tmp1; i++) {
        ascii_string[i] = my_string_object[i];
      }
```

To make the code easier to read, the ASCII char buffer is declared with **+1** as **static char ascii_string[MAX_STRING_LENGTH+1];**. This is because we need a zero-terminated string so we need room for the zero. By having an extra buffer location for the zero-termination of a max-length string, the code doesn't have to be peppered with things like **MAX_STRING_LENGTH-1**; we can just use **MAX_STRING_LENGTH**.

## The setup Code
[Back to Top](#notes "Back to Top")<br>
| What | Description |
| --- | --- |
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

**Syntax** - next there is a **while (Serial.available()) Serial.read();**. Where are the curly braces?
- The answer is that in any block statement such as **if () {}** or **while () {}**, if there is only one code statement to be executed in the block you don't need the curly braces. If there is more than one code statement, you need the curly braces to show what is inside the block.
- The purpose of that code is to flush out any garbage characters that were left in the input queue when we initialized **Serial**.

We start to do the normal prints and then we get **Serial.println(F("CforArduinoClass init..."));**. What is the **F()** doing there?
- The F() surrounding the string places the string into **PROGMEM** instead of **RAM**. The Arduino Nano has very little RAM but much more PROGMEM.
- Using PROGMEM usually requires some extra code, but replacing a double-quoted string in a function or method call is as simple as surrounding it with **F()**.
- I did this trick throughout the code so there would be more room for Dad Jokes.
- You can find more info about this in the Resources page from the Arduino Class: [PROGMEM and F macro to save RAM](https://github.com/Mark-MDO47/ArduinoClass/blob/master/99_Resources/README.md#progmem-and-f-macro-to-save-ram "PROGMEM and F macro to save RAM")

### The setup Code - while TRUE - forever loop
[Back to Top](#notes "Back to Top")<br>
```C
  char * input_string; // this variable will store a pointer to a zero-terminated ASCII string
  while (TRUE) { // loop forever
    Serial.println(F(""));

    Serial.println(F("Enter T (Temp), J (Joke), C (ChooseJoke), or A (AllJoke)"));
    input_string = get_ascii_string(); 
    Serial.print(F("You entered ")); Serial.println(input_string); Serial.println(F(""));
    // make sure first letter of string is capitalized
    if (('a' <= input_string[0]) && ('z' >= input_string[0])) input_string[0] -= 'a' - 'A';
```

We saw the concept of pointers to zero-terminated ASCII strings in the last exercise. This time we will call **get_ascii_string()**, which returns pointer to a zero-terminated ASCII string typed in on the "Serial Monitor" window across the USB serial port.

Once we have the address of the string in input_string, we check the first letter of the string to see if it is lower-case between 'a' and 'z'.
- If so we convert to upper-case by subtracting the difference betwee ASCII 'a' and ASCII 'A'.
- Look again at https://www.asciitable.com/ if you want to see how this works.
```C
    if (('a' <= input_string[0]) && ('z' >= input_string[0])) input_string[0] -= 'a' - 'A';
```

Then we execute different code blocks depending on what the first letter is.
- Note the **if () {} else if () {} else {}** structure. If the first letter is not T, J, C or A we will complain and try again.
```C
    if ('T' == input_string[0]) {
        < ... >
    } else if ('J' == input_string[0]) {
        < ... >
    } else if ('C' == input_string[0]) {
        < ... >
    } else if ('A' == input_string[0]) {
        < ... >
    } else {
      Serial.print(F("ERROR - ")); Serial.print(input_string); Serial.println(F(" is not a valid choice"));
    } // end if which command
```

### The setup Code - forever loop - Temperature for loop
[Back to Top](#notes "Back to Top")<br>
```C
  int f, c; // fahrenheit and centigrade
          < ... >
    if ('T' == input_string[0]) {
      for (f = first; f < beyond_maximum; f += increment) {
        c = ((f - 32) * 5) / 9;
        Serial.print(F(" degF, degC: ")); Serial.print(f); Serial.print(", "); Serial.println(c);
      } // end Fahrenheit and Centigrade for loop
```

Early in setup there is a statement **int f, c; // fahrenheit and centigrade** followed about 20 lines later by **for (f = first; f < beyond_maximum; f += increment)**. What do these do?

**Syntax*** - first the **int** statement with a comma: this just means that both variables **f** and **c** are integers; the **int** applies to both of them. There can be tricky applications like what would happen if we said **int f, c = 5;**? Would both **f** and **c** be initialized to 5? This is an introductory class so I won't go into those type of detailed questions here. If you want to initialize both of them, you already know how to do that with two statements and no comma:<br>
```C
  int f = 5; int c = 5;
```

**Syntax** - the **for ( ; ; )** statement (and the for loop that it generates) is an extremely useful and common happening in C/C++. it is divided into three parts by semicolons. In our case, the three sections are as follows:
- **f = first** - this is the initialization section, where you can initialize any variable before the "for loop" starts
  - If needed you can initialize more than one variable by separating with commas. Example: **f = first, c = 1**
  - You can even define and initialize new variables in the initialization section that only affect the for loop. Example: **int new_variable = 7, f = first, c = 1**
- **f < beyond_maximum** - this is the definition of the **condition** that must be true to execute anything in the for statement
  - **Pro Tip** - it is checked BEFORE THE FIRST EXECUTION of the for loop. If it is false, the loop never executes.
- **f += increment** - this is the action taken AFTER each loop and BEFORE checking the **condition**.
  - Again, multiple actions could be taken. Example: **f += increment, Serial.println("Made f bigger")**
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

### The setup Code - forever loop - Joke
[Back to Top](#notes "Back to Top")<br>
```C
    } else if ('J' == input_string[0]) {
      Serial.print(CURRENT_DAD_JOKE+1); Serial.print(": "); Serial.println(DAD_JOKES[CURRENT_DAD_JOKE++]);
      if ((NUMOF_DAD_JOKES-1) < CURRENT_DAD_JOKE) CURRENT_DAD_JOKE = 0;
```

If the operator chooses to print a Joke by entering a string that starts with J or j, we print the joke from DAD_JOKES[CURRENT_DAD_JOKE].
- Because people tend to think of things starting at 1 instead of 0 but the C compiler starts array indexing at zero, we use **CURRENT_DAD_JOKE+1** when printing the joke number.
- When printing the entry from DAD_JOKES we use **[CURRENT_DAD_JOKE++]**. This form uses CURRENT_DAD_JOKE to index into the array, and afterwards it adds one to CURRENT_DAD_JOKE.
- The last line shown above checks to see if CURRENT_DAD_JOKE has gone past the end; if so it sets it back to zero.
  - Because the last valid array index for **19** jokes is **[18]** (C starts with zero not one), this means that the last valid array index for **NUMOF_DAD_JOKES** is **[NUMOF_DAD_JOKES-1]**.

### The setup Code - forever loop - Choose Joke
[Back to Top](#notes "Back to Top")<br>
```C
    } else if ('C' == input_string[0]) {
      Serial.print(F("Choose 3 Dad Joke nums separated by commas; max num = ")); Serial.println(NUMOF_DAD_JOKES);
      get_3_int_values(&j1, &j2, &j3);
      Serial.print(F("You entered ")); Serial.print(j1); Serial.print(F(", ")); Serial.print(j2); Serial.print(F(", and ")); Serial.println(j3);
      Serial.print(j1); Serial.print(": "); Serial.println(DAD_JOKES[max(min(j1,NUMOF_DAD_JOKES),1)-1]);
      Serial.print(j2); Serial.print(": "); Serial.println(DAD_JOKES[max(min(j2,NUMOF_DAD_JOKES),1)-1]);
      Serial.print(j3); Serial.print(": "); Serial.println(DAD_JOKES[max(min(j3,NUMOF_DAD_JOKES),1)-1]);
```

If the operator chooses to Choose which jokes to print by entering a string that starts with C or c, we get three joke numbers and then print those jokes from DAD_JOKES[CURRENT_DAD_JOKE].
- We want to make sure we don't try to print **DAD_JOKES[-1000]** or **DAD_JOKES[+1000]**
  - The **max(min(j1,NUMOF_DAD_JOKES),1)** makes sure that j1 is at least 1 and at most NUMOF_DAD_JOKES, currently 19.
- As usual, we almost always have to either add or subtract 1 to get the correct number. the **-1** after the above converts it to a range of 0 through 18.

### The setup Code - forever loop - All Jokes for loop
[Back to Top](#notes "Back to Top")<br>
```C
    } else if ('A' == input_string[0]) {
      for (j1 = 0; j1 < NUMOF_DAD_JOKES; j1 += 1) {
        Serial.print(j1+1); Serial.print(": "); Serial.println(DAD_JOKES[j1]);
      }
```

If the operator chooses to print All jokes by entering a string that starts with A or a, we use another **for loop**.
- The loop goes from **j1 = 0** to **j1 < NUMOF_DAD_JOKES** or 18 if 19 == NUMOF_DAD_JOKES. This form of the for loop is extremely common; we use the **<** check instead of the **<=** check and then we get to use **NUMOF_DAD_JOKES** instead of **NUMOF_DAD_JOKES-1**.

### the setup Code - input error detected
[Back to Top](#notes "Back to Top")<br>
```C
    } else {
      Serial.print(F("ERROR - ")); Serial.print(input_string); Serial.println(F(" is not a valid choice"));
    } // end if <which command>
```

If the operator typed a string that started with a char that was not recognized, we get to the **else** clause (instead of the above **else if**). Here we just tell them we don't recognize the command and then loop around for the next operator command.

## Running with DEBUG code enabled
[Back to Top](#notes "Back to Top")<br>
Set **TRUE** for DO_DEBUG but not DO_DEBUG_INPUT and run 03_YakityYak.ino. I typed in the following strings:
- temp ignore rest of line
-     2   42   10xyz
-        t
- 2
- 2
- 2
- JOKE

![alt text](https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/03_SerMon_DO_DEBUG_run.png "03 YakityYak Serial Monitor from running Arduino program with DO_DEBUG")

Set **TRUE** for DO_DEBUG_INPUT but not DO_DEBUG and run 03_YakityYak.ino. I typed in the following strings:
-      the big red fox ran over the lazy brown dogs
-  2,2,2
-  joke ignore the rest of the line

![alt text](https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/03_SerMon_DO_DEBUG_INPUT_run.png "03 YakityYak Serial Monitor from running Arduino program with DO_DEBUG_INPUT")

## Running with DEBUG code disabled
[Back to Top](#notes "Back to Top")<br>
Set **FALSE** for DO_DEBUG and DO_DEBUG_INPUT and run 03_YakityYak.ino. I typed in the following strings:
- temperature
- 2,42,10
- joke
- choose
- 2,3,4
- all

![alt text](https://github.com/Mark-MDO47/CforArduinoClass/blob/master/99_Resources/Images/03_SerMon_run.png "03 YakityYak Serial Monitor from running entire Arduino program")

## Congratulations - that is the end
[Back to Top](#notes "Back to Top")<br>
**Congratulations!** - You have reached the end of the **C for Arduino Class** instruction!

You should be able to take the [C for Arduino Class](https://github.com/Mark-MDO47/CforArduinoClass "Link to C for Arduino Class") and understand what the programs are doing.
