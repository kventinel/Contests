#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int ans = 0;
  int j = 0;
  while (v[j] != 0) {
    ++ans;
    ++j;
  }
  j = n - 1;
  while (v[j] != 0) {
    ++ans;
    --j;
  }
  for (int i = 1; i < n; ++i) {
    if (v[i] != 0) {
      v[i] += v[i - 1];
    }
    ans = max(ans, v[i]);
  }
  cout << ans << endl;
  return 0;
}
