//
// 방의 크기 구하기
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int m, n;
bool isValidPos(vector<vector<char>>& arr, int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m) {
        if (arr[x][y] == '.') return true; // 방문할 수 있는 위치일 때
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> m >> n; // 가로, 세로

        vector<vector<char>> arr(n, vector<char>(m)); // 입력 받기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        stack<pair<int,int>> stack; // 갈 수 있는 위치 저장
        vector<int> rooms; // 방의 크기 저장(원소의 개수: 방 개수)

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == '.') { // 갈 수 있는 위치일 때
                    stack.push({i,j});
                    int roomSize = 0;

                    while (!stack.empty()) {
                        // 현재 방문한 위치 꺼내기
                        int x = stack.top().first;
                        int y = stack.top().second;
                        stack.pop();

                        if (arr[x][y] != '.') continue;

                        arr[x][y] = '*'; // 방문 표시
                        roomSize++;
                        if (isValidPos(arr,x-1, y)) stack.push({x-1,y}); // 위
                        if (isValidPos(arr,x+1, y)) stack.push({x+1,y}); // 아래
                        if (isValidPos(arr,x, y-1)) stack.push({x,y-1}); // 왼쪽
                        if (isValidPos(arr,x, y+1)) stack.push({x,y+1}); // 오른쪽
                    }
                    rooms.push_back(roomSize);
                }
            }
        }

        cout << rooms.size() << endl; // 방 개수 출력
        sort(rooms.begin(), rooms.end(), greater<int>()); // 내림차순 정렬
        for (int i = 0; i < rooms.size(); i++) cout << rooms[i] << " ";
        cout << endl;
    }
}

