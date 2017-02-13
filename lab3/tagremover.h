#include <iostream>
#include <string>
#ifndef TAGREMOVER_H
#define TAGREMOVER_H

class TagRemover {
  public:
      TagRemover(std::istream& cin);
      void print(std::ostream& cout);
  private:
      std::string parsed;
};

#endif
