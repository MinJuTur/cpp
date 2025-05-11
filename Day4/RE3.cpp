//
// 두 구간이 차지하는 길이 구하기
// 배열 이용하기, 구간의 길이 계산 조심하기
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int arr[100] = {0}; //0~99
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        for (int j = a; j <= b; j++) {
            arr[j]++;
        }
        for (int j = c; j <= d; j++) {
            arr[j]++;
        }

        int mixed = 0;
        int total = 0;
        for (int j = 0; j < 100; j++) {
            if (arr[j] == 2) mixed++;
            if (arr[j] >= 1) total++;
        }

        if (mixed == 0) total -= 2;
        else {
            mixed--;
            total--;
        }
        cout << mixed << " " << total << endl;
    }
}