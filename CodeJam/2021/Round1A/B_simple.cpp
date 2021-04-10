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

vector<pll> v;
ll res;

void calc(int i, __int64_t sum, __int64_t prod) {
    if (i < v.size()) {
        if (v[i].S > 0) {
            sum -= v[i].F;
            prod *= v[i].F;
            if (sum == prod) {
                res = sum;
            } else if (prod < sum && res < sum) {
                --v[i].S;
                calc(i, sum, prod);
                ++v[i].S;
            }
            sum += v[i].F;
            prod /= v[i].F;
        }
        calc(i + 1, sum, prod);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; ++t) {
        int m;
        cin >> m;
        v.clear();
        v.resize(m);
        res = 0;
        __int64_t sum = 0;
        for (pll &i : v) {
            cin >> i.F >> i.S;
            sum += i.F * i.S;
        }
        sort(v.begin(), v.end());
        calc(0, sum, 1);
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}
