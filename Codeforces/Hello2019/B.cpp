#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <stack>

#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int a = (1 << 15);
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  for (int i = 0; i < a; ++i) {
    int sum = 0;
    int t = i;
    for (int j = 0; j < n; ++j) {
      if ((t & 1) == 0) {
        sum += v[j];
      } else {
        sum -= v[j];
      }
      t >>= 1;
    }
    if (sum % 360 == 0) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
