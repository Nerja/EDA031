#include <string>
#include "Date.h"
#include "mytemp.h"
#include <iostream>

using namespace std;

int main() {
  double d = 1.234;
  Date today;
  std::string sd = toString(d);
  cout << "Double toString: " << sd << endl;
  std::string st = toString(today);
  cout << "Date toString: " << st << endl;
}
