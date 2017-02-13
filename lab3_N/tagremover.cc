#include "tagremover.h"
#include <iostream>
#include <regex>
#include <string>

using namespace std;

TagRemover::TagRemover(istream& cin) {
  string line;
  while(getline(cin, line)) {
    data.append(line.append("\n"));
  }
 data = regex_replace(data, regex("<[^<]*>"), "");
 data = regex_replace(data, regex("&lt;"), "<");
 data = regex_replace(data, regex("&gt;"), ">");
 data = regex_replace(data, regex("&nbsp;"), " ");
 data = regex_replace(data, regex("&amp;"), "&");
}

void TagRemover::print(ostream& cout) {
  cout << data;
}
