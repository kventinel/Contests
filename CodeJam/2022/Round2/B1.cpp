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
        int r;
        cin >> r;
        int m = r * 2 + 1;
        vector<vector<int> > v(m, vector<int>(m));
        for (int j = 0; j <= r; ++j) {
            for (int i = r - j; i <= r + j; ++i) {
                int x = r - i;
                int y = round(sqrt(j * j - x * x));
                v[i][r - y] = 1;
                v[i][r + y] = 1;
                v[r - y][i] = 1;
                v[r + y][i] = 1;
            }
        }
        int k = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = r - i;
                int y = r - j;
                if (round(sqrt(x * x + y * y)) <= r && v[i][j] == 0) {
                    ++k;
                }
            }
        }
        cout << "Case #" << test << ": " << k << endl;
    }
    return 0;
}
