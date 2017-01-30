#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string process_word(string word) {
	vector<string> trigrams;
	if(word.length() >= 3) {
		// Make word lowercase
		transform(word.begin(), word.end(), word.begin(), ::tolower);

		// Load all trigrams
		for(decltype(word.length()) i = 0; i <= word.length() - 3; i++)
			trigrams.push_back(word.substr(i, 3));
		
		// Sort trigrams
		sort(trigrams.begin(), trigrams.end());
	}
	string trigrams_string = word + " ";
	trigrams_string += to_string(trigrams.size());
	for(string t : trigrams)
		trigrams_string += " " + t;
	return trigrams_string;
}

int main() {
	ifstream input("/usr/share/dict/words");
	if(!input) {
		cerr << "Cant open file" << endl;
		exit(1);
	}

	ofstream output("words.txt");
	if(!output) {
		cerr << "Cant write to file" << endl;
		exit(1);
	}
	
	string word;
	while(input >> word)
		output << process_word(word) << endl;

	input.close();
	output.close();
	cout << "Done" << endl;
	return 0;
}
