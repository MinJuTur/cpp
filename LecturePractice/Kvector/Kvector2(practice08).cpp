//
// 실습 06에서 구현한 Kvector class 에 대하여 main() 함수를 다음과 같이 변경하면 compile error 가 발생한다.
// (1) compile error 가 없도록 class 멤버 함수들을 수정하라.
// (2) 프로그램이 수행되는 동안 생성되는 Kvector 객체들에 저장된 m 배열의 원소 갯수들의 총합을 저장하는 static member 변수 total_len 을 선언하고 생성자와 소멸자를 수정하라.
//

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
    void print() const {
        for (int i = 0; i < len; i++) cout << m[i] << " ";
        cout << endl;
    }
    void clear() {
        delete[] m;
        m = nullptr;
        total_len -= len;
        len = 0;
    }
    int size() const { return len; }
};
int Kvector::total_len = 0;
int main() {
    Kvector v1(3); v1.print();
    const Kvector v2(2,9); v2.print();
    Kvector v3(v2); v3.print();
    Kvector *p = new Kvector(3, 10); p->print();

    cout << "total length : " << Kvector::total_len << endl;
    delete p;
    cout << "total length after deletion : " << Kvector::total_len << endl;
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
