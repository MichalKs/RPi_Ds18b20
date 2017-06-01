/*
 * Utils.cpp
 *
 *  Created on: 31.05.2017
 *      Author: mik
 */

#include <Utils.h>
#include <unistd.h>

void Utils::delayMillis(int millis) {
  const int MILLIS_TO_MICROS = 1000;
  usleep(millis * MILLIS_TO_MICROS);
}
