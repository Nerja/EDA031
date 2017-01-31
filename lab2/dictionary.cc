#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <sstream>

using namespace std;

Dictionary::Dictionary() {
	ifstream input("words.txt");
	if(!input) {
		cerr << "Cant find words.txt" << endl;
		exit(1);
	}
	
	string line;
	while(getline(input, line)) {		
		//Fill words
		istringstream iss(line);
		string word = "";
		iss >> word;
		words.insert(word);

		int f;
		iss >> f;
		vector<string> trigrams;
		string tri;		
		while(iss >> tri)
			trigrams.push_back(tri);
		Word w(word, trigrams);
		words_len[word.length()-1].push_back(w); 
	}
	input.close();
}

bool Dictionary::contains(const string& word) const {
	return words.find(word) != words.end();
}

void Dictionary::create_trigrams(vector<string>& trigrams, const string& word) const {
	if(word.length() >= 3) {
		// Make word lowercase
		string word_lower(word);
		transform(word_lower.begin(), word_lower.end(), word_lower.begin(), ::tolower);

		for(decltype(word_lower.length()) i = 0; i <= word_lower.length() - 3; i++)
			trigrams.push_back(word_lower.substr(i, 3));

		sort(trigrams.begin(), trigrams.end());
	}
}

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const {
	vector<string> trigrams;
	create_trigrams(trigrams, word);
	if(trigrams.size() > 0) {
		for(decltype(word.length()) i = word.length() - 1; i <= word.length() + 1; ++i) {
			for(Word w : words_len[i-1]) {
				if(w.get_matches(trigrams) >= trigrams.size() / 2) 
					suggestions.push_back(w.get_word());	
			}
		}
	}
}

int edit_distance(string sugg, string word) {
	int d[26][26];
	for(int k = 0; k < 26; k++) {
			d[k][0] = k;
			d[0][k] = k;
	}

	for(unsigned i = 1; i <= word.length(); i++) {
		for(unsigned j = 1; j <= sugg.length(); j++) {
			int c1 = (word[i-1] == sugg[j-1]) ? (d[i-1][j-1]) : (d[i-1][j-1] + 1);
			int c2 = d[i-1][j] + 1;
				int c3 = d[i][j-1] + 1;
			d[i][j] = min(min(c1, c2), c3);
		}
	}
	return d[word.length()][sugg.length()];
}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string& word) const {
	vector<pair<int, string>> v;
	for(string sugg : suggestions) 
		v.push_back(make_pair(edit_distance(sugg, word), sugg));	

	sort(v.begin(), v.end());

	suggestions.clear();
	for(pair<int, string> p : v) 
		suggestions.push_back(p.second);
}

void Dictionary::trim_suggestions(vector<string>& suggestions) const {
	suggestions.resize(5);
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}
