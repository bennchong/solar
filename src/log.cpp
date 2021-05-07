#include "log.h"
#include "util.h"

File mySDCard;

void init_log(int chipSelect, String fileName)
{
  if (!SD.begin(chipSelect))
  {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  mySDCard = SD.open(fileName, FILE_WRITE);
}

void log(String message)
{
  mySDCard.print(getTimeISO());
  mySDCard.print(',');
  mySDCard.print(message);
}

void printlog(String fileName)
{
  mySDCard = SD.open(fileName);
  if (mySDCard)
  {
    Serial.println(fileName + " :");

    // read from the file until there's nothing else in it:
    while (mySDCard.available())
    {
      Serial.write(mySDCard.read());
    }
    // close the file:
    mySDCard.close();
  }
  else
  {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}