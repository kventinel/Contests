#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;


int MAX = 5000;

int main() {
    ll x, y;
    cin >> x >> y;
    for (int i = 1; i <= MAX; ++i) {
        ll prob = 2 * i - 1;
        if (x * prob % y) {
            continue;
        }
        ll cnt = x * prob / y;
        vector<int> ans;
        int s = 0;
        while (cnt > 0) {
            ll a = 2;
            while ((a + 2) * (a + 1) <= cnt * 2) {
                a += 2;
            }
            ans.push_back(a);
            cnt -= a * (a - 1) / 2;
            s += a;
        }
        if (cnt > 0 || s > 2 * i) {
            continue;
        }
        cout << ans.size() + (2 * i - s) << endl;
        for (int j : ans) {
            cout << j << " ";
        }
        for (int j = s; j < 2 * i; ++j) {
            cout << 1 << " ";
        }
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
}
