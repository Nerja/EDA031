#include <iostream>
#include <sstream>
#include <stdexcept>
#include "date.h"

using namespace std;

template <typename T>
T string_cast(std::string str) {
  T result;
  istringstream iss(str);
  if (iss >> result)
    return result;

  throw std::invalid_argument("Invalid");
}

int main() {
  try {
    int i = string_cast<int>("123");
    double d = string_cast<double>("12.34");
    Date date = string_cast<Date>("2015-01-10");
    //Date date_err = string_cast<Date>("2015-0x-10");
    cout << i << endl;
    cout << d << endl;
    cout << date << endl;
  } catch (invalid_argument& e) {
    cout << "Error: " << e.what() << endl;
  }
}
