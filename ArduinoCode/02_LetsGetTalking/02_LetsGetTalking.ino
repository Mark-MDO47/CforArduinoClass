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

#include "string.h" // includes the standard C definitions found in string.h

// connections:
// N/A

// loop_count is a "variable" that can store one "int" (integer).
// Because it is defined up front and not inside {} brackets, it can be "seen" by everything below
int loop_count = 0;

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

// the loop function runs over and over again forever
void loop() {
  loop_count += 1;    // instead of loop_count = loop_count + 1

  if (loop_count == 1) {
    Serial.print("1 && 1: "); Serial.println(1 && 1);
    Serial.print("1 && 2: "); Serial.println(1 && 2);
    Serial.print("-1 && 999: "); Serial.println(-1 && 999);
    Serial.print("-1 && 0: "); Serial.println(-1 && 0);
    Serial.print("0 || 2: "); Serial.println(0 || 2);
    Serial.print("!(0 || 2): "); Serial.println(!(0 || 2));
    Serial.println("");
  } // end if (loop_count == 1)

  if (loop_count <= 10) {
    // Serial.print() does not go to a new line; Serial.println() does
    Serial.print(" loop_count: "); Serial.println(loop_count);
  } // end if (loop_count...)

  delay(1000);                       // wait for a second
} // end loop()
