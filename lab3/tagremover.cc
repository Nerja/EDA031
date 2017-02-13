#include <iostream>
#include <string>
#include "tagremover.h"
#include <regex>

using namespace std;

TagRemover::TagRemover(istream& in) {
  string line;
  while(getline(in, line))
    parsed += line += "\n";

  //Remove tags
  parsed = regex_replace(parsed, regex("<[^<]*>"), "");

  //Subs encoding
  parsed = regex_replace(parsed, regex("&lt;"), "<");
  parsed = regex_replace(parsed, regex("&gt;"), ">");
  parsed = regex_replace(parsed, regex("&nbsp;"), " ");
  parsed = regex_replace(parsed, regex("&amp;"), "&");
}

void TagRemover::print(ostream& out) {
  out << parsed;
}
