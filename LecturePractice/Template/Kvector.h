#include <iostream>
#ifndef __KVECTOR__
#define __KVECTOR__
using namespace std;

template <class T>
class Kvector;

template <class T>
class Kvector{
  protected:
    T *m;
    int len;
  public:
    Kvector(int sz = 0, T value = 0);
    Kvector(const Kvector& v);
  virtual ~Kvector();
  virtual void print() const { cout << "Kvector<T>\n"; }
    void clear() { delete[] m; m = NULL; len = 0; }
    int size() const { return len; }

  Kvector<T>& operator=(const Kvector<T>& v);
  T& operator[](int idx) { return m[idx]; }
  const T& operator[](int idx) const { return m[idx]; }

  T sum() const {
    if (len == 0) return T();
    T s = m[0];
    for (int i = 1; i < len; i++) s += m[i];
    return s;
  }

  template <class U>
  friend bool operator==(const Kvector<U>& v, const Kvector<U>& w);

  template <class U>
  friend bool operator!=(const Kvector<U>& v, const Kvector<U>& w);

  template <class U>
  friend ostream& operator<<(ostream& os, const Kvector<U>& v);
};

template <class T>
Kvector<T>::Kvector(int sz, T value): len(sz) {
  if (!sz) { m = NULL; return; }
  m = new T[sz];
  for (int i = 0; i < sz; i++) m[i] = value;
}
template <class T>
Kvector<T>::Kvector(const Kvector& v) {
  len = v.len;
  if (!len) { m = NULL; return; }
  m = new T[len];
  for (int i = 0; i < len; i++) m[i] = v.m[i];
}
template <class T>
Kvector<T>::~Kvector() {
  delete[] m;
}
template <class T>
Kvector<T>& Kvector<T>::operator=(const Kvector& v) {
    delete[] m;
    len = v.len;
    m = new T[len];
    for (int i = 0; i < len; i++) m[i] = v.m[i];
    return *this;
}
template <class T>
bool operator==(const Kvector<T>& v, const Kvector<T>& w) {
    if (v.size() != w.size()) return false;
    for (int i = 0; i < v.size(); i++) {
        if (v.m[i] != w.m[i]) return false;
    }
    return true;
}
template <class T>
bool operator!=(const Kvector<T>& v, const Kvector<T>& w) {
    return !(v == w);
}
template <class T>
ostream& operator<<(ostream& os, const Kvector<T>& v) {
    for (int i = 0; i < v.size(); i++) os << v.m[i] << " ";
    return os;
}
#endif
