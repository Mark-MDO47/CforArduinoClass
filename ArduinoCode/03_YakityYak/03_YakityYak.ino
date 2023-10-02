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

#define DO_DEBUG 0 // 1=debug, 0=no debug
#if DO_DEBUG
  // NOTE: these are not complex enough to cover all the cases
  #define DEBUG_PRINT(x) Serial.print((x))
  #define DEBUG_PRINTLN(x) Serial.println((x))
#else
  #define DEBUG_PRINT 
  #define DEBUG_PRINTLN 
#endif // DO_DEBUG

#define DO_DEBUG_INPUT 0 // 1=debug, 0=no debug
#if DO_DEBUG_INPUT
  // NOTE: these are not complex enough to cover all the cases
  #define DEBUG_INPUT_PRINT(x) Serial.print((x))
  #define DEBUG_INPUT_PRINTLN(x) Serial.println((x))
#else
  #define DEBUG_INPUT_PRINT 
  #define DEBUG_INPUT_PRINTLN 
#endif // DO_DEBUG_INPUT

// NOTE: the following will not warn you if you use it on something that is not an array
#define NUMOF(x) (sizeof((x)) / sizeof((*x))) // calculates the size of an array

char * DAD_JOKES[] = {
  "What's a lawyer's favorite drink? Subpoena colada.",
  "I'm afraid for the calendar. Its days are numbered.",
  "I used to hate facial hair, but then it grew on me.",
  "If a pig loses its voice…does it become disgruntled?",
  "I don't trust stairs. They're always up to something.",
  "What happens when frogs park illegally? They get toad.",
  "Never date a tennis player. Love means nothing to them.",
  "What do you call a Frenchman wearing sandals? Philippe Flop.",
  "When does a joke become a dad joke? When it becomes apparent.",
  "\"Dad, can you explain to me what a solar eclipse is? \"No sun.",
  "Why is it a bad idea to eat a clock? Because it's so time-consuming.",
  "What do you call a line of men waiting to get haircuts? A barberqueue.",
  "The guy who stole my diary just died. My thoughts are with his family.",
  "If April showers bring May flowers, what do May flowers bring? Pilgrims.",
  "Have you heard about the restaurant on the moon? Great food, no atmosphere.",
  "What do a tick and the Eiffel Tower have in common? They're both Paris sites.",
  "To whoever stole my copy of Microsoft Office, I will find you. You have my Word.",
  "My wife said I should do lunges to stay in shape. That would be a big step forward.",
  "I used to run a dating service for chickens. But I was struggling to make hens meet."
/*
  "My hotel tried to charge me ten dollars extra for air conditioning. That wasn’t cool.",
  "Singing in the shower is fun until you get soap in your mouth. Then it's a soap opera.",
  "Anyone looking to buy a Delorean? Good shape, good mileage. Only driven from time to time",
  "I thought the dryer was shrinking my clothes. Turns out it was the refrigerator all along.",
  "Why is it so cheap to throw a party at a haunted house? Because the ghosts bring all the boos.",
  "I just got my doctor's test results and I’m really upset. Turns out, I’m not gonna be a doctor.",
  "Why do fathers take an extra pair of socks when they go golfing? In case they get a hole in one!",
  "A century ago, two brothers decided it was possible to fly. And as you can see, they were Wright.",
  "I just found out Albert Einstein existed. My whole life I thought he was a theoretical physicist.",
  "Cop: I'm arresting you for downloading the entire Wikipedia. Man: \"Wait! I can explain everything!\"",
  "Your wife and daughter look like twins, my friend said. I replied, Well, they were separated at birth.",
  "My landlord told me we need to talk about the heating bill. \"Sure,\" I said. \"My door is always open.\"",
  "During my calculus test, I had to sit between identical twins. It was hard to differentiate between them.",
  "I was playing chess with my friend and he said, \"Let’s make this interesting.\" So we stopped playing chess.",
  "A cop started crying while he was writing me a ticket. I asked him why and he said, \"It's a moving violation.\"",
  "This year’s Fibonacci convention is going to be really special. Apparently it’s as big as the last two put together.",
  "I just spent $300 on a limo and learned it doesn't come with a driver. I can't believe I have nothing to chauffer it.",
  "As I get older, I remember all the people I lost along the way. Maybe a career as a tour guide was not the right choice.",
  "A panic-stricken man explained to his doctor, \"You have to help me, I think I’m shrinking.\" \"Now settle down,\" the doctor calmly told him. \"You'll just have to learn to be a little patient.\"",
  "A man walks into a magic forest and tries to cut down a talking tree. \"You can't cut me down,\" the tree complains. \"I’m a talking tree!\" The man responds, \"You may be a talking tree, but you will dialogue.\"",
 */
}; // end DAD_JOKES[]

