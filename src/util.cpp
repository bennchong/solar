
#include "util.h"

String print2digits(int number)
{
  String input;
  if (number >= 0 && number < 10)
  {
    input += '0';
  }
  input += String(number);

  return input;
}

String getTimeISO()
{
  tmElements_t tm;
  String res;

  if (RTC.read(tm))
  {
    res += String(tmYearToCalendar(tm.Year));
    res += '-';

    res += String(tm.Month);
    res += '-';

    res += String(tm.Day);
    res += '-';

    res += 'T';

    res += print2digits(tm.Hour);
    res += ':';

    res += print2digits(tm.Minute);
    res += ':';

    res += print2digits(tm.Second);
  }
  else
  {
    if (RTC.chipPresent())
    {
      res += "Run Settime to initialize time";
    }
    else
    {
      res += "DS1307 read error!  Please check the circuitry.";
    }
  }

  return res;
}

const char *monthName[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                             "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

tmElements_t tm;

bool getTime(const char *str)
{
  int Hour, Min, Sec;

  if (sscanf(str, "%d:%d:%d", &Hour, &Min, &Sec) != 3)
    return false;
  tm.Hour = Hour;
  tm.Minute = Min;
  tm.Second = Sec;
  return true;
}

bool getDate(const char *str)
{
  char Month[12];
  int Day, Year;
  uint8_t monthIndex;

  if (sscanf(str, "%s %d %d", Month, &Day, &Year) != 3)
    return false;
  for (monthIndex = 0; monthIndex < 12; monthIndex++)
  {
    if (strcmp(Month, monthName[monthIndex]) == 0)
      break;
  }
  if (monthIndex >= 12)
    return false;
  tm.Day = Day;
  tm.Month = monthIndex + 1;
  tm.Year = CalendarYrToTm(Year);
  return true;
}

void setTime()
{
  bool parse = false;
  bool config = false;

  // get the date and time the compiler was run
  if (getDate(__DATE__) && getTime(__TIME__))
  {
    parse = true;
    // and configure the RTC with this info
    if (RTC.write(tm))
    {
      config = true;
    }
  }
  if (parse && config)
  {
    Serial.print("DS1307 configured Time=");
    Serial.print(__TIME__);
    Serial.print(", Date=");
    Serial.println(__DATE__);
  }
  else if (parse)
  {
    Serial.println("DS1307 Communication Error :-{");
    Serial.println("Please check your circuitry");
  }
  else
  {
    Serial.print("Could not parse info from the compiler, Time=\"");
    Serial.print(__TIME__);
    Serial.print("\", Date=\"");
    Serial.print(__DATE__);
    Serial.println("\"");
  }
}