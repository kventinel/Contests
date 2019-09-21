#include <iostream>
#include <vector>

using namespace std;

int p;
vector<int> v;

void update(int i) {
  if (i < p) {
    v[i << 1] = max(v[i], v[i << 1]);
    v[(i << 1) ^ 1] = max(v[i], v[(i << 1) ^ 1]);
    v[i] = 0;
  }
}

void set(int i, int l, int r, int j, int w) {
  update(i);
  if (l == j && r == j + 1) {
    v[i] = w;
    return;
  }
  int m = (l + r) >> 1;
  if (j < m) {
    set(i << 1, l, m, j, w);
  } else {
    set((i << 1) ^ 1, m, r, j, w);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  p = 1;
  while (p < n) {
    p <<= 1;
  }
  v.resize(p << 1);
  for (int i = 0; i < n; ++i) {
    cin >> v[p + i];
  }
  int q;
  cin >> q;
  while (q--) {
    int a;
    cin >> a;
    if (a == 1) {
      int j, w;
      cin >> j >> w;
      set(1, 0, p, j - 1, w);
    } else {
      int w;
      cin >> w;
      v[1] = max(v[1], w);
    }
  }
  for (int i = 1; i < p; ++i) {
    v[i << 1] = max(v[i], v[i << 1]);
    v[(i << 1) ^ 1] = max(v[i], v[(i << 1) ^ 1]);
  }
  for (int i = 0; i < n; ++i) {
    cout << v[p + i] << " ";
  }
  cout << endl;
  return 0;
}
