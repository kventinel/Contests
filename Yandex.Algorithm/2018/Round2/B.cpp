#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  vector<int> w(m);
  for (int &i : v) {
    cin >> i;
  }
  for (int &i : w) {
    cin >> i;
  }
  ll ans = 0;
  int max_a = 0;
  int max_ac = 0;
  int first = 0;
  int last = 0;
  for (int i = 0; i < n; ++i) {
    ans += v[i];
    if (max_a < v[i]) {
      max_a = v[i];
      max_ac = 1;
      first = i;
      last = i;
    } else if (max_a == v[i]) {
      ++max_ac;
      last = i;
    }
  }
  ans += max_a * (m - 1);
  ans *= 1000000000;
  int max_b = 0;
  for (int i = 0; i < m; ++i) {
    ans += w[i];
    max_b = max(max_b, w[i]);
  }
  ans += w[0] * first;
  ans += w[m - 1] * (n - last - 1);
  ans += max_b * (n - first - (n - last - 1) - 1);
  cout << ans << endl;
  return 0;
}
