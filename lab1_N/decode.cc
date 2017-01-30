#include <string>
#include <fstream>
#include "coding.h"
using namespace std;

int main(int argc, char** argv) {
	if (argc == 0)
    return 1;
	string file = argv[1];

	ifstream infile(file.c_str());
	ofstream outfile((file + ".dec").c_str());

	char c;
	while (true) {
		infile.get(c);
		if (!infile.good())
			break;
		outfile.put(Coding::decode(c));
	}

	infile.close();
	outfile.close();
}
