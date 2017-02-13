#ifndef TAGREMOVER_H
#define TAGREMOVER_H

#include<iostream>
#include<string>

class TagRemover {

public:
  TagRemover(std::istream &in);
  void print(std::ostream &out);
private:
  std::string data;
};


#endif
