#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    int totalAverage = 0;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++) {
      int data;
      cin >> data;
      arr[i] = data;
      totalAverage += data;
    }
    totalAverage /= n;

    int cnt = 0;
    for (int i = 0; i <= n-k; i++) {
      int partAverage = 0;
      for (int j = i; j < i+k; j++) {
        partAverage += arr[j];
      }
      partAverage /= k;
      if (partAverage >= totalAverage) cnt++;
    }
    cout << cnt << endl;
  }
}