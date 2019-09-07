#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int M = 20001;
  vector<vector<pii> > v(M);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    v[x + 10000].emplace_back(y + 10000, i + 1);
  }
  for (vector<pii> &i : v) {
    sort(i.begin(), i.end());
  }
  int best_ans = 0;
  int a, b, c, d;
  for (int i1 = 0; i1 < M; ++i1) {
    if (v[i1].size() <= 1) {
      continue;
    }
    for (int i2 = 0; i2 < M; ++i2) {
      if (v[i2].size() <= 1) {
        continue;
      }
      vector<int> y;
      for (int j1 = 0; j1 < v[i1].size(); ++j1) {
        if (lower_bound(v[i2].begin(), v[i2].end(), make_pair(v[i1][j1].first, 0))->first == v[i1][j1].first) {
          y.push_back(v[i1][j1].first);
        }
      }
      if (y.size() <= 1) {
        continue;
      }
      int sq = (i2 - i1) * (y.back() - y[0]);
      if (sq > best_ans) {
        best_ans = sq;
        a = lower_bound(v[i1].begin(), v[i1].end(), make_pair(y[0], 0))->second;
        b = lower_bound(v[i1].begin(), v[i1].end(), make_pair(y.back(), 0))->second;
        c = lower_bound(v[i2].begin(), v[i2].end(), make_pair(y[0], 0))->second;
        d = lower_bound(v[i2].begin(), v[i2].end(), make_pair(y.back(), 0))->second;
      }
    }
  }
  cout << a << " " << b << " " << c << " " << d << endl;
}
