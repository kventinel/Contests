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
#include <cassert>

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
    for (int test = 1; test <= tests; ++ test) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> v(n);
        for (auto &s : v) {
            cin >> s;
        }
        int best_res = 0;
        for (int j = 0; j < m; ++j) {
            if (v[k - 1][j] == 'X') {
                ++best_res;
            }
        }
        vector<int> up(m);
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == 'X') {
                    ++up[j];
                }
            }
        }
        for (int i = k; i < n; ++i) {
            int res = i - k + 1;
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == 'X') {
                    ++res;
                    ++up[j];
                } else if (up[j] >= k) {
                    ++res;
                }
            }
            best_res = min(best_res, res);
        }
        int res = n - k + 1;
        for (int j = 0; j < m; ++j) {
            if (up[j] >= k) {
                ++res;
            }
        }
        best_res = min(best_res, res);
        vector<int> down(m);
        for (int i = k - 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == 'X') {
                    ++down[j];
                }
            }
        }
        for (int i = k - 2; i >= 0; --i) {
            int res = k - i - 1;
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == 'X') {
                    ++res;
                    ++down[j];
                } else if (down[j] >= n - k + 1) {
                    ++res;
                }
            }
            best_res = min(best_res, res);
        }
        res = k;
        for (int j = 0; j < m; ++j) {
            if (down[j] >= n - k + 1) {
                ++res;
            }
        }
        best_res = min(best_res, res);
        cout << "Case #" << test << ": " << best_res << endl;
    }
    return 0;
}
