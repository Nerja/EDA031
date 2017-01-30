#include "coding.h"

unsigned char Coding::encode(unsigned char c){
  return c + 5;
}

unsigned char Coding::decode(unsigned char c){
  return c - 5;
}
