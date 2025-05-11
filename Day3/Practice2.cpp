#include <iostream>
using namespace std;

int main() {
	int t;
  	cin >> t;

  	for (int i = 0; i < t; i++) {
    	int n, a, b;
    	cin >> n >> a >> b;

    	int x = 1;
    	int y = 0;
    	int go = n; //한 방향 안에서 몇 번 가는지
    	int cnt = 0; //몇 번째 수인지 세기
    	for (int j = 0; j < 2*n-1; j++) {
      		switch (j % 4) {
        		case 0: //오른쪽
        			for (int k = 0; k < go; k++) {
        				cnt++;
        				y++;
                		if (cnt >= a && cnt <= b) cout << (x-1)*n+y << " ";
     				}
                    go--;
                    break;
                case 1: //아래
                	for (int k = 0; k < go; k++) {
                		cnt++;
                		x++;
                		if (cnt >= a && cnt <= b) cout << (x-1)*n+y << " ";
     				}
                    break;
                case 2: //왼쪽
                	for (int k = 0; k < go; k++) {
                		cnt++;
                		y--;
                		if (cnt >= a && cnt <= b) cout << (x-1)*n+y << " ";
     				}
                    go--;
                    break;
                case 3: //위
                	for (int k = 0; k < go; k++) {
                		cnt++;
                		x--;
                		if (cnt >= a && cnt <= b) cout << (x-1)*n+y << " ";
     				}
                    break;
      			default:
      				break;
      		}

    	}

  		cout << "\n";
  	}
}