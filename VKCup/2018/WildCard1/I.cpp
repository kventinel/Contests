#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v) {
    string s;
    cin >> s;
    i = (((s[0] - '0') * 10 + s[1] - '0') * 6 + s[3] - '0') * 10 + s[4] - '0';
  }
  sort(v.begin(), v.end());
  int k = 1439 - v[v.size() - 1] + v[0];
  for (int i = 1; i < v.size(); ++i) {
    k = max(k, v[i] - v[i - 1] - 1);
  }
  string ans = 00:00;
  ans[0] += k / 600;
  ans[1] += k % 600 / 60;
  ans[3] += k % 60 / 10;
  ans[4] += k % 10;
  cout << ans << endl;
}
