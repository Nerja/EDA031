#include "mytemp.h"
#include "date.h"
#include <iostream>

using namespace std;

int main() {
  try {
    int i = string_cast<int>("123");
    cout << "String cast at int: " << i << endl;
    double d = string_cast<double>("12.34");
    cout << "String cast at double: " << d << endl;
    Date date = string_cast<Date>("2015-01-10");
    cout << "String cast at date: " << date << endl;
    try{
      string_cast<Date>("2012-123-12");
      cout << "Wrong date was accepted, scheisse" << endl;
    } catch(std::invalid_argument& e) {
      cout << "Exception was raised for wrong date(good)" << endl;
    }
  } catch (std::invalid_argument& e) {
    cout << "Error: " << e.what() << endl;
  }
}
