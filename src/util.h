#ifndef UTIL_H
#define UTIL_H

#include <Arduino.h>
#include <string.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

String getTimeISO();

void setTime();

#endif
