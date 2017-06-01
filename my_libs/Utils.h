/*
 * Utils.h
 *
 *  Created on: 31.05.2017
 *      Author: mik
 */

#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_

#include <string>

using namespace std;

class Utils {
public:
  /**
   * @brief Delay milliseconds
   * @param millis Milliseconds to delay
   */
  static void delayMillis(int millis);
  static bool checkRegexMatch(const char * regularExpression, const char * data);
  static const string EMPTY_STRING;
};

#endif /* UTILS_UTILS_H_ */
