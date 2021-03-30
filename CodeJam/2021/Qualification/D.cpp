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
    int t, n, q;
    cin >> t >> n >> q;
    while (t--) {
        cout << "1 2 3" << endl;
        int m;
        cin >> m;
        vector<int> v;
        if (m == 1) {
            v = {2, 1, 3};
        } else if (m == 2) {
            v = {1, 2, 3};
        } else {
            v = {1, 3, 2};
        }
        for (int i = 3; i < n; ++i) {
            int l = 0;
            int r = i + 1;
            while (l + 1 < r) {
                int a = l + (r - l) / 3;
                int b = l + 2 * (r - l) / 3;
                int f = max(0, a - 1);
                int s = max(1, b - 1);
                cout << i + 1 << " " << v[f] << " " << v[s] << endl;
                cin >> m;
                if (m == i + 1) {
                    l = f + 1;
                    r = s + 1;
                } else if (m == v[s]) {
                    l = s + 1;
                } else {
                    r = f + 1;
                }
            }
            v.insert(v.begin() + l, i + 1);
        }
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                cout << " ";
            }
            cout << v[i];
        }
        cout << endl;
        cin >> m;
        if (m == -1) {
            break;
        }
    }
    return 0;
}
