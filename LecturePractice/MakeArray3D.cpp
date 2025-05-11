//
// 입력 => ./alloc3d 3 4 2
//

#include <iostream>
#include <cstdlib> // atoi 함수를 위한 헤더
using namespace std;

int ***makeArray3D(int *sz);
void destroyArray3D(int ***arr, int *sz);

int main(int argc, char *argv[]) {
  // argc: 인자의 개수, argv: 인자의 문자열 배열
  if (argc < 4) {
    cout << "usage : ./str   1d 2d 3d ... nd \n";
    return -1;
  }

  int i;
  int dim = argc -1; // 입력받은 차원의 수

  int *size = new int[dim]; // 입력받은 차원의 크기를 저장할 배열 동적 할당

  // argv[i]부터 차원의 크기를 받아서 size 배열에 정수로 저장
  for (i = 1; i < argc; i++) size[i-1] = atoi(argv[i]);

  int ***arr3d = NULL; // 3차원 배열을 가리킬 삼중포인터 초기화

  // 3차원 배열 동적 생성
  arr3d = makeArray3D(size);

  // 배열에 값을 0부터 순서대로 채움
  int num = 1;
  for (i = 0; i < size[0]; i++) {
    for (int j = 0; j < size[1]; j++) {
      for (int k = 0; k < size[2]; k++) {
        arr3d[i][j][k] = (i*size[1]+j)*size[2]+k;
      }
    }
  }
  // 배열의 내용을 출력
  for (i = 0; i < size[0]; i++) {
    cout << "i : " << i << endl;
    for (int j = 0; j < size[1]; j++) {
      for (int k = 0; k < size[2]; k++) {
        cout << arr3d[i][j][k] << ' ';
      }
      cout << endl;
    }
    cout << endl;
  }

  // 동적 할당된 메모리 해제
  destroyArray3D(arr3d, size);
  // size 배열 메모리 해제
  delete[] size;
  
  return 0;
}

// 3차원 배열을 동적으로 생성하는 함수
int ***makeArray3D(int *sz) {
  int n1 = sz[0], n2 = sz[1], n3 = sz[2];
  int ***arr = new int **[n1];
  for (int i = 0; i < n1; i++) {
    arr[i] = new int *[n2];
  }
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n2; j++)
     arr[i][j] = new int [n3];
  }
  return arr;
}

// 동적으로 할당된 3차원 배열을 해제하는 함수
void destroyArray3D(int ***arr, int *sz) {
  int n1 = sz[0], n2 = sz[1];
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n2; j++) {
      delete[] arr[i][j];
    }
  }

  for (int i = 0; i < n1; i++) {
    delete[] arr[i];
  }

  delete[] arr;
}
