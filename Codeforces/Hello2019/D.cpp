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

pll prod(pll a, pll b) {
  return {a.F * b.F % MOD, a.S * b.S % MOD};
}

pll sum(pll a, pll b) {
  return {(a.F * b.S + a.S * b.F) % MOD, a.S * b.S % MOD};
} 

void calc(pll &a, int k, int t, ll y) {
  vector<vector<pll> > v(k + 1, vector<pll> (t + 1, {0, 1}));
  v[0][t].F = 1;
  v[0][t].S = 1;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j <= t; ++j) {
      pll tt = {1, j + 1};
      tt = prod(tt, v[i][j]);
      for (int z = 0; z <= j; ++z) {
        v[i + 1][z] = sum(tt, v[i + 1][z]);
      }
    }
  }
  pll ans = {0, 1};
  pll x = {1, 1};
  for (int j = 0; j <= t; ++j) {
    v[k][j] = prod(v[k][j], x);
    x = prod(x, {y, 1});
    ans = sum(ans, v[k][j]);
  }
  a = prod(a, ans);
}

int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  int k;
  cin >> n >> k;
  pll ans = {1, 1};
  for (long long i = 2; i * i <= n; ++i) {
    int t = 0;
    while (n % i == 0) {
      n /= i;
      ++t;
    }
    if (t > 0) {
      calc(ans, k, t, i);
    }
  }
  if (n != 0) {
    calc(ans, k, 1, n);
  }
  ll p = ans.F;
  ll q = ans.S;
  while (p && q) {
    if (p > q) {
      p %= q;
    } else {
      q %= p;
    }
  }
  p += q;
  ans.F /= p;
  ans.S /= p;
  p = MOD - 3;
  q = ans.S;
  while (p > 0) {
    if (p % 2 == 0) {
      q *= q;
      q %= MOD;
      p /= 2;
    } else {
      ans.S *= q;
      ans.S %= MOD;
      --p;
    }
  }
  ans.F *= ans.S;
  ans.F %= MOD;
  cout << ans.F << endl;
  return 0;
}
