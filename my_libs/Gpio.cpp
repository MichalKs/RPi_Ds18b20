/**
 * @file    GPIO.cpp
 * @brief	  GPIO pin class
 * @date    27 gru 2014
 * @author  Michal Ksiezopolski
 *
 *
 * @verbatim
 * Copyright (c) 2014 Michal Ksiezopolski.
 * All rights reserved. This program and the
 * accompanying materials are made available
 * under the terms of the GNU Public License
 * v3.0 which accompanies this distribution,
 * and is available at
 * http://www.gnu.org/licenses/gpl.html
 * @endverbatim
 */

#include "Gpio.h"
#include "wiringPi.h"

bool Gpio::initialized = false;

Gpio::Gpio(int pinNumber, PinDirection pinDirection) {
  // initialize library only once at start of program
  if (!initialized) {
    wiringPiSetupGpio();
    initialized = true;
  }
  this->pinNumber = pinNumber;
  this->pinDirection = pinDirection;
  pinMode(pinNumber, pinDirection);
}

Gpio::~Gpio() {
  pinMode(pinNumber, DIRECTION_INPUT);
}

void Gpio::toggle() {
  int pinValue = read();
  set(!pinValue);
}

bool Gpio::read() {
  return digitalRead(pinNumber);
}

void Gpio::set(bool newState) {
  digitalWrite(pinNumber, newState);
}
