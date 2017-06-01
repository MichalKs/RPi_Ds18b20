/**
 * @file    GPIO.h
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
#ifndef GPIO_H_
#define GPIO_H_

/**
 * @brief Class for GPIO pin
 */
class Gpio {

public:
  enum PinDirection {
    DIRECTION_INPUT = 0,
    DIRECTION_OUTPUT = 1,
  };

  /**
   * @brief Constructor for GPIO pin
   * @param pinNumber Pin number (pin numbers as per BCM numbering scheme)
   * @param pinDirection Pin direction
   */
  Gpio(int pinNumber, PinDirection pinDirection);
  /**
   * @brief Destructor (sets pin as input)
   */
  virtual ~Gpio();
  /**
   * @brief Toggle pin value
   */
  void toggle();
  /**
   * @brief Read pin value
   * @return Value of pin (true or false)
   */
  bool read();
  /**
   * @brief Set pin value
   * @param newState New pin value
   */
  void set(bool newState);

private:
  static bool initialized;    ///< Is low level library initialized
  int pinNumber;              ///< Pin number
  PinDirection pinDirection;  ///< Pin direction
};

#endif /* GPIO_H_ */
