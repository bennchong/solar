#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

#include "util.h"
#include "log.h"

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ; // wait for serial
  delay(200);

  const int chipSelect = D8;
  init_log(chipSelect, "test.txt");
}

void loop()
{
  Serial.println(getTimeISO());
  printlog("test.txt");
  delay(5000);
}

// change this to match your SD shield or module;
// WeMos Micro SD Shield V1.0.0: D8
// LOLIN Micro SD Shield V1.2.0: D4 (Default)
// const int chipSelect = D8;

// File myFile;

// void setup() {
//   // Open serial communications and wait for port to open:
//   Serial.begin(9600);
//   while (!Serial) {
//     ; // wait for serial port to connect. Needed for Leonardo only
//   }

//   Serial.print("Initializing SD card...");

//   if (!SD.begin(chipSelect)) {
//     Serial.println("initialization failed!");
//     return;
//   }
//   Serial.println("initialization done.");

//   // open the file. note that only one file can be open at a time,
//   // so you have to close this one before opening another.
//   myFile = SD.open("test.txt", FILE_WRITE);

//   // if the file opened okay, write to it:
//   if (myFile) {
//     Serial.print("Writing to test.txt...");
//     myFile.println("testing 1, 2, 3.");
//     // close the file:
//     myFile.close();
//     Serial.println("done.");
//   } else {
//     // if the file didn't open, print an error:
//     Serial.println("error opening test.txt");
//   }

//   // re-open the file for reading:
//   myFile = SD.open("test.txt");
//   if (myFile) {
//     Serial.println("test.txt:");

//     // read from the file until there's nothing else in it:
//     while (myFile.available()) {
//       Serial.write(myFile.read());
//     }
//     // close the file:
//     myFile.close();
//   } else {
//     // if the file didn't open, print an error:
//     Serial.println("error opening test.txt");
//   }
// }

// void loop() {
//   // nothing happens after setup
// }

// #include <Wire.h>
// #include <TimeLib.h>
// #include <DS1307RTC.h>

// void print2digits(int number) {
//   if (number >= 0 && number < 10) {
//     Serial.write('0');
//   }
//   Serial.print(number);
// }

// void setup() {
//   Serial.begin(9600);
//   while (!Serial)
//     ; // wait for serial
//   delay(200);
//   Serial.println("DS1307RTC Read Test");
//   Serial.println("-------------------");
// }

// void loop() {
//   tmElements_t tm;

//   if (RTC.read(tm)) {
//     Serial.print("Ok, Time = ");
//     print2digits(tm.Hour);
//     Serial.write(':');
//     print2digits(tm.Minute);
//     Serial.write(':');
//     print2digits(tm.Second);
//     Serial.print(", Date (D/M/Y) = ");
//     Serial.print(tm.Day);
//     Serial.write('/');
//     Serial.print(tm.Month);
//     Serial.write('/');
//     Serial.print(tmYearToCalendar(tm.Year));
//     Serial.println();
//   } else {
//     if (RTC.chipPresent()) {
//       Serial.println("The DS1307 is stopped.  Please run the SetTime");
//       Serial.println("example to initialize the time and begin running.");
//       Serial.println();
//     } else {
//       Serial.println("DS1307 read error!  Please check the circuitry.");
//       Serial.println();
//     }
//     delay(9000);
//   }
//   delay(1000);
// }
