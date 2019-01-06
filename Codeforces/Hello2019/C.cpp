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
  int n;
  cin >> n;
  multiset<int> left;
  multiset<int> right;
  int zero = 0;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int val = 0;
    int low = 0;
    for (char a : s) {
      if (a == '(') {
        ++val;
      } else {
        --val;
        if (val < low) {
          low = val;
        }
      }
    }
    if (low >= 0 && val > 0) {
      left.insert(val);
    } else if (low >= 0) {
      ++zero;
    } else if (low == val) {
      right.insert(-val);
    }
  }
  int k = 0;
  for (int a : left) {
    if (right.find(a) != right.end()) {
      right.erase(right.find(a));
      ++k;
    }
  }
  cout << k + zero / 2 << endl;
  return 0;
