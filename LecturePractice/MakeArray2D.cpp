//
// 입력 => ./alloc2d 2 3
//

#include <iostream>
#include <cstdlib> // atoi 함수를 위한 헤더
using namespace std;

int **makeArray2D(int *sz);
void destroyArray2D(int **arr, int *sz);

int main(int argc, char *argv[]) {
  // argc: 인자의 개수, argv: 인자의 문자열 배열
  if (argc < 3) {
    cout << "usage : ./str   1d 2d 3d ... nd \n";
    return -1;
  }

  int i;
  int dim = argc -1; // 입력받은 차원의 수

  int *size = new int[dim]; // 입력받은 차원의 크기를 저장할 배열 동적 할당

  // argv[i]부터 차원의 크기를 받아서 size 배열에 정수로 저장
  for (i = 1; i < argc; i++) size[i-1] = atoi(argv[i]);

  int **arr2d = NULL; // 2차원 배열을 가리킬 이중포인터 초기화

  // 2차원 배열 동적 생성
  arr2d = makeArray2D(size);

  // 배열에 값을 0부터 순서대로 채움
  for (int i = 0; i < size[0]; i++)
    for (int j = 0; j < size[1]; j++)
      arr2d[i][j] = i*size[1]+j;
  // 배열의 내용을 출력
  for (int i = 0; i < size[0]; i++) {
    for (int j = 0; j < size[1]; j++)
      cout << arr2d[i][j] << " ";
    cout << endl;
  }

  // 동적 할당된 메모리 해제
  destroyArray2D(arr2d, size);
  // size 배열 메모리 해제
  delete[] size;
  
  return 0;
}

// 2차원 배열을 동적으로 생성하는 함수
int **makeArray2D(int *sz) {
  int n1 = sz[0], n2 = sz[1];

  // 1차원 포인터 배열(행 포인터들) 생성
  int **arr = new int *[n1];

  // 각 행마다 열의 크기만큼 동적 할당
  for (int i = 0; i < n1; i++)
    arr[i] = new int[n2];
  return arr; // 생성한 배열의 주소 반환
}

// 동적으로 할당된 2차원 배열을 해제하는 함수
void destroyArray2D(int **arr, int *sz) {
  int n1 = sz[0];
  for (int i = 0; i < n1; i++)
     delete[] arr[i];
  delete[] arr;
}
