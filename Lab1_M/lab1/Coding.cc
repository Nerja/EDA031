#include "Coding.h"

const int magic_number = 1;

unsigned char encode(unsigned char c) {
	return c + magic_number;
}

// decode(encode(c)) = c
unsigned char decode(unsigned char c) {
	return c - magic_number;
}
