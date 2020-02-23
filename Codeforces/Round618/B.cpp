#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define F first
#define S second
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pii> v(n);
    for (auto &i : v) {
        cin >> i.F >> i.S;
    }
    if (n & 1) {
        cout << "NO\n";
        return 0;
    }
    v.pb(v[0]);
    for (int i = 0; i * 2 < n; ++i) {
        pii d1 = make_pair(v[i].F - v[i + 1].F, v[i].S - v[i + 1].S);
        int j = n / 2 + i;
        pii d2 = make_pair(v[j].F - v[j + 1].F, v[j].S - v[j + 1].S);
        if (d1.F != -d2.F || d1.S != -d2.S) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
