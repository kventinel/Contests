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
        int n, q;
        cin >> n >> q;
        vector<pair<int, string>> v(n);
        for (auto &i : v) {
            cin >> i.S >> i.F;
            if (i.F * 2 < q) {
                for (char &c : i.S) {
                    c = c == 'F' ? 'T' : 'F';
                }
                i.F = q - i.F;
            }
        }
        sort(v.rbegin(), v.rend());
        cout << "Case #" << t << ": " << v[0].S << " " << v[0].F << "/1" << endl;
    }
    return 0;
}
