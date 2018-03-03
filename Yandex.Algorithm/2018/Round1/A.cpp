#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    int n, k;
    cin >> n >> k;
    ++k;
    int ans = n / k;
    ans *= 2;
    if (n % k == 1) {
        ++ans;
    } else if (n % k > 1) {
        ans += 2;
    }
    cout << ans << endl;
}
