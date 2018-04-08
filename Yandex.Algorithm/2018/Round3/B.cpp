#include <bits/stdc++.h>

using namespace std;

using ld = long double;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int u = 0;
    int k = 0;
    ll ans = 0;
    while (n--) {
        int a;
        cin >> a;
        int b = a;
        if (a == 0 && u != 0) {
            cout << -1 << endl;
            return 0;
        }
        while (u != 0 && u < a) {
            --k;
            u *= 2;
        }
        while (a < u) {
            a *= 2;
            ++k;
        }
        k = max(k, 0);
        ans += k;
        u = b;
    }
    cout << ans << endl;
    return 0;
}
