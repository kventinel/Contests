#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define F first
#define S second
#define pb push_back
#define eb emplace_back

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; ++t) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        vector<int> a;
        vector<int> b;
        vector<int> c;
        char prev = 0;
        int cnt = 0;
        int cost = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '?') {
                if (cnt == 0) {
                    a.pb(prev);
                }
                if (i + 1 == s.size()) {
                    b.pb(0);
                    c.pb(cnt + 1);
                }
            } else if (s[i] == 'C') {
                cost += prev == 'J' ? y : 0;
                if (prev == '?') {
                    b.pb(s[i]);
                    c.pb(cnt);
                }
            } else {
                cost += prev == 'C' ? x : 0;
                if (prev == '?') {
                    b.pb(s[i]);
                    c.pb(cnt);
                }
            }
            prev = s[i];
            cnt = s[i] == '?' ? cnt + 1 : 0;
        }
        // cerr << cost << endl;
        for (int i = 0; i < a.size(); ++i) {
            cerr << "test" << t << " " << a[i] << " " << b[i] << " " << c[i] << endl;
            if (x + y < 0) {
                if (a[i] == 0 && b[i] == 0) {
                    cost += ((c[i] - 1) / 2) * (x + y) + (c[i] % 2 == 0 ? min(x, y) : 0) - (c[i] % 2 ? max(max(x, y), 0) : 0);
                } else if (a[i] == 0) {
                    cost += (c[i] / 2) * (x + y) + (c[i] % 2 ? min(b[i] == 'C' ? y : x, 0) : 0) - (c[i] % 2 == 0 ? max(b[i] == 'C' ? x : y, 0) : 0);
                } else if (b[i] == 0) {
                    cost += (c[i] / 2) * (x + y) + (c[i] % 2 ? min(a[i] == 'C' ? x : y, 0) : 0) - (c[i] % 2 == 0 ? max(a[i] == 'C' ? y : x, 0) : 0);
                } else if (a[i] == b[i]) {
                    cost += ((c[i] + 1) / 2) * (x + y);
                } else {
                    cost += (c[i] / 2) * (x + y) + (a[i] == 'C' ? x : y);
                }
            } else if (x < 0) {
                if (a[i] == 0 && b[i] == 0) {
                    cost += c[i] > 1 ? x : 0;
                } else if (a[i] == 0) {
                    cost += b[i] == 'J' ? x : 0;
                } else if (b[i] == 0) {
                    cost += a[i] == 'C' ? x : 0;
                } else if (a[i] != b[i]) {
                    cost += a[i] == 'C' ? x : y;
                }
            } else if (y < 0) {
                if (a[i] == 0 && b[i] == 0) {
                    cost += c[i] > 1 ? y : 0;
                } else if (a[i] == 0) {
                    cost += b[i] == 'C' ? y : 0;
                } else if (b[i] == 0) {
                    cost += a[i] == 'J' ? y : 0;
                } else if (a[i] != b[i]) {
                    cost += a[i] == 'C' ? x : y;
                }
            } else {
                if (a[i] != b[i] && a[i] != 0 && b[i] != 0) {
                    cost += a[i] == 'C' ? x : y;
                }
            }
        }
        cout << "Case #" << t << ": " << cost << endl;
    }
    return 0;
}
