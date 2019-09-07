#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v) {
    cin >> i;
  }
  int p = 1;
  while (p < n) {
    p <<= 1;
  }
  vector<ll> t(2 * p);
  vector<ll> ans(n);
  for (int i = 0; i < n; ++i) {
    int l = p;
    int r = p + v[i];
    ll sum = 0;
    while (l < r) {
      if (l & 1) {
        sum += t[l];
        ++l;
      }
      if (r & 1) {
        --r;
        sum += t[r];
      }
      l >>= 1;
      r >>= 1;
    }
    ans[i] = sum;
    l = p + v[i] - 1;
    while (l > 0) {
      t[l] += v[i];
      l >>= 1;
    }
  }
  for (ll i : ans) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
