#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int main() {
    //freopen(input.txt, r, stdin);
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> mx(n);
    long long ind = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > cur) {
            cur = a[i];
            ind = i;
        }
        if (i == 0) {
            mx[i] = a[i];
        } else {
            mx[i] = max(mx[i - 1], a[i]);
        }
    }
    long long ans = 0;
    for (int i = ind; i < n; ++i) {
        ans += cur - a[i];
    }
    --cur;
    --ind;
    while (ind > 0) {
        if (mx[ind] < cur) {
            ans += cur - a[ind];
            --ind;
            --cur;
        } else {
            long long l = 0, r = ind;
            while (l != r) {
                long long m = (l + r) / 2;
                if (mx[m] == cur) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            for (int j = l; j <= ind; ++j) {
                ans += cur - a[j];
            }
            ind = l - 1;
            --cur;
        }
    }
    cout << ans << endl;
    return 0;
}
