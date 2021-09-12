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
    for (int test = 1; test <= tests; ++ test) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int k = n + m - 1;
        cout << "Case #" << test << ": ";
        if (a < k || b < k) {
            cout << "Impossible" << endl;
            continue;
        }
        cout << "Possible" << endl;
        a -= k - 1;
        b -= k - 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) {
                    cout << a;
                } else if (i == 0 && j + 1 == m) {
                    cout << b;
                } else {
                    cout << 1;
                }
                if (j + 1 != m) {
                    cout << " ";
                } else {
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
