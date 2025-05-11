#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int arr[n];
        for (int j = 0; j < n; j++) {
           int temp;
           cin >> temp;
           arr[j] = temp;
        }

        int max = arr[0];
        int min = arr[0];
        for (int j = 1; j < n; j++) {
          if (arr[j] > max) max = arr[j];
          else if (arr[j] < min) min = arr[j];
        }

        cout << max << " " << min << endl;
    }
}