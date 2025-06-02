//
//•문자 배열 a 의 원소들을 vector<char> v, deque<char> dq, list<char> li, set<char> s, multiset<char> ss 에 저장한다.
//•map<int, char> m 과 multimap<int, char> mm 에  key 값이 i 일 때 a[i] 값을 value 로 갖도록 저장한다.
//•v, dq, li, s, ss, m, mm 의 원소들을 iterator 를 이용하여 순서대로 출력하라.  (print_container() 함수를 호출하라.)
//
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <functional>
using namespace std;

template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p){
  os << "[" << p.first << "]" << p.second;
  return os;
}

template <class T>
void print_container(const T& container, string s=""){
  cout << s << "(" << container.size() << ") ";
  auto it = container.begin();
  for (; it != container.end(); it++) cout << *it << " ";
  cout << endl;
}

int main() {
  char a[10] = {'c','a','x','a','c','b','x','c','b','y'};

  vector<char> v(&a[0], &a[10]);
  deque<char> dq(&a[0], &a[10]);
  list<char> li(&a[0], &a[10]);
  set<char> s(&a[0], &a[10]);
  multiset<char> ss(&a[0], &a[10]);
  map<int, char> m;
  multimap<int, char> mm;
  for (int i = 0; i < 10; i++) {
    m[i] = a[i];
    mm.insert(pair<int, char>(i, a[i]));
  }

  print_container(v, "v= ");
  print_container(dq, "dq= ");
  print_container(li, "li= ");
  print_container(s, "s= ");
  print_container(ss, "ss= ");
  print_container(m, "m= ");
  print_container(mm, "mm= ");
}

