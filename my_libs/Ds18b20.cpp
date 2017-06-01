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
  string dataLine;
  ifstream thermometerFile(filename.c_str());
  if (thermometerFile.is_open()) {
    while (getline(thermometerFile, dataLine)) {
      cout << dataLine << endl;
    }
    thermometerFile.close();
  } else {
    cout << "Unable to open file" << endl;
  }

  return 22.1;
}

bool Ds18b20::checkSensorIdValidity(const char * filename) {
  const char * DEVICE_FILE_REGEX = "28\\-[0-9a-fA-F]{4}";
  return Utils::checkRegexMatch(DEVICE_FILE_REGEX, filename);
}

} /* namespace rpilibs */


