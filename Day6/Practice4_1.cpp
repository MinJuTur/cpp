#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    int arr[n]; //박테리아 수 저장
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    while (k--) { //단위시간마다
      int sideSum[n] = {0}; //이웃한 박테리아 합 저장
      for (int i = 0; i < n; i++) {
        if (i == 0) sideSum[i] = arr[i+1];
        else if (i == n-1) sideSum[i] = arr[i-1];
        else sideSum[i] = arr[i-1] + arr[i+1];
      }

      for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && (sideSum[i] < 3 || sideSum[i] > 7)) arr[i]--;
        else if (arr[i] < 9 && (sideSum[i] == 4 || sideSum[i] == 5 || sideSum[i] == 6 || sideSum[i] == 7)) arr[i]++;
      }
    }

    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}
