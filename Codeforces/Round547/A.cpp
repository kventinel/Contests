#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (m % n != 0) {
    cout << -1 << endl;
    return 0;
  }
  int a = m / n;
  int k = 0;
  while (a % 2 == 0) {
    a /= 2;
    ++k;
  }
  while (a % 3 == 0) {
    a /= 3;
    ++k;
  }
  if (a != 1) {
    k = -1;
  }
  cout << k << endl;
  return 0;
}
