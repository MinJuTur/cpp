#include <iostream>
using namespace std;

int main() {
   int t;
   cin >> t;

   for (int i = 0; i < t; i++) {
     int n;
     cin >> n;

     int scissor = 0;
     int rock = 0;
     int paper = 0;
     for (int j = 0; j < n; j++) {
       int temp;
       cin >> temp;

       if (temp == 1) scissor++;
       else if (temp == 2) rock++;
       else if (temp == 3) paper++;
     }

      int result = 0; //이긴 사람의 수
      if ((scissor == n || rock == n || paper == n) || (scissor > 0 && rock > 0 && paper > 0)) {
        result = 0;
      } else if (scissor == 0) result = paper;
      else if (rock == 0) result = scissor;
      else if (paper == 0) result = rock;

      cout << result << endl;
   }
}
