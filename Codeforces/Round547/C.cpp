#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n - 1);
  ll k = 0;
  ll sum = 0;
  for (int &i : v) {
    cin >> i;
    k += i;
    sum += k;
  }
  sum = n * (ll) (n + 1) / 2 - sum;
  if (sum % n != 0) {
    cout << -1 << endl;
    return 0;
  }
  vector<ll> ans(n);
  ans[0] = sum / n;
  if (ans[0] <= 0 || ans[0] > n) {
    cout << -1 << endl;
    return 0;
  }
  set<int> s;
  s.insert(ans[0]);
  for (int i = 1; i < n; ++i) {
    ans[i] = ans[i - 1] + v[i - 1];
    if (ans[i] <= 0 || ans[i] > n || s.find(ans[i]) != s.end()) {
      cout << -1 << endl;
      return 0;
    }
    s.insert(ans[i]);
  }
  for (ll i : ans) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
