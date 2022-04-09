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

int MAX = 1000 * 1000 * 1000;

set<vector<int> > _gen(vector<int> v) {
    set<vector<int> > w;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > 0) {
            --v[i];
            auto z = _gen(v);
            ++v[i];
            for (auto a : z) {
                vector<int> b{i};
                b.insert(b.end(), a.begin(), a.end());
                w.insert(b);
            }
        }
    }
    if (w.size() == 0) {
        w.insert(vector<int>(0));
    }
    return w;
}

vector<pair<vector<int>, int> > gen(vector<int> v) {
    vector<pair<vector<int>, int> > w;
    set<vector<int> > s = _gen(v);
    for (auto it : s) {
        w.eb(it, MAX);
    }
    return w;
}

void pv(vector<int> v) {
    for (int i : v) {
        cerr << i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int e, w;
        cin >> e >> w;
        vector<vector<int> > v(e, vector<int> (w));
        for (auto &i : v) {
            for (auto &j : i) {
                cin >> j;
            }
        }
        int res = MAX;
        vector<pair<vector<int>, int> > a(1, make_pair(vector<int>(0), 0));
        for (int i = 0; i < e; ++i) {
            auto b = gen(v[i]);
            for (int k = 0; k < b.size(); ++k) {
                for (int j = 0; j < a.size(); ++j) {
                    int g = 0;
                    while (g < min(a[j].F.size(), b[k].F.size()) && a[j].F[g] == b[k].F[g]) {
                        ++g;
                    }
                    b[k].S = min(b[k].S, a[j].S + (int) a[j].F.size() + (int) b[k].F.size() - 2 * g);
                    // pv(a[j].F);
                    // cerr << " ";
                    // pv(b[k].F);
                    // cerr << " " << b[k].S << endl;
                }
                // pv(b[k].F);
                // cerr << " " << b[k].S << endl;
            }
            a = move(b);
        }
        for (int i = 0; i < a.size(); ++i) {
            res = min(res, (int) (a[i].S + a[i].F.size()));
        }
        // int res = 0;
        // stack<int> s;
        // vector<int> c(w);
        // for (int i = 0; i < e; ++i) {
        //     for (int j = 0; j < w; ++j) {
        //         while (c[j] > v[i][j]) {
        //             int z = s.top();
        //             --c[z];
        //             s.pop();
        //             ++res;
        //         }
        //     }
        //     for (int k = e - 1; k >= i; --k) {
        //         for (int j = 0; j < w; ++j) {
        //             int z = v[i][j];
        //             for (int g = i + 1; g <= k; ++g) {
        //                 z = min(z, v[g][j]);
        //             }
        //             while (z > c[j]) {
        //                 cerr << j << endl;
        //                 s.push(j);
        //                 ++res;
        //                 ++c[j];
        //             }
        //         }
        //     }
        // }
        // while (!s.empty()) {
        //     s.pop();
        //     ++res;
        // }
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}
