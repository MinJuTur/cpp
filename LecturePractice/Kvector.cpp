#include <iostream>
using namespace std;

class Kvector {
    int *m;
    int len;
  public:
    static int total_len;
    Kvector(int sz = 0, int value = 0);
    Kvector(const Kvector& v);
    ~Kvector() {
      total_len -= len;
      delete[] m;
    }

    Kvector& operator=(const Kvector& k);
  friend bool operator==(const Kvector& a, const Kvector& b);
  friend bool operator!=(const Kvector& a, const Kvector& b);
    int& operator[](int idx);
  friend ostream& operator<<(ostream& os, const Kvector& k);

    void print() const {
       for (int i = 0; i < len; i++) cout << m[i] << " ";
       cout << endl;
    }
    void clear() {
      delete[] m;
      m = NULL;
      total_len -= len;
      len = 0;
    }
    int size() const { return len; }
};
int Kvector::total_len = 0;
int main() {
  Kvector v1(3); v1.print();
  Kvector v2(2,9); v2.print();
  Kvector v3(v2); v3.print();
  cout << (v1 == v2) << endl;
  cout << (v3 == v2) << endl;
  v3 = v2 = v1;
  cout << v1 << endl;
  cout << v2 << endl;
  cout << v3 << endl;
  cout << (v3 != v2) << endl;
  v1[2] = 2;
  v2[0] = v1[2];
  cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
  return 0;
}
Kvector::Kvector(int sz, int value) {
  if (sz == 0) {
    m = nullptr;
    return;
  }
  len = sz;
  total_len += len;
  m = new int[len];
  for (int i = 0; i < len; i++) {
    m[i] = value;
  }
}

Kvector::Kvector(const Kvector& v) {
  len = v.size();
  total_len += len;
  m = new int[len];
  for (int i = 0; i < len; i++) {
    m[i] = v.m[i];
  }
}

Kvector& Kvector::operator=(const Kvector& v) {
  clear();
  len = v.size();
  m = new int[len];
  for (int i = 0; i < len; i++) {
    m[i] = v.m[i];
  }
  return *this;
}
bool operator==(const Kvector& a, const Kvector& b) {
  if (a.size() != b.size()) return false;
  for (int i = 0; i < a.size(); i++) {
    if (a.m[i] != b.m[i]) return false;
  }
  return true;
}
bool operator!=(const Kvector& a, const Kvector& b) {
  return !(a == b);
}
int& Kvector::operator[](int idx) {
  return m[idx];
}
ostream& operator<<(ostream& os, const Kvector& k) {
  for (int i = 0; i < k.size(); i++) os << k.m[i] << " ";
  return os;
}




