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
  /**
   * @brief Constructor for sensor. Gets sensor ID from list of devices on bus.
   */
  Ds18b20();
  virtual ~Ds18b20();
  /**
   * @brief Reads temperature in degress Celsius
   * @return Temperature in Celsius
   */
  double readTemperatureCelsius();

private:
  /**
   * @brief Checks if filename corresponds to sensor ID
   * @param filename File name to check
   * @retval true File name corresponds to device ID
   * @retval false File name does not correspond to device ID
   */
  bool checkSensorIdValidity(const char * filename);
  string id; ///< ID of sensor
  static const string ONEWIRE_DEVICES_PATH; ///< Path to onewire devices
  static const string ONEWIRE_DATA_FILE;    ///< Data file for thermometer
};

} /* namespace rpilibs */

#endif /* MY_LIBS_DS18B20_H_ */
