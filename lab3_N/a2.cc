#include "sieve.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
  find_primes(1000);
  find_primes(100000);
}

void find_primes(int m) {
  string p_str = string(m+1, 'P');
  p_str[0] = 'C';
  p_str[1] = 'C';
  int p = 2;
  while(p * p <= m){
    int j = p * p;
    while(j <= m) {
      p_str[j] = 'C';
      j += p;
    }
    while(p_str[++p] == 'C') {}
  }
  cout << "Largest Prime: " << p_str.find_last_of('P') << endl;
  cout << "Primes before " << (m > 200 ? 200 : m) << ": ";
  for(int i = 0; i <= (m > 200 ? 200 : m); ++i) {
    if(p_str[i] == 'P') {
      cout << i << ", ";
    }
  }
  cout << endl;
}
