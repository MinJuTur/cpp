#include <iostream>
#include "Bvector.h"

class BitSet : public Bvector {
  public:
    BitSet(int sz = 32);
  void insert(int v);
  BitSet& operator+=(const BitSet& v);
  friend BitSet operator+(BitSet v1, const BitSet& v2);
  friend std::ostream& operator<<(std::ostream& os, const BitSet& s);
};