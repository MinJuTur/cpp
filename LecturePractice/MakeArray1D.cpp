//
// 입력 => ./alloc1d 3
//

#include <iostream>
#include <cstdlib> // atoi 함수를 위한 헤더
using namespace std;

int *makeArray1D(int *sz);
void destroyArray1D(int *arr, int *sz);

int main(int argc, char *argv[]) {
  // argc: 인자의 개수, argv: 인자의 문자열 배열
  if (argc < 2) {
    cout << "usage : ./str   1d 2d 3d ... nd \n";
    return -1;
  }

  int i;
  int dim = argc -1; // 입력받은 차원의 수

  int *size = new int[dim]; // 입력받은 차원의 크기를 저장할 배열 동적 할당

  // argv[i]부터 차원의 크기를 받아서 size 배열에 정수로 저장
  for (i = 1; i < argc; i++) size[i-1] = atoi(argv[i]);

  int *arr1d = NULL; // 1차원 배열을 가리킬 포인터 초기화

  // 1차원 배열 동적 생성
  arr1d = makeArray1D(size);

  // 배열에 size[0] - 1까지의 값을 순서대로 채움
  for (int i = 0; i < size[0]; i++) arr1d[i] = i;
  // 배열의 내용을 출력
  for (int i = 0; i < size[0]; i++) cout << arr1d[i] << " ";
  cout << endl;

  // 동적 할당된 메모리 해제
  destroyArray1D(arr1d, size);

  // size 배열 메모리 해제
  delete[] size;

  return 0;
}

// 1차원 배열을 동적으로 생성하는 함수
int *makeArray1D(int *sz) {
  int n = sz[0]; // 1차원 배열의 크기
  int *arr = new int[n]; // 크기 n짜리 int 배열 동적 생성
  return arr; // 생성한 배열의 주소 반환
}

// 동적으로 할당된 1차원 배열을 해제하는 함수
void destroyArray1D(int *arr, int *sz) {
  delete[] arr;
}
