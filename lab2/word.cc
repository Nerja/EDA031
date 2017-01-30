#include <string>
#include <vector>
#include "word.h"
#include <iostream>

using namespace std;

Word::Word(const string& w, const vector<string>& t) : word(w), trigrams(t) {}
	
string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int nbr_matches = 0;
	
	auto my_itr = trigrams.begin();
	auto my_e = trigrams.end();
	auto t_itr = t.begin();
	auto t_e = t.end();

	while(my_itr != my_e && t_itr != t_e) {
		if(*my_itr == *t_itr) {
			nbr_matches++;
			my_itr++;
			t_itr++;
		} else if(*my_itr < *t_itr) {
			my_itr++; // Move my_itr
		} else {
			t_itr++;  // Move t_itr
		}
	}
	return nbr_matches;
}
