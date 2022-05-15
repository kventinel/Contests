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

vector<int> gen_perm(int n) {
    if (n == 1) {
        return {1};
    }
    if (n == 2) {
        return {1, 2, 2, 1};
    }
    if (n == 3) {
        return {1, 2, 3, 1, 3, 2, 2, 1, 3, 2, 3, 1, 3, 1, 2, 3, 2, 1};
    }
    vector<int> res;
    for (int i = 1; i <= n; ++i) {
        auto cur = gen_perm(n - 1);
        for (int j = 0; j < cur.size(); ++j) {
            if (j % (n - 1) == 0) {
                res.pb(i);
            }
            res.pb(cur[j] >= i ? cur[j] + 1 : cur[j]);
        }
    }
    return res;
}

ll cd(pll a, pll b) {
    return (a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S);
}

vector<pii> check_perm(const vector<pll> &c, const vector<pll> &k, const vector<int> &perm, int st) {
    int last = c.size();
    vector<pii> res;
    set<int> cc;
    set<int> kk;
    bool fok = false;
    while (res.size() != c.size()) {
        int prev_size = res.size();
        for (int j = 0; j < c.size(); ++j) {
            if (cc.find(j) != cc.end()) {
                continue;
            }
            ll dist = cd(c[j], k[perm[st + j]]);
            bool ok = true;
            for (int g = 0; g < k.size(); ++g) {
                if (kk.find(g) != kk.end()) {
                    continue;
                }
                if (cd(c[j], k[g]) < dist) {
                    ok = false;
                    if (g == 0) {
                        fok = true; 
                    }
                    break;
                }
            }
            if (ok) {
                res.eb(j + 1, perm[st + j] + 1);
                cc.insert(j);
                kk.insert(perm[st + j]);
            } else if (fok) {
                break;
            }
        }
        if (fok || res.size() == prev_size) {
            break;
        }
    }
    if (res.size() != c.size()) {
        return {};
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    vector<vector<int> > perms;
    for (int test = 1; test <= tests; ++test) {
        int n;
        cin >> n;
        vector<pll> c(n);
        vector<pll> k(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> c[i].F >> c[i].S;
        }
        for (int i = 0; i <= n; ++i) {
            cin >> k[i].F >> k[i].S;
        }
        while (perms.size() < n) {
            perms.pb({});
        }
        if (perms[n - 1].size() == 0) {
            perms[n - 1] = gen_perm(n);
        }
        vector<pii> res;
        for (int i = 0; i < perms[n - 1].size(); i += n) {
            res = check_perm(c, k, perms[n - 1], i);
            if (!res.empty()) {
                break;
            }
        }
        cout << "Case #" << test << ": ";
        if (!res.empty()) {
            cout << "POSSIBLE" << endl;
            for (auto a : res) {
                cout << a.F << " " << a.S << endl;
            }
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
