#include <algorithm>
#include <iostream>
#include <vector>

#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define sort(v) sort(v.begin(), v.end())

using namespace std;
using ll = long long;
using pii = pair<ll, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
    }
    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll best_add = 0;
    int x = 0;
    for (int i = m - 1; i >= 0; --i) {
        vector<int> w;
        ll add = 0;
        int val = 1 << i;
        int cur_x = val;
        for (int j : v) {
            if ((j & val) == 0) {
                w.pb(j);
                add += val;
            }
        }
        vector<pii> curs;
        for (int j = i - 1; j >= 0; --j) {
            val = 1 << j;
            ll cur_add = 0;
            for (int z : w) {
                if (z & val) {
                    cur_add -= val;
                } else {
                    cur_add += val;
                }
            }
            curs.eb(-cur_add, val);
        }
        sort(curs);
        int tk = 1;
        for (pii j : curs) {
            if (tk == k) {
                break;
            }
            ++tk;
            if (j.F < 0) {
                add -= j.F;
                cur_x += j.S;
            }
        }
        if (best_add < add) {
            best_add = add;
            x = cur_x;
        } else if (best_add == add && cur_x < x) {
            x = cur_x;
        }
    }
    cout << x << endl;
}
