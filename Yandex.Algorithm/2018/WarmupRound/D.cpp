#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 2 << endl;
        return 0;
    }
    ll i = 2;
    ll ans = 1;
    while (i * i <= n) {
        ll mul = 0;
        while (n % i == 0) {
            n /= i;
            if (mul == 0) {
                mul = i - 1;
            } else {
                mul *= i;
            }
        }
        if (mul != 0) {
            ans *= mul;
        }
        ++i;
    }
    if (n != 1) {
        ans *= n - 1;
    }
    cout << ans << endl;
}