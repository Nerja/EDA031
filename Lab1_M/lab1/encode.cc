#include "Coding.h"
#include <iostream>
#include <fstream>

using namespace std;

void encode_file(char* file) {
	ifstream input(file);
	string outputFile(file);
	outputFile += ".enc";
	ofstream output(outputFile);
	if(!input || !output) {
		cerr << "Could not open " << file << " or write to "
		"output file, goodbye!" << endl;
		exit(1);	
	}
	char ch;
	while(input.get(ch)) 
		output << encode(ch);
	
	input.close();
	output.close();
}

int main(int argc, char* argv[]) {
	if(argc == 2) {
		encode_file(argv[1]);
		return 0;
	} else {
		cout << "The format is ./encode file" << endl;
		return -1;
	}
}
