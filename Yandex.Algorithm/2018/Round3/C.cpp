#include <bits/stdc++.h>

using namespace std;

using ld = long double;
using ll = long long;

int h;

ll sol(const vector<pair<int, int>> &v) {
    ll ans = 0;
    vector<int> w(v.size());
    vector<int> z(v.size());
    for (int i = 0; i < v.size(); ++i) {
        w[i] = v[i].first - (h - 1 - v[i].second);
        z[i] = v[i].first - v[i].second;
        ans += h - 1;
        ans += h;
    }
    sort(w.begin(), w.end());
    sort(z.begin(), z.end());
    int k = 0;
    int j = 0;
    int u = 0;
    for (int i = 0; i < v.size(); ++i) {
        while (j < v.size() && w[j] < z[i] + h) {
            ++k;
            ++j;
        }
        while (u < j && z[i] >= w[u] + h) {
            ++u;
            --k;
        }
        ans -= k;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n >> h;
    vector<pair<int, int>> white;
    vector<pair<int, int>> black;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if ((a + b) % 2 == 0) {
            white.push_back(make_pair(a, b));
        } else {
            black.push_back(make_pair(a, b));
        }
    }
    cout << sol(white) + sol(black) << endl;
    return 0;
}
