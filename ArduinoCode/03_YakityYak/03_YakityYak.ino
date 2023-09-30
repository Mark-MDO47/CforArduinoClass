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

void get_temp_values(int * first, int * increment, int * beyond_maximum) {
  int tmp_first, tmp_inc, tmp_max;

  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    // look for the next valid integer in the incoming serial stream:
    tmp_first = Serial.parseInt();
    // do it again:
    tmp_inc = Serial.parseInt();
    // do it again:
    tmp_max = Serial.parseInt();

    // look for the newline. That's the end of the "sentence":
    while (!(Serial.read() == '\n')) ; // wait for the end of line

    // constrain values to something reasonable
    /* I will let you experiment with the for loop
    if (tmp_max <= tmp_first) {
      tmp_max = tmp_first+1;
    } // end if
    */
    if (tmp_max > (tmp_first + (20*tmp_inc))) {
      tmp_max = tmp_first + (20*tmp_inc);
    } // end if
    *first = tmp_first;
    *increment = tmp_inc;
    *beyond_maximum = tmp_max;
  } // end while (Serial.available() > 0)
} // end get_temp_values()

// the setup function runs once when you press reset or power the board
void setup() {

  // this serial communication is for general debug; set the USB serial port to 115,200 baud
  Serial.begin(115200);

  while (!Serial) {
    ; // note that ";" is a null code statement. Wait for serial port to connect.
  }
  
  Serial.println(""); // print a blank line in case there is some junk from power-on
  Serial.println("CforArduinoClass init...");

  // we are showing that we don't actually need a loop()
  int f, c; // fahrenheit and centigrade
  int first, increment, beyond_maximum; // loop parameters
  while (TRUE) { // loop forever
    Serial.println("");
    Serial.println("Enter start degF, end degF, and stride degF\n");
    get_temp_values(&first, &increment, &beyond_maximum);
    Serial.println("\nFahrenheit and Centigrade computed with integers");
    for (f = first; f < beyond_maximum; f += increment) { // last loop will be 120 since 130 is not < 130
      c = ((f - 32) * 5) / 9;
      Serial.print(" degF, degC: "); Serial.print(f); Serial.print(", "); Serial.println(c);
    } // end Fahrenheit and Centigrade for loop
  } // end while loop

} // end setup()

// the loop function runs over and over again forever
void loop() {
} // end loop()
