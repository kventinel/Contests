#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int main() {
    //freopen(input.txt, r, stdin);
    ios_base::sync_with_stdio(false);
    int n, u;
    cin >> n >> u;
    vector<int> a(n);
    vector<int> c(n);
    bool Ans = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i >= 2) {
            Ans |= (a[i] - a[i - 2] <= u);
        }
    }
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        c[i] = a[i + 1] - a[i];
    }
    long double ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        long double res = 1;
        int l = i + 1, r = n - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a[m] - a[i] <= u) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        if (a[r] - a[i] <= u) {
            l = r;
        }
        if (l >= i + 2) {
            res = res - c[i] / 1. / (a[l] - a[i]);
            ans = max(ans, res);
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
