#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;

    int arr[n]; // 격자판
    int changedArr[n]; // 단위시간 동안 바뀐 격자판
    for (int j = 0; j < n; j++) {
      int data;
      cin >> data;
      arr[j] = data;
      changedArr[j] = data;
    }

    for (int j = 0; j < k; j++) {
      for (int l = 0; l < n; l++) {
        int sum = 0;
        if (l == 0) sum = arr[l+1];
        else if (l == n-1) sum = arr[l-1];
        else sum = arr[l-1] + arr[l+1];

        if (sum < 3 && arr[l] > 0) changedArr[l]--;
        else if (sum > 7 && arr[l] > 0) changedArr[l]--;
        else if (sum >= 4 && sum <= 7 && arr[l] < 9) changedArr[l]++;
      }

      for (int l = 0; l < n; l++) {
        arr[l] = changedArr[l];
      }
    }

    for (int j = 0; j < n; j++) {
      cout << arr[j] << " ";
    }
    cout << endl;
  }
}
