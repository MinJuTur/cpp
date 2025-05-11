#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;

    int arr[n];
    int totalSum = 0;
    for (int j = 0; j < n; j++) {
      int data;
      cin >> data;
      arr[j] = data;
      totalSum += data;
    }
    int totalAverage = totalSum / n;

    int cnt = 0;
    for (int j = 0; j <= n - k; j++) {
      int partSum = 0;
      for (int l = j; l < j + k; l++) {
        partSum += arr[l];
      }
      int partAverage = partSum / k;
      if (partAverage >= totalAverage) cnt++;
    }
    cout << cnt << endl;
  }
}
