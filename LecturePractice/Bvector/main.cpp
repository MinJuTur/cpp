//
//Bvector 를 상속하여 0~N-1 의 숫자들 중 일부를 원소로 갖는 BitSet class 를 만들어 컴파일하고 수행하라.
//1)N을 인자로 갖는 생성자: 생성된 집합 객체는 공집합을 표현한다.
//2) i 를 집합의 원소로 추가하는 insert() 멤버 함수를 구현하라.
//3)합집합 연산자(operator+=) 를 member 함수로 구현하라.
//4)operator+= 를 이용하여 합집합 연산자(operator+) 를 friend 함수로 구현하라.
//5)출력 연산자(operator<< )를 friend 함수로 구현하라.
//다음의 main() 함수에 대한 출력이 제시된 바와 같아야 한다.
//

#include <iostream>
#include "BitSet.h"
using namespace std;

int main(int argc, char *argv[]) {
  BitSet b1(131), b2(131);
  b1.insert(3); b1.insert(5); b1.insert(8);
  b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
  b1.print(); b2.print();
  cout << "b1= " << b1 << endl;
  cout << "b2= " << b2 << endl;
  cout << "b1+b2= " << b1+b2 << endl;
}
