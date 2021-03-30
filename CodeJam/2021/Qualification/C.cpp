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
        int n, cost;
        cin >> n >> cost;
        if (cost + 1 < n) {
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
            continue;
        }
        cost -= n - 1;
        vector<int> v{n};
        for (int i = n - 1; i > 0; --i) {
            int pos = cost;
            if (cost > n - i) {
                pos = n - i;
            }
            reverse(v.begin(), v.begin() + pos);
            v.insert(v.begin() + pos, i);
            cost -= pos;
        }
        if (cost > 0) {
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << t << ":";
            for (int i : v) {
                cout << " " << i;
            }
            cout << endl;
        }
    }
    return 0;
}
