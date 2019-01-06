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

vector<string> v;
int n, m;

pair<int, vector<string>> solve(string a) {
  string b = "";
  for (char c : "ACGT") {
    if (c != a[0] && c != a[1]) {
      b += c;
    }
  }
  vector<string> d{a, b};
  vector<string> w(n);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int res1 = 0;
    int res2 = 0;
    for (int j = 0; j < m; ++j) {
      if (v[i][j] != d[i & 1][j & 1]) {
        ++res1;
      }
      if (v[i][j] != d[i & 1][(j & 1) ^ 1]) {
        ++res2;
      }
    }
    if (res1 <= res2) {
      res += res1;
      for (int j = 0; j < m; ++j) {
        w[i] += d[i & 1][j & 1];
      }
    } else {
      res += res2;
      for (int j = 0; j < m; ++j) {
        w[i] += d[i & 1][(j & 1) ^ 1];
      }
    }
  }
  return {res, w};
}

pair<int, vector<string>> solve2(string a) {
  string b = "";
  for (char c : "ACGT") {
    if (c != a[0] && c != a[1]) {
      b += c;
    }
  }
  vector<string> d{a, b};
  vector<string> w(n);
  int res = 0;
  for (int j = 0; j < m; ++j) {
    int res1 = 0;
    int res2 = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i][j] != d[j & 1][i & 1]) {
        ++res1;
      }
      if (v[i][j] != d[j & 1][(i & 1) ^ 1]) {
        ++res2;
      }
    }
    if (res1 <= res2) {
      res += res1;
      for (int i = 0; i < n; ++i) {
        w[i] += d[j & 1][i & 1];
      }
    } else {
      res += res2;
      for (int i = 0; i < n; ++i) {
        w[i] += d[j & 1][(i & 1) ^ 1];
      }
    }
  }
  return {res, w};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  string s = "ACGT";
  int best_res = 30000000;
  vector<string> w;
  for (int i = 0; i < 4; ++i) {
    for (int j = i + 1; j < 4; ++j) {
      string q = "";
      q += s[i];
      q += s[j];
      auto t = solve(q);
      if (t.F < best_res) {
        best_res = t.F;
        w = t.S;
      }
      t = solve2(q);
      if (t.F < best_res) {
        best_res = t.F;
        w = t.S;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << w[i] << endl;
  }
  return 0;
}
