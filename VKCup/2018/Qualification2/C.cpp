#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

set<pair<int, pair<int, int>>> q;

int main() {
    //freopen(input.txt, r, stdin);
    int g, d, f;
    cin >> g >> d >> f;
    vector<int> a(g + d + f);
    for (int i = 0; i < g + d + f; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < g + d + f; ++i) {
        int mn = a[i];
        long long res1 = 0, res2 = 0, res3 = 0;
        for (int j = 0; j < g; ++j) {
            if (a[j] <= 2 * mn && a[j] > mn) {
                ++res1;
            }
        }
        if (i < g) {
            res1 = 1;
        }
        for (int j = g; j < g + d; ++j) {
            if (a[j] <= 2 * mn && a[j] > mn) {
                ++res2;
            }
        }
        if (i < g || i >= g + d) {
            res2 = (res2 - 1) * res2 / 2;
        }
        for (int j = g + d; j < g + d + f; ++j) {
            if (a[j] <= 2 * mn && a[j] > mn) {
                ++res3;
            }
        }
        if (i >= g + d) {
            res3 = res3 * (res3 - 1) / 2;
        } else {
            res3 = res3 * (res3 - 1) * (res3 - 2) / 6;
        }
        ans += res1 * res2 * res3;
    }
    cout << ans << endl;
    return 0;
}
