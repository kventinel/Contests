#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<stack<int> > v(26);
  vector<stack<int> > w(26);
  stack<int> a;
  stack<int> b;
  vector<pii> ans;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '?') {
      a.push(i);
    } else {
      v[s[i] - 'a'].push(i);
    }
    if (t[i] == '?') {
      b.push(i);
    } else {
      w[t[i] - 'a'].push(i);
    }
  }
  for (int i = 0; i < 26; ++i) {
    while (!v[i].empty() && !w[i].empty()) {
      ans.emplace_back(v[i].top(), w[i].top());
      v[i].pop();
      w[i].pop();
    }
    while (!v[i].empty() && !b.empty()) {
      ans.emplace_back(v[i].top(), b.top());
      v[i].pop();
      b.pop();
    }
    while (!w[i].empty() && !a.empty()) {
      ans.emplace_back(a.top(), w[i].top());
      a.pop();
      w[i].pop();
    }
  }
  while (!a.empty() && !b.empty()) {
    ans.emplace_back(a.top(), b.top());
    a.pop();
    b.pop();
  }
  cout << ans.size() << endl;
  for (auto &i : ans) {
    cout << i.first + 1 << " " << i.second + 1 << endl;
  }
  return 0;
}
