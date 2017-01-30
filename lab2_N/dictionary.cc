#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {
	//ifstream fin("/usr/share/dict/words");
	ifstream fin("words");
	string line;

	while (getline(fin, line)) {
		dictionary.insert(line);

		if (line.size() > 3) {
			vector<string> trigrams;

			for (unsigned int count = 0; count <= line.size() - 3; ++count) {
				trigrams.push_back(line.substr(count, 3));
			}

			sort(trigrams.begin(), trigrams.end());

			Word w = Word(line, trigrams);
			words[line.size() - 1].push_back(w);
		}
	}
}

bool Dictionary::contains(const string& word) const {
	return dictionary.count(word) > 0;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const {
	vector<string> trigrams;

	if (word.size() >= 3) {
		for (unsigned int i = 0; i <= word.size() - 3; ++i) {
			trigrams.push_back(word.substr(i, 3));
		}
		sort(trigrams.begin(), trigrams.end());

		// Only check words that are -2 and +1 in size
		for (unsigned int i = word.size() - 2; i <= word.size(); ++i) {
			for (Word w : words[i]) {
				if (w.get_matches(trigrams) >= trigrams.size() / 2) {
					suggestions.push_back(w.get_word());
				}
			}
		}
	}
}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string& word) const {
	int d[26][26];
  d[0][0] = 0;
  for (unsigned int i = 1; i <= 25; i++) d[i][0] = i;
  for (unsigned int j = 1; j <= 25; j++) d[0][j] = j;

  const size_t len1 = word.size();
  vector<pair<int, string> > ranked_suggestions;

  for (unsigned int suggested_place = 0; suggested_place < suggestions.size();
       suggested_place++) {
    const string& p = suggestions[suggested_place];
    const size_t len2 = p.size();

    for (unsigned int i = 1; i <= len1; ++i) {
      for (unsigned int j = 1; j <= len2; ++j) {
        d[i][j] = min({d[i - 1][j] + 1, d[i][j - 1] + 1,
                            d[i - 1][j - 1] + (p[i] == word[j] ? 0 : 1)});
      }
    }

    ranked_suggestions.push_back(make_pair(d[len1][len2], p));
  }

  auto compare = [](pair<int, string> p1,
                    pair<int, string> p2) {
    return p1.first < p2.first;
  };
  sort(ranked_suggestions.begin(), ranked_suggestions.end(), compare);
  suggestions.clear();

  auto second = [](const pair<int, string>& p) { return p.second; };
  transform(ranked_suggestions.begin(), ranked_suggestions.end(),
            back_inserter(suggestions), second);
}

void Dictionary::trim_suggestions(vector<string>& suggestions) const {
	if(suggestions.size() > 5) {
		suggestions.resize(5);
		suggestions.shrink_to_fit();
	}
}
