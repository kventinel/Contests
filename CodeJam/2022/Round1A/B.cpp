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

const ll MAX = 1000 * 1000 * 1000;

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, MAX);
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n = 100;
        cin >> n;
        if (n == -1) {
            break;
        }
        vector<ll> v;
        vector<ll> w;
        map<ll, int> m;
        ll val = 2;
        v.pb(1);
        m[1] = 1;
        ll s = 1;
        while (val <= MAX) {
            v.pb(val);
            m[val] = 1;
            s += val;
            val *= 2;
        }
        val = 300;
        while (v.size() + w.size() < n) {
            w.pb(val);
            s += val;
            ++val;
        }
        // for (int i = 1; i < n; ++i) {
        //     ll val = v[i - 1] * 10;
        //     if (val > MAX) {
        //         val = 1;
        //     }
        //     v[i] = val;
        //     ++m[val];
        //     s += val;
        // }
        for (int i : v) {
            cout << i << " ";
        }
        for (int i : w) {
            cout << i << " ";
        }
        cout << endl;
        cout.flush();
        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            if (val == -1) {
                s = -1;
                break;
            }
            s += val;
            w.pb(val);
        }
        if (s == -1) {
            break;
        }
        // for (int i = 0; i < n; ++i) {
        //     if (i + 1 < n) {
        //         val = dist(gen);
        //     } else if (s % 2 == 0) {
        //         val = 2;
        //     } else {
        //         val = 1;
        //     }
        //     s += val;
        //     w.pb(val);
        // }
        s /= 2;
        sort(w.rbegin(), w.rend());
        for (int i = 0; i <= n; ++i) {
            ll curs = 0;
            vector<int> res;
            for (int j = 0; j < i; ++j) {
                curs += w[j];
                res.pb(w[j]);
            }
            ll val = 2;
            while (m[val / 2] != 0) {
                if (s < curs) {
                    break;
                }
                ll diff = (s - curs) % val / (val / 2);
                if (diff == 0) {
                    val *= 2;
                } else if (m[val / 2] >= diff) {
                    for (int j = 0; j < diff; ++j) {
                        res.pb(val / 2);
                        curs += val / 2;
                    }
                } else {
                    break;
                }
            }
            // cerr << s << " vs " << curs << endl;
            if (s == curs) {
                for (int i = 0; i < res.size(); ++i) {
                    if (i != 0) {
                        cout << " ";
                    }
                    cout << res[i];
                }
                cout << endl;
                cout.flush();
                break;
            }
            if (i == n) {
                throw runtime_error("");
            }
        }
    }
    return 0;
}
