/*
  02_LetsGetTalking

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

// connections:
// 
// N/A

// loop_count is a "variable" that can store "int" (integers)
//   because it is defined up front and not inside {} brackets, it can be "seen" by everything below
static int loop_count = 0;

// the setup function runs once when you press reset or power the board
void setup() {

  // this serial communication is for general debug; set the USB serial port to 115,200 baud
  Serial.begin(115200);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.println(""); // print a blank line in case there is some junk from power-on
  Serial.println("CforArduinoClass init...");
}

// the loop function runs over and over again forever
void loop() {
  loop_count += 1;    // instead of loop_count = loop_count + 1

  // Serial.print() does not go to a new line; Serial.println() does
  Serial.print(" loop_count: ");
  Serial.println(loop_count);

  delay(1000);                       // wait for a second
}
