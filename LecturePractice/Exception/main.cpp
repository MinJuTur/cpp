//
//•BitSet class 의 operator+=() 함수에서 두 operands 의 최대 원소 갯수 (NBITS) 이 다르면 IncompatibleException 을 발생하도록 변경하라.
//•IncompatibleException 은 std::exception class 를 상속하여 만들어라.
//•main() 함수에서 IncompatibleException 을 catch 하여 다음 화면과 같이 출력하도록 변경하라.
//

#include <iostream>
#include "BitSet.h"

int main(int argc, char *argv[]) {
  BitSet b1(132), b2(131);
  b1.insert(3); b1.insert(5); b1.insert(8);
  b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
  b1.print(); b2.print();
  cout << "b1= " << b1 << endl;
  cout << "b2= " << b2 << endl;
  cout << "b1+b2= ";
  try {
    cout << b1+b2 << endl;
  } catch (IncompatibleException& e) {
    cout << "In + operation, the operands are not compatible.\n";
    cout << "The size of the first BitSet is " << b1.size() << "\n";
    cout << "The size of the second BitSet is " << b2.size() << "\n";
  }
}