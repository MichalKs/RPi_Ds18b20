/*
 * Ds18b20.cpp
 *
 *  Created on: 01.06.2017
 *      Author: mik
 */

#include <Ds18b20.h>
#include <iostream>
#include <dirent.h>
#include <stddef.h>
#include <regex.h>

namespace rpilibs {

const string Ds18b20::ONEWIRE_DEVICES_PATH = "/sys/bus/w1/devices/";

Ds18b20::Ds18b20() {
  cout << "Initializing DS18B20" << endl;

  DIR * onewireDirectory = opendir(ONEWIRE_DEVICES_PATH.c_str());
  if (onewireDirectory == NULL) {
    id = 0;
    return;
  }

  struct dirent * directoryEntry;
  while (true) {
    directoryEntry = readdir(onewireDirectory);
    if (directoryEntry == NULL) {
      break;
    }
    cout << "Filename: " << directoryEntry->d_name << endl;
    if (checkSensorIdValidity(directoryEntry->d_name)) {
      // Is a valid sensor ID
    }
  }

  closedir(onewireDirectory);
}

Ds18b20::~Ds18b20() {

}

double Ds18b20::readTemperatureCelsius() {

  return 0;
}

bool Ds18b20::checkSensorIdValidity(const char * filename) {

  return true;
}

} /* namespace rpilibs */


