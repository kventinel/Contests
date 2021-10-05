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
        int n, m;
        cin >> n >> m;
        multiset<pii> v;
        int res = 0;
        for (int i = 0; i < m; ++i) {
            int a;
            cin >> a;
            v.emplace(a, 0);
        }
        for (int j = 0; j < n; ++j) {
            multiset<pii> w;
            vector<int> unchanged;
            for (int i = 0; i < m; ++i) {
                int a;
                cin >> a;
                auto it = v.lower_bound(make_pair(a + 1, 0));
                if (it != v.begin()) {
                    --it;
                }
                if (it->first == a) {
                    w.insert(*it);
                    v.erase(it);
                } else {
                    unchanged.pb(a);
                }
            }
            auto it = v.begin();
            int i = 0;
            while (it != v.end()) {
                if (it->second != 0) {
                    ++res;
                }
                auto a = *it;
                a.first = unchanged[i];
                ++a.second;
                w.insert(a);
                ++it;
                ++i;
            }
            v = w;
        }
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}
