#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int r, s, t;
        cin >> r >> s >> t;

        vector<vector<int>> arr1(r, vector<int>(s));
        vector<vector<int>> arr2(s, vector<int>(t));

        for (int j = 0; j < r; j++) {
          for (int k = 0; k < s; k++) {
            cin >> arr1[j][k];
          }
        }

        for (int j = 0; j < s; j++) {
            for (int k = 0; k < t; k++) {
                cin >> arr2[j][k];
            }
        }

        for (int j = 0; j < r; j++) {
            for (int k = 0; k < t; k++) {
                int result = 0;
                for (int l = 0; l < s; l++) {
                  result += arr1[j][l] * arr2[l][k];
                }
                cout << result << " ";
            }
            cout << endl;
        }
    }
}
