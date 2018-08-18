#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

vector<int> ep{1, 1, 1, 2, 3, 4, 6};

ll res(int w) {
    map<int, ll> m;
    m.emplace(w, 1);
    ll ans = 0;
    while (!m.empty()) {
        w = m.rbegin()->first;
        ll t = m.rbegin()->second;
        m.erase(--m.end());
        int k = w;
        while (k >= 2) {
            int l = w / k;
            int a = l + 1;
            int next_k = w / a;
            if (l < ep.size()) {
                ans += t * (k - next_k) *ep[l];
            } else {
                m[l] += t * (k - next_k);
            }
            k = min(next_k, k - 1);
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    for (int i = 7; i < 10000; ++i) {
        ep.push_back(res(i));
    }
    if (w < ep.size()) {
        cout << ep[w] << endl;
    } else {
        cout << res(w) << endl;
    }
    return 0;
}
