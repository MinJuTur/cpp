//
//Kvector class 를 상속하여 Avector class 를 만들어라.
//•Kvector class 의 멤버 변수는 protected 로 선언하라.
//•Avector class 는 table 라는 문자 배열을 member 변수로 가지는데 그 원소들은 각각 0,1,2 의 값에 대응되는 영어 알파벳이다.
//•Avector 의 생성자는 table 의 초기값을 문자열 상수 인자로부터 초기화한다.
//•Avector 의 member function setTable() 함수는 table 의 내용을 변경한다.
//•Avector 의 객체를 출력할 때는 m 배열의 원소들을 3으로 나눈 나머지를 0,1,2 대신에 table 배열에서 이에 해당하는 알파벳이 출력되어야 한다.
//

#include <iostream>
#define N 3
using namespace std;

class Kvector {
protected:
  int *m;
  int len;
public:
  Kvector(int sz = 0, int value = 0) {
    if (sz == 0) {
      m = nullptr;
      return;
    }
    len = sz;
    m = new int[len];
    for (int i = 0; i < len; i++) {
      m[i] = value;
    }
  };
  Kvector(const Kvector& v) {
    len = v.size();
    m = new int[len];
    for (int i = 0; i < len; i++) {
      m[i] = v.m[i];
    }
  };
  ~Kvector() { delete[] m; }

  void print() const {
    for (int i = 0; i < len; i++) cout << m[i] << " ";
    cout << endl;
  }
  void clear() {
    delete[] m;
    m = NULL;
    len = 0;
  }
  int size() const { return len; }

  Kvector& operator=(const Kvector& v);
  friend bool operator==(const Kvector& v, const Kvector& w);
  friend bool operator!=(const Kvector& v, const Kvector& w);
  int& operator[](int idx) { return m[idx]; }
  const int& operator[](int idx) const { return m[idx]; }
  friend ostream& operator<<(ostream& os, const Kvector& v);
};

Kvector& Kvector::operator=(const Kvector& v) {
  clear();
  len = v.size();
  m = new int[len];
  for (int i = 0; i < len; i++) {
    m[i] = v.m[i];
  }
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
ostream& operator<<(ostream& os, const Kvector& k) {
  for (int i = 0; i < k.size(); i++) os << k.m[i] << " ";
  return os;
}


class Avector: public Kvector {
   char table[N];
  public:
    Avector(int sz = 0, int v = 0, const char *t = "abc"): Kvector(sz, v) { setTable(t); }
    void setTable(const char *t) {
      for (int i = 0; i < 3; i++) {
        table[i] = t[i];
      }
    }
  friend ostream& operator<<(ostream& os, const Avector& v);
};

ostream& operator<<(ostream& os, const Avector& v) {
  for (int i = 0; i < v.len; i++) {
    int idx = v.m[i] % 3;
    os << v.table[idx] << " ";
  }
  return os;
}



int main() {
  Avector v1(3); v1.print();
  Avector v2(2,1,"xyz"); v2.print();
  Avector v3(v2); v3.print();
  cout << "v1 == v2 " << (v1 == v2) << endl;
  cout << "v3 == v2 " << (v3 == v2) << endl;
  v3 = v2 = v1;
  cout << "v1: " << v1 << endl;
  v1.print();
  cout << "v2: " << v2 << endl;
  v2.print();
  cout << "v3: " << v3 << endl;
  v3.print();
  cout << "v3 != v2 " << (v3 != v2) << endl;
  v1[2] = 2;
  v2[0] = v1[2];
  v1.setTable("pqr");
  cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
  v1.print();
  v2.print();
  v3.print();
  return 0;
}
