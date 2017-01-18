#include <fstream>
#include <iostream>
#include "Coding.h"

using namespace std;

void decode_file(char* file) {
	string inputFile(file);
	inputFile += ".enc";
	ifstream input(inputFile);
	
	string outputFile(file);
	outputFile += ".dec";
	ofstream output(outputFile);
	
	if(!input || !output) {
		cerr << "Failed with file operations " << endl;
		exit(1);	
	}

	char ch;
	while(input.get(ch)) 
		output.put(decode(ch));

	output.close();
	input.close();
}

int main(int argc, char* argv[]) {
	if(argc == 2) {
		decode_file(argv[1]);
		return 0;
	} else {
		cerr << "dude" << endl; 
		return -1;
	}
}
