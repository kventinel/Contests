#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int buf[50 * 50 * 50 * 50];
int v[50][50];

int get_id(int l, int r, int t, int b) {
  return (((l * n + r) * n + t) * n + b);
}

bool clear_row(int ro, int l, int r) {
  for (int i = l; i <= r; ++i) {
    if (v[ro][i]) {
      return false;
    }
  }
  return true;
}

bool clear_col(int c, int t, int b) {
  for (int i = t; i <= b; ++i) {
    if (v[i][c]) {
      return false;
    }
  }
  return true;
}

int rec(int l, int r, int t, int b) {
  if (l > r) {
    return 0;
  }
  if (t > b) {
    return 0;
  }
  if (buf[get_id(l, r, t, b)] != -1) {
    return buf[get_id(l, r, t, b)];
  }
  int ans = max(r - l + 1, b - t + 1);
  for (int i = l; i <= r; ++i) {
    if (clear_col(i, t, b)) {
      ans = min(ans, rec(l, i - 1, t, b) + rec(i + 1, r, t, b));
    }
  }
  for (int i = t; i <= b; ++i) {
    if (clear_row(i, l, r)) {
      ans = min(ans, rec(l, r, t, i - 1) + rec(l, r, i + 1, b));
    }
  }
  buf[get_id(l, r, t, b)] = ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      v[i][j] = c == '#';
    }
  }
  fill(buf, buf + 50 * 50 * 50 * 50, -1);
  cout << rec(0, n - 1, 0, n - 1) << endl;
  return 0;
}
