/*
 * Ds18b20.cpp
 *
 *  Created on: 01.06.2017
 *      Author: mik
 */

#include "Ds18b20.h"
#include "Utils.h"
#include <iostream>
#include <dirent.h>
#include <stddef.h>
#include <fstream>
#include <sstream>

namespace rpilibs {

const string Ds18b20::ONEWIRE_DEVICES_PATH = "/sys/bus/w1/devices/";
const string Ds18b20::ONEWIRE_DATA_FILE = "/w1_slave";

Ds18b20::Ds18b20() {
  cout << "Initializing DS18B20" << endl;
  id = "";

  DIR * onewireDirectory = opendir(ONEWIRE_DEVICES_PATH.c_str());
  if (onewireDirectory == NULL) {
    return;
  }

  struct dirent * directoryEntry;
  while (true) {
    directoryEntry = readdir(onewireDirectory);
    if (directoryEntry == NULL) {
      break;
    }
    if (checkSensorIdValidity(directoryEntry->d_name)) {
      id = directoryEntry->d_name;
      break;
    }
  }
  cout << "Device ID = " << id << endl;
  closedir(onewireDirectory);
}

Ds18b20::~Ds18b20() {

}

double Ds18b20::readTemperatureCelsius() {
  if (id == Utils::EMPTY_STRING) {
    return 0;
  }

  string filename = ONEWIRE_DEVICES_PATH + id + ONEWIRE_DATA_FILE;

  ifstream thermometerFile(filename.c_str());
  if (!thermometerFile.is_open()) {
    cout << "Unable to open file" << endl;
    return 0;
  }

  string crcLine;
  getline(thermometerFile, crcLine);
  const string YES_STRING = "YES";
  if (crcLine.find(YES_STRING) == string::npos) {
    cout << "CRC invalid" << endl;
    return 0;
  }

  string temperatureLine;
  getline(thermometerFile, temperatureLine);

  const string TEMPERATURE_STRING = "t=";
  string::size_type temperaturePosition = temperatureLine.find(TEMPERATURE_STRING);
  if (temperaturePosition == string::npos) {
    cout << "No temperature found" << endl;
    return 0;
  }
  string temperatureValue = temperatureLine.substr(temperaturePosition +
      TEMPERATURE_STRING.length());

  int rawTemperature;
  istringstream temperatureStream(temperatureValue);
  temperatureStream >> rawTemperature;
  thermometerFile.close();

  const double UNITS_TO_MILLIS = 1000.0;
  return rawTemperature/UNITS_TO_MILLIS;
}

bool Ds18b20::checkSensorIdValidity(const char * filename) {
  const char * DEVICE_FILE_REGEX = "28\\-[0-9a-fA-F]{4}";
  return Utils::checkRegexMatch(DEVICE_FILE_REGEX, filename);
}

} /* namespace rpilibs */


