#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<bool> v(3 * n);
  vector<int> matching;
  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    if (!v[--a] && !v[--b]) {
      v[a] = true;
      v[b] = true;
      matching.push_back(i);
    }
  }
  if (matching.size() >= n) {
    cout << "Matching" << endl;
    matching.resize(n);
    for (int i : matching) {
      cout << i << " ";
    }
    cout << endl;
  } else {
    cout << "IndSet" << endl;
    int i = 0;
    while (n >> 0) {
      if(!v[i]) {
        cout << i + 1 << " ";
        --n;
      }
      ++i;
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
