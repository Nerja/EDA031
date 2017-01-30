#include <string>
#include <vector>
#include "word.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t) : word(w), trigrams(t) {}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	unsigned int found = 0;

	unsigned int t_index = 0;
	unsigned int this_index = 0;

	while(t_index < t.size() && this_index < trigrams.size()){
		if(t.at(t_index) == trigrams.at(this_index)){
			++found;
			++t_index;
			++this_index;
		}
		else if(t.at(t_index) < trigrams.at(this_index)){
			t_index++;
		}
		else {
			this_index++;
		}
	}

	return found;
}
