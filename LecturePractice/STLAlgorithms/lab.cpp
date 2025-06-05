//
//1-1) Team 배열 t 을 내용으로 하는 vector<Team> v 을 만들고 출력한다.
//1-2) v 을 이름 순으로 정렬하고 다시 출력한다.
//1-3) v 을  wins 오름차순으로 정렬하여 출력한다.
//1-4) v 에  새로운 팀 (“Lakers”, 3) 를 맨 앞에 insert 하고 v를 다시 출력한다.
//2-1) Team 배열 t 을 내용으로 하는 set<Team> s 을 만들고 출력한다.
//이 때 정렬 순서는 wins 의  크기 순서로 한다.
//2-2) s 에  새로운 팀 (“Lakers”, 3) 를 insert 하고 s를 다시 출력한다.
//3-1) Team 배열 t 을 내용으로 하는 priority_queue<Team> p 를 만든다.
//이 때 우선 순위는 wins 가 크면 우선 순위가 높은 것이 되게 만든다.
//3-2) p 에  새로운 팀 (“Lakers”, 3) 를 push 한다.
//3-3) top(), pop() 함수를 사용하여 모든 원소를 출력한다.
//
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include "team.h"
using namespace std;

template <class T>
void print_container(const T& container, string s="") {
  cout << s << "(" << container.size() << ")";
  auto it = container.begin();
  for (; it != container.end(); it++) cout << *it << " ";
  cout << endl;
}

bool tempCmp_byName (const Team& a, const Team& b) { return a.name < b.name; };

struct TeamCmp_byVictory {
  bool operator() (const Team& a, const Team& b) const { return a.wins < b.wins; }
};

int main() {
  Team t[] = {Team("Bulls", 7), Team("Warriors", 5), Team("Spurs", 2)};

  vector<Team> v(&t[0], &t[3]);
  set<Team, TeamCmp_byVictory> s(&t[0], &t[3]);
  priority_queue<Team, vector<Team>, TeamCmp_byVictory> p(&t[0], &t[3]);

  print_container(v, "1.v= ");
  sort(v.begin(), v.end(), tempCmp_byName);
  print_container(v, "2.v= ");
  sort(v.begin(), v.end(), TeamCmp_byVictory());
  print_container(v, "3.v= ");
  v.insert(v.begin(), Team("Lakers", 3));
  print_container(v, "4.v= ");

  print_container(s, "1.s= ");
  s.insert(Team("Lakers", 3));
  print_container(s, "2.s= ");

  p.push(Team("Lakers", 3));
  cout << "priority queue : ";
  while (!p.empty()) {
    cout << p.top() << " ";
    p.pop();
  }
  cout << endl;
}