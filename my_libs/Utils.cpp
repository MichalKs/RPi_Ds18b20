/*
 * Utils.cpp
 *
 *  Created on: 31.05.2017
 *      Author: mik
 */

#include "Utils.h"
#include <iostream>
#include <unistd.h>
#include <regex.h>

const string Utils::EMPTY_STRING = "";

void Utils::delayMillis(int millis) {
  const int MILLIS_TO_MICROS = 1000;
  usleep(millis * MILLIS_TO_MICROS);
}

bool Utils::checkRegexMatch(const char * regex, const char * data) {
  const int BUFFER_LENGTH = 100;
  char messageBuffer[BUFFER_LENGTH];
  bool returnValue = false;
  regex_t regularExpression;
  int result;

  // Compile regular expression
  result = regcomp(&regularExpression, regex, REG_EXTENDED);
  if (result) {
    cout << "Could not compile regex" << endl;
    return false;
  }

  // Execute regular expression
  const int FLAGS_NULL = 0;
  const int NUMBER_OF_MATCHES_TO_FIND = 0;
  result = regexec(&regularExpression, data, NUMBER_OF_MATCHES_TO_FIND,
      NULL, FLAGS_NULL);
  if (result == 0) {
    returnValue = true;
  } else if (result == REG_NOMATCH) {
    returnValue = false;
  } else {
    regerror(result, &regularExpression, messageBuffer, sizeof(messageBuffer));
    cout << "Regex match failed: " << messageBuffer << endl;
    returnValue = false;
  }

  // Free memory allocated to the pattern buffer by regcomp()
  regfree(&regularExpression);

  return returnValue;
}
