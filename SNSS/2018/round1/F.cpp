#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;


int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k = 0;
        while (n--) {
            int a, b, c, ab, bc, ac, abc;
            cin >> a >> b >> c >> ab >> bc >> ac >> abc;
            int ans = 0;
            if (abc < 0) {
                continue;
            }
            a -= abc;
            b -= abc;
            c -= abc;
            ab -= abc;
            bc -= abc;
            ac -= abc;
            ans += abc;
            if (ab < 0) {
                continue;
            }
            a -= ab;
            b -= ab;
            ans += ab;
            if (bc < 0) {
                continue;
            }
            b -= bc;
            c -= bc;
            ans += bc;
            if (ac < 0) {
                continue;
            }
            a -= ac;
            c -= ac;
            ans += ac;
            if (a < 0) {
                continue;
            }
            ans += a;
            if (b < 0) {
                continue;
            }
            ans += b;
            if (c < 0) {
                continue;
            }
            ans += c;
            k = max(k, ans);
        }
        cout << k << endl;
    }
    return 0;
}
