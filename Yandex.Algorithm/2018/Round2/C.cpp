#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, ds, cs, da, ca;
  cin >> n >> m >> ds >> cs >> da >> ca;
  vector<int> v(n);
  for (int &i : v) {
    cin >> i;
  }
  sort(v.begin(), v.end());
  int best_res = 0;
  while (m >= 0) {
    int count = 0;
    int temp_health = v[0];
    int i = 0;
    int temp_m = m;
    while (i < n && temp_m >= 0) {
      if (temp_health <= 0) {
        ++i;
        temp_health = v[i];
        ++count;
      } else {
        temp_health -= ds;
        temp_m -= cs;
      }
    }
    best_res = max(best_res, count);
    m -= ca;
    for (int i = 0; i < n; ++i) {
      v[i] -= da;
    }
  }
  cout << best_res << endl;
  return 0;
}
