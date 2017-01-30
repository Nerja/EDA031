
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  //ifstream fin("/usr/share/dict/words");
  ifstream fin("words");
  ofstream fout("words.txt");

  string line;

  while (getline(fin, line)) {
    transform(line.begin(), line.end(), line.begin(), ::tolower);
    vector<string> trigrams;

    if (line.size() > 3) {
      unsigned int count;
      for (count = 0; count <= line.size() - 3; ++count) {
        trigrams.push_back(line.substr(count, 3));
      }

      sort(trigrams.begin(), trigrams.end());

      fout << line << " " << count;
      for (auto it = trigrams.begin(); it != trigrams.end(); ++it) {
        fout << " " << *it;
      }

      fout << endl;
    } else {
      fout << line << " 0" << endl;
    }
  }
}
