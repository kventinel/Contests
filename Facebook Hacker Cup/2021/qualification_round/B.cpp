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
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        map<int, int> res;
        set<pii> poses;
        for (int i = 0; i < n; ++i) {
            int xcnt = 0;
            int ocnt = 0;
            int pos = -1;
            for (int j = 0; j < n; ++j) {
                if (v[i][j] == 'X') {
                    ++xcnt;
                } else if (v[i][j] == 'O') {
                    ++ocnt;
                } else  {
                    pos = j;
                }
            }
            if (ocnt == 0) {
                ++res[n - xcnt];
                if (n - xcnt == 1) {
                    poses.emplace(i, pos);
                }
            }
            xcnt = 0;
            ocnt = 0;
            pos = -1;
            for (int j = 0; j < n; ++j) {
                if (v[j][i] == 'X') {
                    ++xcnt;
                } else if (v[j][i] == 'O') {
                    ++ocnt;
                } else {
                    pos = j;
                }
            }
            if (ocnt == 0) {
                ++res[n - xcnt];
                if (n - xcnt == 1) {
                    poses.emplace(pos, i);
                }
            }
        }
        cout << "Case #" << test << ": ";
        if (res.empty()) {
            cout << "Impossible";
        } else {
            cout << res.begin()->first << " " << (res.begin()->first == 1 ? poses.size() : res.begin()->second);
        }
        cout << endl;
    }
    return 0;
}
