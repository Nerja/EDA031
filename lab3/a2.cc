#include <string>
#include <iostream>

using namespace std;

int main() {
  int M = 100000;

  //Init with P
  string enumeration(M+1, 'P');

  //0& 1 not prime
  enumeration[0] = 'C';
  enumeration[1] = 'C';
  for(int marker = 2; marker < M+1; ++marker) {
    while(marker != M+1 && enumeration[marker] != 'P')
      ++marker;
    int k = 2;
    while(marker*k < M+1) {
      enumeration[marker*k] = 'C';
      k++;
    }
  }
  for(decltype(enumeration.size()) i = 1; i <= 200; i++)
    if(enumeration[i] == 'P')
      cout << i << endl;
  cout << "Last: " << enumeration.find_last_of('P') << endl;
}
