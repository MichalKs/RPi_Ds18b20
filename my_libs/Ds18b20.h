/*
 * Ds18b20.h
 *
 *  Created on: 01.06.2017
 *      Author: mik
 */

#ifndef MY_LIBS_DS18B20_H_
#define MY_LIBS_DS18B20_H_

#include <string>

using namespace std;

namespace rpilibs {

class Ds18b20 {
public:
  Ds18b20();
  virtual ~Ds18b20();
  double readTemperatureCelsius();


private:
  bool checkSensorIdValidity(const char * filename);
  int id;
  static const string ONEWIRE_DEVICES_PATH;
};

} /* namespace rpilibs */

#endif /* MY_LIBS_DS18B20_H_ */
