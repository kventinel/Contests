#include <iostream>
using namespace std;

pair<string, string> solve(const string &n) {
  string a, b;
  for (char c : n) {
    if (c == '4') {
      a += '3';
      b += '1';
    } else {
      a += c;
      if (!b.empty()) {
        b += '0';
      }
    }
  }
  return make_pair(a, b);
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    string n;
    cin >> n;
    auto ans = solve(n);
    cout << "Case #" << i << ": " << ans.first << " " << ans.second << endl;
  }
  return 0;
}
