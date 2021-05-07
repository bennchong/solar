#ifndef LOG_H
#define LOG_H

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

void init_log(int chipSelect, String fileName);
void log(String message);
void printlog(String fileName);

#endif