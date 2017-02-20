#include "bitset.h"
#include "bitreference.h"
#include "bitsetiterator.h"

Bitset::Bitset() : bits(0) {}

size_t Bitset::size() const {
	return BPW;
}

bool Bitset::operator[](size_t pos) const {
	BitStorage const_bits = bits; //Make copy since we may not change bits
	return BitReference(&const_bits, pos);
}

BitReference Bitset::operator[](size_t pos) {
	return BitReference(&bits, pos);
}


Bitset::iterator Bitset::begin() {
	return BitsetIterator(&bits, 0);
}

Bitset::iterator Bitset::end() {
	return BitsetIterator(&bits, BPW); //Indexing 0..BPW-1. end points to BPW one past
																		 //BPW-1
}
