#include <iostream>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, I;
  cin >> n >> I;
  I *= 8;
  map<int, int> m;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++m[a];
  }
  int k = I / n;
  int z = 1;
  while (k > 0) {
    z *= 2;
    if (z >= m.size()) {
      cout << 0 << endl;
      return 0;
    }
    --k;
  }
  z = m.size() - z;
  int cur = 0;
  auto it = m.begin();
  for (int i = 0; i < z; ++i) {
    cur += it->second;
    ++it;
  }
  int best_ans = cur;
  auto end = m.end();
  for (int i = 0; i < z; ++i) {
    --it;
    --end;
    cur += end->second;
    cur -= it->second;
    best_ans = min(best_ans, cur);
  }
  cout << best_ans << endl;
  return 0;
}
