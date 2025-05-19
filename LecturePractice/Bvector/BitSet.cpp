#include <iostream>
#include "BitSet.h"
using namespace std;

BitSet::BitSet(int sz): Bvector(sz) {

}

void BitSet::insert(int v) {
	Bvector::set(v);
}

BitSet& BitSet::operator+=(const BitSet& v) {
	for (int i = 0; i < NBITS; i++) {
          if (v.bit(i)) set(i);
	}
    return *this;
}

BitSet operator+(BitSet v1, const BitSet& v2) {
	v1 += v2;
    return v1;
}

ostream& operator<<(ostream& os, const BitSet& s) {
  	os << "{ ";
	for (int i = 0; i < s.NBITS; i++) {
          if (s.bit(i)) os << i << " ";
	}
    os << "}";
 	return os;
}