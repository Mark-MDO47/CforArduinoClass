/* 03_YakityYak
 *
 * Mark Olson for his "C for Arduino Class" https://github.com/Mark-MDO47/CforArduinoClass
 * 
 * We are using an Arduino Nano with a USB mini-B connector
 *            V3.0 ATmega328P 5V 16M CH340 Compatible to Arduino Nano V3
 *            32Kbyte Flash (program storage), 2Kbyte SRAM, 1Kbyte EEPROM
 *            http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf
 *            http://www.pighixxx.com/test/pinouts/boards/nano.pdf
 *
 * This is code for https://github.com/Mark-MDO47/CforArduinoClass/tree/master/03_YakityYak
 * 
 */

// connections:
// N/A

#define TRUE  1 // in a LOGICAL statement, anything non-zero is true
#define FALSE 0 // in a LOGICAL statement, only zero is false

// the setup function runs once when you press reset or power the board
void setup() {
  int f, c; // fahrenheit and centigrade

  // this serial communication is for general debug; set the USB serial port to 115,200 baud
  Serial.begin(115200);

  while (!Serial) {
    ; // note that ";" is a null code statement. Wait for serial port to connect.
  }
  
  Serial.println(""); // print a blank line in case there is some junk from power-on
  Serial.println("CforArduinoClass init...");

  // we are showing that we don't actually need a loop()
  while (TRUE) { // loop forever
    Serial.println("");
    Serial.println("Enter start degF, end degF, and stride degF");
    Serial.readln
    Serial.println("\nFahrenheit and Centigrade computed with integers");
    for (f = 0; f < 130; f += 10) { // last loop will be 120 since 130 is not < 130
      c = ((f - 32) * 5) / 9;
      Serial.print(" degF, degC: "); Serial.print(f); Serial.print(", "); Serial.println(c);
    } // end Fahrenheit and Centigrade for loop
  } // end while loop

} // end setup()

// the loop function runs over and over again forever
void loop() {
} // end loop()
