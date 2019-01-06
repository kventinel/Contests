#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <stack>

#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  vector<string> v(5);
  for (int i = 0; i < 5; ++i) {
    cin >> v[i];
  }
  for (int i = 0; i < 5; ++i) {
    if (v[i][0] == s[0] || v[i][1] == s[1]) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
