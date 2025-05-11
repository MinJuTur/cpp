#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  cout << "write the random seed.";

   int seed;
   cin >> seed;

   srand(seed);
   for (int i = 0; i < 10; i++) {
       int data = rand()%5 + 1;
       cout << data << " ";
   }
   cout << endl;
}
