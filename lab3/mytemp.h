#ifndef MYTEMP_H
#define MYTEMP_H
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

template<typename T>
std::string toString(const T& obj) {
  std::ostringstream output;
  output << obj;
  return output.str();
}

template<typename T>
T string_cast(std::string s) {
  std::istringstream iss(s);
  T obj;
  iss >> obj;
  if(iss.fail())
    throw std::invalid_argument("cant be converted");
  return obj;
}
#endif
