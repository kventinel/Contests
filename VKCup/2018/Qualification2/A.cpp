#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int main() {
    //freopen(input.txt, r, stdin);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int l = 0, r = k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0 && a[i] - a[i - 1] > k) {
            cout << -1 << endl;
            return 0;
        }
        if (i > 0) {
            l = min(l, a[i] - a[i - 1]);
        }
    }
    int ans = 1;
    int c = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] - c > k) {
            ++ans;
            c = a[i - 1];
        }
    }
    cout << ans << endl;
    return 0;
}
