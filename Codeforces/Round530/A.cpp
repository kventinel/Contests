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
using pll = pair<ll, ll>;

ll MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n, -1);
  vector<int> s(n);
  vector<int> a(n);
  vector<vector<int> > w(n);
  for (int i = 1; i < n; ++i) {
    cin >> v[i];
    --v[i];
    w[v[i]].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  a[0] = s[0];
  queue<int> q;
  for (int i : w[0]) {
    q.push(i);
  }
  ll ans = a[0];
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (s[u] == -1) {
      int m = INT32_MAX;
      for (int i = 0; i < w[u].size(); ++i) {
        m = min(s[w[u][i]], m);
      }
      if (w[u].size() == 0) {
        m = s[v[u]];
      }
      s[u] = m;
    }
    a[u] = s[u] - s[v[u]];
    if (a[u] < 0) {
      cout << -1 << endl;
      return 0;
    }
    for (int i : w[u]) {
      q.push(i);
    }
    ans += a[u];
  }
  cout << ans << endl;
  return 0;
}
