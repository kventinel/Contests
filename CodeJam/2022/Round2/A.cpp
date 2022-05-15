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

inline int new_i(int i, int d) {
    switch (d) {
        case 1:
            ++i;
            break;
        case 3:
            --i;
            break;
    }
    return i;
}

inline int new_j(int j, int d) {
    switch (d) {
        case 0:
            ++j;
            break;
        case 2:
            --j;
            break;
    }
    return j;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n, k;
        cin >> n >> k;
        if (k % 2 || k + 1 < n) {
            cout << "Case #" << test << ": IMPOSSIBLE" << endl;
            continue;
        }
        int cur = 1;
        int m = n - 1;
        int norm = 0;
        queue<pii> steps;
        while (k < n * n - cur && cur != n * n) {
            int diff = 1;
            int d = n * n - cur - k + 1;
            int c = cur - norm;
            if (c > 0 && c < m + 1 && m * 4 - 1 <= d) {
                diff = m * 4 - 1;
            } else if (c > m + 1 && c < 2 * m + 1 && m * 4 - 3 <= d) {
                diff = m * 4 - 3;
            } else if (c > 2 * m + 1 && c < 3 * m + 1 && m * 4 - 5 <= d) {
                diff = m * 4 - 5;
            } else if (c > 3 * m + 1 && c < m * 4 && m * 4 - 7 <= d) {
                diff = m * 4 - 7;
            }
            if (diff > 1) {
                steps.emplace(cur, cur + diff);
            }
            cur += diff;
            if (norm + 4 * m <= cur) {
                norm += 4 * m;
                m -= 2;
            }
            --k;
        }
        cout << "Case #" << test << ": ";
        if (k == n * n - cur) {
            cout << steps.size() << endl;
            while (!steps.empty()) {
                pii a = steps.front();
                steps.pop();
                cout << a.F << " " << a.S << endl;
            }
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