int NUMOF_DAD_JOKES = NUMOF(DAD_JOKES);
int CURRENT_DAD_JOKE = 0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// get_3_int_values() - get three integer values then flush to '\n'
//
//    parameters:
//       int * first, int * second, int * third - place to store three integers
//    returns: nothing
//
// Reads from Serial, gets three integers then flushes to '\n'.
// Does not return until the flush is complete.
//

void get_3_int_values(int * first, int * second, int * third) {
  int tmp_first, tmp_second, tmp_third;

  while (0 == Serial.available()) ; // wait for some typing

  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    // look for the next valid integer in the incoming serial stream:
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
    DEBUG_PRINTLN(" Got the newline");

    *first = tmp_first;
    *second = tmp_second;
    *third = tmp_third;
  } // end while (Serial.available() > 0)
} // end get_3_int_values()

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// get_one_string() - get one string (no leading or trailing ' ' or '\t') then flush to '\n'
//
//    parameters: none
//    returns:    char * pointer to the string
//
// Reads from Serial, gets one string then flushes to '\n'.
// Does not return until the flush is complete.
// Maximum string length is 
//
#define MAX_STRING_LENGTH 20

char * get_one_string() {
  uint16_t one_string_end = 0; // points to zero at end of current string
  uint8_t str_start = FALSE;
  uint8_t str_end = FALSE;
  uint8_t str_done = FALSE;
  char inchar;
  static char one_string[MAX_STRING_LENGTH+1]; // only this routine can use it

  memset((void *)one_string, 0, NUMOF(one_string)); // clear buffer; good idea for zero-terminated strings
  while (TRUE) {
    // if there's any serial available, read it:
    if (Serial.available() > 0) {
      DEBUG_INPUT_PRINT(F("DBGIN ")); DEBUG_INPUT_PRINT(__func__);   DEBUG_INPUT_PRINT(F(" st=")); DEBUG_INPUT_PRINT(str_start);  DEBUG_INPUT_PRINT(F(" en=")); DEBUG_INPUT_PRINT(str_end); DEBUG_INPUT_PRINT(F(" dn=")); DEBUG_INPUT_PRINT(str_done); DEBUG_INPUT_PRINT(F(" line ")); DEBUG_INPUT_PRINTLN(__LINE__);
      inchar = (char) Serial.read();
      if ( !str_start ) { // if waiting for start of string
        if (' ' < inchar) {
          DEBUG_INPUT_PRINT(F("DBGIN ")); DEBUG_INPUT_PRINT(__func__);   DEBUG_INPUT_PRINT(F(" st=")); DEBUG_INPUT_PRINT(str_start);  DEBUG_INPUT_PRINT(F(" en=")); DEBUG_INPUT_PRINT(str_end); DEBUG_INPUT_PRINT(F(" dn=")); DEBUG_INPUT_PRINT(str_done); DEBUG_INPUT_PRINT(F(" line ")); DEBUG_INPUT_PRINTLN(__LINE__);
          one_string[one_string_end++] = inchar;
          str_start = TRUE;
        }
      } else if ( !str_end ) { // if waiting for string finish
        if (' ' < inchar) {
          DEBUG_INPUT_PRINT(F("DBGIN ")); DEBUG_INPUT_PRINT(__func__);   DEBUG_INPUT_PRINT(F(" st=")); DEBUG_INPUT_PRINT(str_start);  DEBUG_INPUT_PRINT(F(" en=")); DEBUG_INPUT_PRINT(str_end); DEBUG_INPUT_PRINT(F(" dn=")); DEBUG_INPUT_PRINT(str_done); DEBUG_INPUT_PRINT(F(" line ")); DEBUG_INPUT_PRINTLN(__LINE__);
          if (one_string_end < MAX_STRING_LENGTH) one_string[one_string_end++] = inchar;
          else str_end = TRUE;
        } else if ('\n' == inchar) {
          DEBUG_INPUT_PRINT(F("DBGIN ")); DEBUG_INPUT_PRINT(__func__);   DEBUG_INPUT_PRINT(F(" st=")); DEBUG_INPUT_PRINT(str_start);  DEBUG_INPUT_PRINT(F(" en=")); DEBUG_INPUT_PRINT(str_end); DEBUG_INPUT_PRINT(F(" dn=")); DEBUG_INPUT_PRINT(str_done); DEBUG_INPUT_PRINT(F(" line ")); DEBUG_INPUT_PRINTLN(__LINE__);DEBUG_INPUT_PRINT("DBGIN "); DEBUG_INPUT_PRINT(__func__);   DEBUG_INPUT_PRINT(" st="); DEBUG_INPUT_PRINT(str_start);  DEBUG_INPUT_PRINT(" en="); DEBUG_INPUT_PRINT(str_end); DEBUG_INPUT_PRINT(" dn="); DEBUG_INPUT_PRINT(str_done); DEBUG_INPUT_PRINT(" line "); DEBUG_INPUT_PRINTLN(__LINE__);
          str_end = TRUE;
          str_done = TRUE;
        } else {
          DEBUG_INPUT_PRINT(F("DBGIN ")); DEBUG_INPUT_PRINT(__func__);   DEBUG_INPUT_PRINT(F(" st=")); DEBUG_INPUT_PRINT(str_start);  DEBUG_INPUT_PRINT(F(" en=")); DEBUG_INPUT_PRINT(str_end); DEBUG_INPUT_PRINT(F(" dn=")); DEBUG_INPUT_PRINT(str_done); DEBUG_INPUT_PRINT(F(" line ")); DEBUG_INPUT_PRINTLN(__LINE__);DEBUG_INPUT_PRINT("DBGIN "); DEBUG_INPUT_PRINT(__func__);   DEBUG_INPUT_PRINT(" st="); DEBUG_INPUT_PRINT(str_start);  DEBUG_INPUT_PRINT(" en="); DEBUG_INPUT_PRINT(str_end); DEBUG_INPUT_PRINT(" dn="); DEBUG_INPUT_PRINT(str_done); DEBUG_INPUT_PRINT(" line "); DEBUG_INPUT_PRINTLN(__LINE__);
          str_end = TRUE;
        }
      } else { // flush the remaining
       DEBUG_INPUT_PRINT(F("DBGIN ")); DEBUG_INPUT_PRINT(__func__);   DEBUG_INPUT_PRINT(F(" st=")); DEBUG_INPUT_PRINT(str_start);  DEBUG_INPUT_PRINT(F(" en=")); DEBUG_INPUT_PRINT(str_end); DEBUG_INPUT_PRINT(F(" dn=")); DEBUG_INPUT_PRINT(str_done); DEBUG_INPUT_PRINT(F(" line ")); DEBUG_INPUT_PRINTLN(__LINE__);
        if ('\n' != inchar)
          while (!(Serial.read() == '\n')) ; // wait for the end of line
        str_done = TRUE;
      } // end if to process one character
    } // end if Serial.available
    if (str_done) break; // we got our string
  } // end while (TRUE)
  DEBUG_INPUT_PRINT(F("DBGIN ")); DEBUG_INPUT_PRINT(__func__);   DEBUG_INPUT_PRINT(F(" st=")); DEBUG_INPUT_PRINT(str_start);  DEBUG_INPUT_PRINT(F(" en=")); DEBUG_INPUT_PRINT(str_end); DEBUG_INPUT_PRINT(F(" dn=")); DEBUG_INPUT_PRINT(str_done); DEBUG_INPUT_PRINT(F(" line ")); DEBUG_INPUT_PRINTLN(__LINE__);
  return(one_string);
} // end get_one_string()

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// setup() - the setup function runs once when you press reset or power the board
//
//    parameters: none
//    returns:    none
//
// 
void setup() {

  // this serial communication is for general debug; set the USB serial port to 115,200 baud
  Serial.begin(115200);

  while (!Serial) {
    ; // note that ";" is a null code statement. Wait for serial port to connect.
  }
  
  Serial.println(""); // print a blank line in case there is some junk from power-on
  Serial.println(F("CforArduinoClass init..."));

  DEBUG_PRINT(F("\nNUMOF_DAD_JOKES ")); DEBUG_PRINTLN(NUMOF_DAD_JOKES); DEBUG_PRINTLN(F(""));

  // we are showing that we don't actually need a loop()
  int f, c; // fahrenheit and centigrade
  int first, increment, beyond_maximum; // temp loop parameters
  int j1, j2, j3; // joke parameters
  char * input_string;
  while (TRUE) { // loop forever
    Serial.println(F(""));

    Serial.println(F("Enter T (Temp), J (Joke), C (ChooseJoke), or A (AllJoke)"));
    input_string = get_one_string(); 
    Serial.print(F("You entered ")); Serial.println(input_string); Serial.println(F(""));
    if (('a' <= input_string[0]) && ('z' >= input_string[0])) input_string[0] -= 'a' - 'A';
    if ('T' == input_string[0]) {
      #define PRINT_MAX 30 // PRINT_MAX is the maximum number of temp loops to allow
      Serial.println(F("Enter start degF, end degF, and stride degF\n"));
      get_3_int_values(&first, &beyond_maximum, &increment);
      // constrain values to print something reasonable
      if (beyond_maximum > (first + (PRINT_MAX*increment))) {
        beyond_maximum = first + (PRINT_MAX*increment) + ((beyond_maximum-first)%increment);
        Serial.print(F("WARNING: PRINT_MAX exceeded, end degF adjusted to ")); Serial.println(beyond_maximum);
      } // end if
      DEBUG_PRINT(F("DEBUG first=")); DEBUG_PRINT(first); DEBUG_PRINT(F(" increment=")); DEBUG_PRINT(increment); DEBUG_PRINT(F(" beyond_maximum=")); DEBUG_PRINTLN(beyond_maximum);
      Serial.print(F("integer Fahrenheit and Centigrade computed \"for (degF = ")); Serial.print(first); Serial.print(F("; degF < ")); Serial.print(beyond_maximum); Serial.print(F("; degF += ")); Serial.print(increment); Serial.println(F(") {...}\""));
      DEBUG_PRINT(F("DEBUG f=")); DEBUG_PRINT(f = first); DEBUG_PRINT(F(" f < beyond_maximum=")); DEBUG_PRINTLN(f < beyond_maximum); 
      for (f = first; f < beyond_maximum; f += increment) {
        c = ((f - 32) * 5) / 9;
        Serial.print(F(" degF, degC: ")); Serial.print(f); Serial.print(", "); Serial.println(c);
      } // end Fahrenheit and Centigrade for loop
    } else if ('J' == input_string[0]) {
      Serial.print(CURRENT_DAD_JOKE+1); Serial.print(": "); Serial.println(DAD_JOKES[CURRENT_DAD_JOKE++]);
      if ((NUMOF_DAD_JOKES-1) < CURRENT_DAD_JOKE) CURRENT_DAD_JOKE = 0;
    } else if ('C' == input_string[0]) {
      Serial.print(F("Choose 3 Dad Joke nums separated by commas; max num = ")); Serial.println(NUMOF_DAD_JOKES);
      get_3_int_values(&j1, &j2, &j3);
      Serial.print(j1); Serial.print(": "); Serial.println(DAD_JOKES[max(min(j1,NUMOF_DAD_JOKES),1)-1]);
      Serial.print(j2); Serial.print(": "); Serial.println(DAD_JOKES[max(min(j2,NUMOF_DAD_JOKES),1)-1]);
      Serial.print(j3); Serial.print(": "); Serial.println(DAD_JOKES[max(min(j3,NUMOF_DAD_JOKES),1)-1]);
    } else if ('A' == input_string[0]) {
      for (j1 = 0; j1 < NUMOF_DAD_JOKES; j1 += 1) {
        Serial.print(j1+1); Serial.print(": "); Serial.println(DAD_JOKES[j1]);
      }
    } else {
      Serial.print(F("ERROR - ")); Serial.print(input_string); Serial.println(F(" is not a valid choice"));
    } // end if which command

  } // end while loop

} // end setup()

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// loop() - the loop function runs over and over again forever
//
//    parameters: none
//    returns:    none
//
// 

void loop() {
  // we are demonstrating we don't need the loop() function
  Serial.println(F("\n\nERROR - Running loop(); should never happen!\n\n"));
} // end loop()
