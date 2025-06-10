#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    unsigned int m, n;
    cin >> m >> n;

    vector<int> mArr;
    int mWeight = 0;
    vector<int> nArr;
    int nWeight = 0;
    while (m > 0) {
     mArr.push_back(m % 2);
     if (m % 2 == 1) mWeight++;
     m /= 2;
    }

    while (n > 0) {
     nArr.push_back(n % 2);
     if (n % 2 == 1) nWeight++;
     n /= 2;
    }

    if (mArr.size() > nArr.size()) nArr.resize(mArr.size());
    else mArr.resize(nArr.size());

    int distance = 0;
    for (int i = 0; i < mArr.size(); i++) {
        if (mArr[i] != nArr[i]) distance++;
    }

    cout << mWeight << " " << nWeight << " " << distance << endl;
  }
}