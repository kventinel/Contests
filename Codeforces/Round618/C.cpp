#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;

#define F first
#define S second
#define pb push_back

bool cmp(pii cur, const stack<pii> &s) {
    if (s.empty()) {
        return false;
    }
    pii se = s.top();
    return cur.F * se.S <= cur.S * se.F;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) {
        cin >> i;
    }
    stack<pii> s;
    for (int i = 0; i < n; ++i) {
        pii cur = make_pair((ll) v[i], (ll) 1);
        while (cmp(cur, s)) {
            pii se = s.top();
            cur.F += se.F;
            cur.S += se.S;
            s.pop();
        }
        s.push(cur);
    }
    stack<pii> ans;
    while (!s.empty()) {
        ans.push(s.top());
        s.pop();
    }
    cout << fixed << setprecision(10);
    while (!ans.empty()) {
        pii cur = ans.top();
        ans.pop();
        ld te = cur.F;
        te /= cur.S;
        while (cur.S) {
            --cur.S;
            cout << te << "\n";
        }
    }
    return 0;
}
