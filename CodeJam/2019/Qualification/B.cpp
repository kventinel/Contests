#include <iostream>
using namespace std;

string solve(string s) {
  string t = "";
  for (char c : s) {
    if (c == 'E') {
      t += 'S';
    } else {
      t += 'E';
    }
  }
  return t;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto t = solve(s);
    cout << "Case #" << i << ": " << t << endl;
  }
  return 0;
}
