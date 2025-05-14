//
// 해밍 거리
//
#include <iostream>
using namespace std;

int main() {
 int t;
 cin >> t;

 while (t--) {
  int m, n;
  cin >> m >> n;

  // 해밍 무게
  int weight_m = 0;
  int weight_n = 0;

  int arr_m[33] = {0}; // m을 이진수로 변환해서 저장(거꾸로)
  int arr_n[33] = {0}; // n을 이진수로 변환해서 저장(거꾸로)

  int temp = m;
  int i = 0;
  while (temp > 0) {
   arr_m[i++] = temp % 2;
   if (temp % 2 == 1) weight_m++;
   temp /= 2;
  }

  temp = n;
  int j = 0;
  while (temp > 0) {
   arr_n[j++] = temp % 2;
   if (temp % 2 == 1) weight_n++;
   temp /= 2;
  }

  int maxSize = i > j ? i : j; // 최대 사이즈
  int distance = 0; // 해밍 거리
  for (int k = 0; k < maxSize; k++) {
   if (arr_m[k] != arr_n[k]) distance++;
  }

  cout << weight_m << " " << weight_n << " " << distance << endl;
 }
}