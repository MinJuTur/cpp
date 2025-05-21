#include <iostream>
#include "Kvector.h"
using namespace std;

Kvector::Kvector(int sz, int value): len(sz) {
  if (!sz) { m = NULL; return; }
  m = new int[sz];
  for (int i = 0; i < sz; i++) m[i] = value;
}

Kvector::Kvector(const Kvector& v) {
  len = v.len;
  if (!len) { m = NULL; return; }
  m = new int[len];
  for (int i = 0; i < len; i++) m[i] = v.m[i];
}

Kvector::~Kvector() {
  delete[] m;
}

Kvector& Kvector::operator=(const Kvector& v) {
    delete[] m;
    len = v.len;
    m = new int[len];
    for (int i = 0; i < len; i++) m[i] = v.m[i];
    return *this;
}
bool operator==(const Kvector& v, const Kvector& w) {
    if (v.size() != w.size()) return false;
    for (int i = 0; i < v.size(); i++) {
        if (v.m[i] != w.m[i]) return false;
    }
    return true;
}
bool operator!=(const Kvector& v, const Kvector& w) {
    return !(v == w);
}
ostream& operator<<(ostream& os, const Kvector& v) {
    for (int i = 0; i < v.size(); i++) os << v.m[i] << " ";
    return os;
}
