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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v) {
            cin >> i;
        }
        int cost = 0;
        for (int i = 0; i < n - 1; ++i) {
            int k = i;
            for (int j = i + 1; j < n; ++j) {
                if (v[j] < v[k]) {
                    k = j;
                }
            }
            cost += (k - i + 1);
            for (int j = i; j < k; ++j) {
                int r = k - (j - i);
                if (r <= j) {
                    break;
                }
                swap(v[j], v[r]);
            }
        }
        cout << "Case #" << t << ": " << cost << endl;
    }
    return 0;
}
